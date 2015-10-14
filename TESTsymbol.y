%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "symb.h"
#define YYDEBUG 1
#define YYPRINT(file, type, value) yyprint (file, type, value)
#define MAX_STRING 1028 //the max length of a string
#define YY_BUF_SIZE 32768 //Buffer size for yy buffers 

/*Variable declarations******************************/
extern char *yytext;
extern FILE *yyin;
symrec *sym_table; //The symbol table is stored in symb.h
symrec *param_sym_table; //Second symbol table for function parameters only
typedef struct yy_buffer_state * YY_BUFFER_STATE; //input buffers
char *buff; //A buffer for string addition and mallocs
static int sym_scope[128]; //This keeps tracks of the # of symbols within each scope
static int scope_lvl = 0; //The current scope level, 0 is base
static int no_exec_flag = 0; //0 means execute normally, 1 means skip within ifstatement
static char TMP_BUFF[MAX_STRING];
static int f_flag = 0; //A flag telling the program to look for function symbols first
static char *f_name; //The global name of the current function

/*Function prototypes********************************/
void yyerror(const char *);
static void init_table();
static void yyprint(FILE *file, int type, struct symrec value);
static int free_sym_table(int scope);
static int free_sym_table_param();
static char *make_sym_name(char *func, char *param);
%}


%define api.value.type {struct symrec}
%define parse.lac full
%define parse.error verbose

%start line
%token SCRIBE EXIT_COMMAND CAST SMITE
%token EQ_OP NE_OP LE_OP GE_OP
%token INTEGER REAL STRING ERA
%token IDENTIFIER INQUIRE ALTERNATE RESEARCH
%left '+' '-'
%left '*' '/'
%right '^' '=' SCRIBE

%%

line    : statement   {;}
        | line statement   {;}
        | function_declaration {;}
        | line function_declaration {;}
    	| function_call {;}
    	| line function_call {;}
    	;
    
    
/*constant production assigns INTEGER and REAL value constants(literals) to a symbol within the sym_table.
 * The names are simply string representations of their value 
 */
constant  : INTEGER     {
             symrec* tmp;
             if ( (tmp = getsym($1.name)) == 0){
               //Symbol does not exist in table yet
               putsym($1.name, 0, 0);
               upsym($1.name, (void *)&$1.value.intval, NULL);
               tmp = getsym($1.name);
               $$.name = tmp->name; $$.type = tmp->type;
               $$.qual = tmp->qual; $$.value = tmp->value;
               free($1.name); //free alloc'd string
             }else{
               $$.name = tmp->name; $$.type = tmp->type;
               $$.qual = tmp->qual; $$.value = tmp->value;
               free($1.name);
             } }
          | REAL        {
             symrec* tmp;
             if ( (tmp = getsym($1.name)) == 0){
               //Symbol does not exist in table yet
               putsym($1.name, 1, 0);
               upsym($1.name, (void *)&$1.value.doubleval, NULL);
               tmp = getsym($1.name);
               $$.name = tmp->name; $$.type = tmp->type;
               $$.qual = tmp->qual; $$.value = tmp->value;
               free($1.name); //free alloc'd string
             }else{
               $$.name = tmp->name; $$.type = tmp->type;
               $$.qual = tmp->qual; $$.value = tmp->value;
               free($1.name); //yylval still has malloc
             } }
    	  ;
    
/* string production is much the same as constant, except the data is a string literal
*/
string    : STRING      {symrec* tmp;
             if ( (tmp = getsym($1.name)) == 0){
               //Symbol does not exist in table yet
               putsym($1.name, 2, 0);
               upsym($1.name, (void *)$1.value.strval, NULL);
               tmp = getsym($1.name);
               $$.name = tmp->name; $$.type = tmp->type;
               $$.qual = tmp->qual; $$.value = tmp->value;
               free($1.name); //free alloc'd string
             }else{
               //Symbol does, in fact, exist
               $$.name = tmp->name; $$.type = tmp->type;
               $$.qual = tmp->qual; $$.value = tmp->value;
               free($1.name); //Still need to free yylval
             } }
    ;
    
/* primary_expression retrieves the value from a constant, string or an IDENTIFIER.
 * For IDENTIFIER, it will return that symbol in the table OR it will simply pass
 * the struct up
*/
primary_expression
    : IDENTIFIER      {symrec* tmp;
            if( (tmp = getsym($1.name)) == 0){
              //Symbol not yet in the table
              buff = malloc(strlen($1.name) + 1);
              strcpy(buff, $1.name);
              $$.name = buff; // Pass var name up
              free($1.name); //Free yylval
            }else{
             $$.type = tmp->type; $$.qual = tmp->qual;
             $$.value = tmp->value;
             free($1.name);
             } }
    | constant      {$$ = $1;}
    | string      {$$ = $1;}
    ;
    
multiplicative_expression
    : primary_expression
    | multiplicative_expression '*' primary_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 1; $$.value.doubleval =
        $1.value.doubleval * $3.value.doubleval;
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 1; $$.value.doubleval = 
        $1.value.intval * $3.value.doubleval;
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 1; $$.value.doubleval =
        $1.value.doubleval * $3.value.intval;
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        $1.value.intval * $3.value.intval;
        }
       //At least one arg is a string
       }else{ 
         printf("Cannot multiply using strings\n");
         YYERROR;
       }
      }
    | multiplicative_expression '/' primary_expression
    {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 1; $$.value.doubleval =
        $1.value.doubleval / $3.value.doubleval;
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 1; $$.value.doubleval = 
        $1.value.intval / $3.value.doubleval;
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 1; $$.value.doubleval =
        $1.value.doubleval / $3.value.intval;
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        $1.value.intval / $3.value.intval;
        }
       //At least one arg is a string
       }else{ 
         printf("Cannot subract using strings\n");
         YYERROR;
       }
    
    }
    | multiplicative_expression '%' primary_expression
    {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        	printf("Cannot modulus floats\n");
        	YYERROR;
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        	printf("Cannot modulus floats\n");
        	YYERROR;
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        	printf("Cannot modulus floats\n");
        	YYERROR;
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        $1.value.intval % $3.value.intval;
        }
       //At least one arg is a string
       }else{ 
         printf("Cannot modulus using strings\n");
         YYERROR;
       }
    
    }
    ;
    
additive_expression
    : multiplicative_expression
    | additive_expression '+' multiplicative_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 1; $$.value.doubleval =
        $1.value.doubleval + $3.value.doubleval;
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 1; $$.value.doubleval = 
        $1.value.intval + $3.value.doubleval;
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 1; $$.value.doubleval =
        $1.value.doubleval + $3.value.intval;
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        $1.value.intval + $3.value.intval;
        }
       //At least one arg is a string
       }else if($1.type == 2 && $3.type == 2){
         //strings
         buff = malloc(strlen($1.value.strval) + strlen($3.value.strval)+ 1);
         strcat(buff,$1.value.strval); strcat(buff,$3.value.strval);
         $$.type = 2; $$.value.strval = buff;
       }else if($1.type == 0 && $3.type == 2){
         //append an int to the beginning of a string
         buff = malloc(sizeof($1.value.intval) + strlen($3.value.strval)+ 1);
         sprintf(buff+strlen(buff),"%d",$1.value.intval); 
         strcat(buff,$3.value.strval); 
         $$.type = 2; $$.value.strval = buff;
       }else if($1.type == 1 && $3.type == 2){
         //append a float to the beginning of a string
         buff = malloc(sizeof($1.value.doubleval) + strlen($3.value.strval)+ 1);
         sprintf(buff+strlen(buff),"%g",$1.value.doubleval); 
         strcat(buff,$3.value.strval); 
         $$.type = 2; $$.value.strval = buff;
       }else if($1.type == 2 && $3.type == 0){
         //append int to end of string
         buff = malloc(strlen($1.value.strval) + sizeof($3.value.intval)+ 1);
         strcat(buff,$1.value.strval); 
         sprintf(buff+strlen(buff),"%d",$3.value.intval);  
         $$.type = 2; $$.value.strval = buff;
       }else if($1.type ==2 && $3.type == 1){
         //append a float to end of string
         buff = malloc(strlen($1.value.strval) + sizeof($3.value.doubleval)+ 1);
         strcat(buff,$1.value.strval); 
         sprintf(buff+strlen(buff),"%g",$3.value.doubleval);  
         $$.type = 2; $$.value.strval = buff;
       }
       else{ 
         printf("Mismatched type; cannot add\n");
         YYERROR;
       }
      }
    | additive_expression '-' multiplicative_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 1; $$.value.doubleval =
        $1.value.doubleval - $3.value.doubleval;
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 1; $$.value.doubleval = 
        $1.value.intval - $3.value.doubleval;
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 1; $$.value.doubleval =
        $1.value.doubleval - $3.value.intval;
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        $1.value.intval - $3.value.intval;
        }
       //At least one arg is a string
       }else{ 
         printf("Cannot subract using strings\n");
         YYERROR;
       }
      }
      
    ;
    
relational_expression
    : additive_expression
    | relational_expression '>' additive_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval > $3.value.doubleval);
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 0; $$.value.intval = 
        ($1.value.intval > $3.value.doubleval);
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval > $3.value.intval);
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        ($1.value.intval > $3.value.intval);
        }
      }else if($1.type == $3.type){//strcmp
         $$.type = 0; $$.value.intval = 
         (1 == strcmp($1.value.strval,$3.value.strval));
         //1 means $1 > $3, true here
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
    | relational_expression '<' additive_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval < $3.value.doubleval);
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 0; $$.value.intval = 
        ($1.value.intval < $3.value.doubleval);
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval < $3.value.intval);
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        ($1.value.intval < $3.value.intval);
        }
      }else if($1.type == $3.type){//strcmp
         $$.type = 0; $$.value.intval = 
         (-1 == strcmp($1.value.strval,$3.value.strval));
         //-1 means $1 < $3, true here
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
    | relational_expression LE_OP additive_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval <= $3.value.doubleval);
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 0; $$.value.intval = 
        ($1.value.intval <= $3.value.doubleval);
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval <= $3.value.intval);
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        ($1.value.intval <= $3.value.intval);
        }
      }else if($1.type == $3.type){//strcmp
         $$.type = 0; $$.value.intval = 
         (-1 != strcmp($1.value.strval,$3.value.strval));
         //-1 means $3 < $1, not true here
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
    | relational_expression GE_OP additive_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval >= $3.value.doubleval);
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 0; $$.value.intval = 
        ($1.value.intval >= $3.value.doubleval);
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval >= $3.value.intval);
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        ($1.value.intval >= $3.value.intval);
        }
      }else if($1.type == $3.type){//strcmp
         $$.type = 0; $$.value.intval = 
         (1 != strcmp($1.value.strval,$3.value.strval));
         //1 means $3 > $1, not true here
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
    ;
    
/* equality_expression works as one would expect boolean equalities to work. 
 * It can compare numbers (floats and integers don't matter), and it can compare strings. 
 * It can NOT compare characters to ints yet.
 */
equality_expression
    : relational_expression
    | equality_expression EQ_OP relational_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval == $3.value.doubleval);
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 0; $$.value.intval = 
        ($1.value.intval == $3.value.doubleval);
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval == $3.value.intval);
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        ($1.value.intval == $3.value.intval);
        }
      }else if($1.type == $3.type){//strcmp
         $$.type = 0; $$.value.intval = 
         (0 == strcmp($1.value.strval,$3.value.strval));
         //Equal; strmp = 0 means they are equal
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
    | equality_expression NE_OP relational_expression
      {if( $1.type < 2 && $3.type < 2 ){
      //Both are numbers
        if($1.type == 1 && $3.type == 1){
        //floats
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval != $3.value.doubleval);
        }else if($1.type == 0 && $3.type == 1){
        //one int one float
        $$.type = 0; $$.value.intval = 
        ($1.value.intval != $3.value.doubleval);
        }else if($1.type == 1 && $3.type == 0){
        //one float one int
        $$.type = 0; $$.value.intval =
        ($1.value.doubleval != $3.value.intval);
        }else{
        //ints
        $$.type = 0; $$.value.intval = 
        ($1.value.intval != $3.value.intval);
        }
      }else if($1.type == $3.type){//strcmp
         $$.type = 0; $$.value.intval = 
         (0 != strcmp($1.value.strval,$3.value.strval));
         //Not Equals; strmp = 0 means they are equal
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
    ;
/*assignment_expression either reduces downward or assigns the value in $3 to the 
IDENTIFIER in $1. Since the name in $1 is what defines the value, the string was 
malloc'd in flex. It must be freed in the C code to prevent memory leaks, as it 
is no longer needed   */    
assignment_expression
    : equality_expression {;}
    | IDENTIFIER '=' assignment_expression  
      {symrec *tmp;
       if($3.type == 0){//integer
         tmp = putsym($1.name, 0, 1); //add to sym_t
         upsym($1.name, (void *)&$3.value.intval, NULL); //update val
         free($1.name); //yylval no longer needed, free 
         $$ = *tmp;
       }else if($3.type == 1){//float
         tmp = putsym($1.name, 1, 1);
         upsym($1.name, (void *)&$3.value.doubleval, NULL);
         free($1.name); 
         $$ = *tmp;
       }else{ //string
         tmp = putsym($1.name, 2, 1);
         upsym($1.name, (void *)$3.value.strval, NULL);
         free($1.name);
         $$ = *tmp;
       }
      }
    ;
    

    
expression  : assignment_expression       {;}
	    | SCRIBE assignment_expression
	    	{if($2.type == 0){//integer
        	   printf("%d\n",$2.value.intval);
       		 }else if($2.type == 1){//float
         	   printf("%g\n",$2.value.doubleval);
       		 }else{ //string
         	   printf("%s\n",$2.value.strval);
       		 }
	    	}
   	    | EXIT_COMMAND          	  {YYACCEPT;}
   	    ;
    
expression_statement  : '\n'
      		      | expression '\n'
     		      ;
  

selection_statement : ifs true false    
			{no_exec_flag = 0;
			free_sym_table(1);
			scope_lvl -= 1;}
     		    | ifs true      
			{no_exec_flag = 0;
			free_sym_table(1);
			scope_lvl -= 1;}
      		    ;
      
ifs   : INQUIRE '(' assignment_expression ')' '\n'{if(!$3.value.intval) no_exec_flag = 1;
              scope_lvl += 1;
              /*Set flag and inc scope*/}
      | INQUIRE '(' assignment_expression ')' {if(!$3.value.intval) no_exec_flag = 1;
              scope_lvl += 1; }
    ;

true    
	: CAST
		{
	      	char *ifName;
	        char *ifText;
	        int symReturn;
	        symrec *ifS;
	        //Create the symbol text
	        while( (symReturn = yylex() ) != SMITE){ //Consume SMITE token
	          //While reading the if block, copy into string
	          if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	            //STRINGs are stored in a separate buffer
	            if(symReturn == STRING){
	              strcat(TMP_BUFF, "\"");
	              strcat(TMP_BUFF,yylval.value.strval);
	              strcat(TMP_BUFF, "\" ");
	            }else{
	              strcat(TMP_BUFF, yytext);
	              strcat(TMP_BUFF, " ");
	            }
	            
	          }else{
	            //TMP_BUFF buffer overflow, error
	            printf("TMP BUFF overflowed\n");
	            YYERROR;
	          }
	        }
	        //Here, SMITE is in the yytext buffer
	        /*if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	          strcat(TMP_BUFF, yytext);
	          strcat(TMP_BUFF, " ");
	        }else{
	          //TMP_BUFF buffer overflow, error
	          printf("TMP BUFF overflowed\n");
	          YYERROR;
	        }*/
	        
	        ifText = malloc(strlen(TMP_BUFF) + 1);
	        strcpy(ifText, TMP_BUFF); //put text into new string
	        memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
	        ifName = make_sym_name("\0", "if");
	        
	        ifS = putsym(ifName, 2, 2);
	        upsym(ifName, (void *)ifText, NULL); //put and update symbol
	        
	        //Here, I would redirect the input of yyparse/flex to the string in if
	        //if the if statement is true
	        if(no_exec_flag){
	          no_exec_flag = 0;
	        }else{
	        //Switch input to string
	          YY_BUFFER_STATE ys = yy_scan_string(ifText);
	          yyparse();
	          yy_delete_buffer(ys);
	        
	        //Switch back to stdin
	          YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
	          yy_switch_to_buffer(ys2); 
	          
	          no_exec_flag = 1; //so alternate doesn't execute 
	        }
	        
	        } 
	        
	 | {
	      	char *ifName;
	        char *ifText;
	        int symReturn;
	        symrec *ifS;
	        //Create the symbol text
	        
	        //Here, get the lookahead token in yytext
	        if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	          strcat(TMP_BUFF, yytext);
	          strcat(TMP_BUFF, " ");
	        }else{
	          //TMP_BUFF buffer overflow, error
	          printf("TMP BUFF overflowed\n");
	          YYERROR;
	        }
	        
	        while( (symReturn = yylex() ) != '\n'){ //Consume \n token
	          //While reading the if block, copy into string
	          if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	            //STRINGs are stored in a separate buffer
	            if(symReturn == STRING){
	              strcat(TMP_BUFF, "\"");
	              strcat(TMP_BUFF,yylval.value.strval);
	              strcat(TMP_BUFF, "\" ");
	            }else{
	              strcat(TMP_BUFF, yytext);
	              strcat(TMP_BUFF, " ");
	            }
	            
	          }else{
	            //TMP_BUFF buffer overflow, error
	            printf("TMP BUFF overflowed\n");
	            YYERROR;
	          }
	        }
	        //Here, \n is in the yytext buffer
	        if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	          strcat(TMP_BUFF, yytext);
	        }else{
	          //TMP_BUFF buffer overflow, error
	          printf("TMP BUFF overflowed\n");
	          YYERROR;
	        }
	        
	        ifText = malloc(strlen(TMP_BUFF) + 1);
	        strcpy(ifText, TMP_BUFF); //put text into new string
	        memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
	        ifName = make_sym_name("\0", "if");
	        
	        ifS = putsym(ifName, 2, 2);
	        upsym(ifName, (void *)ifText, NULL); //put and update symbol
	        
	        //Here, I would redirect the input of yyparse/flex to the string in if
	        //if the if statement is true
	        if(no_exec_flag){
	          no_exec_flag = 0;
	        }else{
	        //Switch input to string
	          YY_BUFFER_STATE ys = yy_scan_string(ifText);
	          yyparse();
	          yy_delete_buffer(ys);
	        
	        //Switch back to stdin
	          YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
	          yy_switch_to_buffer(ys2); 
	          
	          no_exec_flag = 1; //so alternate doesn't execute 
	        }
	        
	        } 
      
    ;
    
false   : ALTERNATE CAST
    {
       char *ifName;
       char *ifText;
       int symReturn;
       symrec *ifS;
       //Create the symbol text
       while( (symReturn = yylex() ) != SMITE){
       //While reading the if block, copy into string
         if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
           if(symReturn == STRING){
	     strcat(TMP_BUFF, "\"");
	     strcat(TMP_BUFF,yylval.value.strval);
	     strcat(TMP_BUFF, "\" ");
	   }else{
	     strcat(TMP_BUFF, yytext);
	     strcat(TMP_BUFF, " ");
	   }
         }else{
           //TMP_BUFF buffer overflow, error
           printf("TMP BUFF overflowed\n");
           YYERROR;
         }
       }
       //Here, SMITE is in the yytext buffer
       /*if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
         strcat(TMP_BUFF, yytext);
         strcat(TMP_BUFF, " ");
       }else{
       //TMP_BUFF buffer overflow, error
         printf("TMP BUFF overflowed\n");
         YYERROR;
       }*/
       
       //Put the text within the if statement into a new symbol
       ifText = malloc(strlen(TMP_BUFF) + 1);
       strcpy(ifText, TMP_BUFF); //put text into new string
       memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
       ifName = make_sym_name("\0", "else");
       ifS = putsym(ifName, 2, 2);
       upsym(ifName, (void *)ifText, NULL); //put and update symbol
       
       //Here, I would redirect the input of yyparse/flex to the string in if
       //if the ELSE statement is true
       if(no_exec_flag){
         no_exec_flag = 0;
       }else{
         YY_BUFFER_STATE ys = yy_scan_string(ifText);
         yyparse();
         yy_delete_buffer(ys);
       
       //Switch back to stdin
         YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
         yy_switch_to_buffer(ys2); 
         
       }
       
       } 
    ;
    
loop_statement
	: ERA '(' assignment_expression ')' loop_block
		{/*Increment scope
		  *While(loop_be.intval)
		  *While this is true, execute text stored in loop_block */
		  scope_lvl += 1; //Increment scope into loop
		  while($3.value.intval){
		  printf("$3 val: %d\n", $3.value.intval);
		     //Here, I would redirect the input of yyparse/flex to the string in if
      		 //if the ELSE statement is true
      		 
       	 	   YY_BUFFER_STATE ys = yy_scan_string($5.value.strval);
      		   yyparse();
        	   yy_delete_buffer(ys);
       
      		 //Switch back to stdin
       		  YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
        	  yy_switch_to_buffer(ys2); 
		  }  
		}
	;
	
loop_block
	: CAST
	{/*Store block in $$*/
	char *ifText;
       symrec *ifS;
       //Create the loop text
       while(yylex() != SMITE){
       //While reading the if block, copy into string
         if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
           strcat(TMP_BUFF, yytext);
           strcat(TMP_BUFF, " ");
         }else{
           //TMP_BUFF buffer overflow, error
           printf("TMP BUFF overflowed\n");
           YYERROR;
         }
       }
      
       //Put the text within the if statement into $$
       ifText = malloc(strlen(TMP_BUFF) + 1);
       strcpy(ifText, TMP_BUFF); //put text into new string
       memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
       $$.value.strval = ifText; //Pass loop text up
       }
	;		
    
compound_statement
    : CAST SMITE {;}
    | CAST block_item_list SMITE {;}
    ;
    
block_item_list
    : statement
    | block_item_list statement
    ;
      
statement : expression_statement
    | selection_statement
    | loop_statement
    | compound_statement
    ;
    
function_call
	: IDENTIFIER '(' param_list ')'
		{//param_list is in ptable
		 //Need to assign func.p symbols in normal table the values of
		 //the param_list symbols
		   //while param_sym_table != tail
		     //symrec *tmp = psymtable
		     //symrec *fSym = getsym($1.name)
		     //upsym(func.p1, tmp.value, tmp.params)
		     //get next, move pointers
		     //Check for errors
		 free($3.name); //Don't need the concat'd list of param names here    
		 symrec *ptr;
		 //printf("##fname in f_call: %s\n", $1.name);
		 symrec *fSymb = getsym($1.name); //Find the function symbol
		 free($1.name); //Use fSymb name now
		 int i = 0; //interate through function parameters
		 for(ptr = param_sym_table; strcmp(ptr->name,"tail") != 0; ptr = (symrec *)ptr->next){		 //Count # of parameters
		   i++;}
		 i--; //# of params will always be 1 more than actual
		 
		 for(ptr = param_sym_table; strcmp(ptr->name,"tail") != 0; ptr = (symrec *)ptr->next, i--){
		   if(ptr->type == 0){
		     putsym( *((*fSymb).params+i), 0, 1);
		     upsym( *((*fSymb).params+i), (void *)&(*ptr).value.intval, NULL);
		   }else if(ptr->type == 1){
		     putsym( *((*fSymb).params+i), 1, 1);
		     upsym( *((*fSymb).params+i), (void *)&(*ptr).value.doubleval, NULL);
		   }else{
		     putsym( *((*fSymb).params+i), 2, 1);
		     upsym( *((*fSymb).params+i), (void *)(*ptr).value.strval, NULL);
		   }
		 }
		 
		 //the func.p symbols will have values (free paramsymtable?)
		 free_sym_table_param();
		 //Global flag to look for function symbols first
		 f_flag = 1; 
		 f_name = fSymb->name;
		 //Read the function symbol's block, incr scope
		 scope_lvl += 1;
		 YY_BUFFER_STATE ys = yy_scan_string(fSymb->value.strval);
		 yyparse();
		 yy_delete_buffer(ys);
		 
		 //read back from stdin
		 free_sym_table(1); //delete function's stack frame
		 scope_lvl -= 1;
		 f_flag = 0;
		 f_name = NULL;
		 YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
		 yy_switch_to_buffer(ys2);
		
		}
	;
    
function_declaration
	: func_head func_body
		{symrec *tmp = getsym($1.name);
		 //Put function body and parameter names into function symbol
		 upsym($1.name, $2.value.strval, tmp->params);
		 //printf("f_declar name: %s\n, text: %s\n, param1: %s\n",tmp->name,
		 //						tmp->value.strval,
		 //						*(*tmp).params);
		 free($1.name); //Free values no longer in use
		 free_sym_table_param(); //param_list adds to table, declaration
		 //DOESNOT USE THESE VALUES, so free
		}
	;
	
func_head
	: RESEARCH IDENTIFIER '(' param_list ')' '\n'
		{char *token;
		 char *pName;
		 char **pNames = malloc(sizeof(char*) * 10);
		 int i = 0;
		 if( (token = strtok($4.name, ",")) != NULL){
		   //Create func.param symbol in table
		   pName = make_sym_name($2.name, token);
		   
		   //putsym(pName, 0, 1); //Name, Type(arbitrary), Qual(var)
		   *pNames = pName;
		 }else{
		   printf("func_head strtok returned as NULL first\n");
		   
		 }
		 while( (token = strtok(NULL, ",")) != NULL){
		   i++; 
		   
		   pName = make_sym_name($2.name, token);
		   //printf("%s\n",pName);
		   //putsym(pName, 0, 1);
		   *(pNames+i) = pName; //Add to list of params
		   
		 }
		 
		 putsym($2.name, 2, 2); //name, char*, function
		 upsym($2.name, NULL, pNames); //Put param list in function symbol
		 $$.name = $2.name; //Pass function name up
		  /*1. Create symbol w/ name IDENTIFIER and param_list
		    2. Create param symbols with func.param name scheme
		    3. $$ = function symbol*/}
	;
	
func_body
	: CAST
		{char *funcText;
		int symReturn;
    	   	//Read the function text
       		while( (symReturn = yylex() ) != SMITE){
         	  //While reading the function block, copy into string
         	  if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
           	    if(symReturn == STRING){
	              strcat(TMP_BUFF, "\"");
	              strcat(TMP_BUFF,yylval.value.strval);
	              strcat(TMP_BUFF, "\" ");
	            }else{
	              strcat(TMP_BUFF, yytext);
	              strcat(TMP_BUFF, " ");
	            }
         	  }else{
           	    //TMP_BUFF buffer overflow, error
           	    printf("TMP BUFF overflowed in func_body\n");
           	    YYERROR;
         	  }
      		}
       		/*//Here, SMITE is in the yytext buffer
       		if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
         	  strcat(TMP_BUFF, yytext);
         	  strcat(TMP_BUFF, " ");
       		}else{
         	  //TMP_BUFF buffer overflow, error
         	  printf("TMP BUFF overflowed in func_body\n");
         	  YYERROR;
       		}*/
       
       		funcText = malloc(strlen(TMP_BUFF) + 1);
       		strcpy(funcText, TMP_BUFF); //put text into new string
       		memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
       		$$.value.strval = funcText; //Pass text up
       		}
	;

/*parameter places the parameter symbol structs in
 a separate list that will later be referenced by the
 function call productions */
parameter
	: primary_expression
		{symrec *tmp;
       		if($1.type == 0){//integer
       		  tmp = putsym_param($1.name, 0, 1); //add to sym_t
         	  upsym_param($1.name, (void *)&$1.value.intval, NULL); //update val
       		}else if($1.type == 1){//float
        	  tmp = putsym_param($1.name, 1, 1);
        	  upsym_param($1.name, (void *)&$1.value.doubleval, NULL);
       		}else{ //string
        	  tmp = putsym_param($1.name, 2, 1);
       		  upsym_param($1.name, (void *)$1.value.strval, NULL);
      		}
      		
      		$$ = $1; //Pass the symbol up after putting in symtablep
		}
	;

/*param_list concatenates all the parameter NAMES into a single string after
 each is placed within the sym_table_param. Frees names afterward */
param_list
	: parameter
	| param_list ',' parameter
		{//Concat the parameter names into one string to pass up
		 buff = malloc(strlen($1.name) + 1 + strlen($3.name) + 1);
		 strcat(buff, $1.name);
		 strcat(buff,",");
		 strcat(buff, $3.name);
		 $$.name = buff;
		 }
	;
  
    
%%

int main(void)
{
  //yydebug = 1;
  int result;
  init_table();
  result = yyparse();
  free_sym_table(0); //free the symbol table!
  return result;
}

void init_table()
{
  putsym("tail", 0, 0); //Add first node to symbol table
  putsym_param("tail", 0, 0); //And to param symbol table
}

/*
*free_sym_table frees the symbols within the indicated scope
* A value of 0 means all scopes (called at end of program)
* Any other value means the current scope, the integer scope_lvl
*/
int free_sym_table(int scope)
{

  if(!scope){ //All scopes
    symrec *ptr = sym_table;
    symrec *next = (symrec *)sym_table->next;
    while( strcmp(ptr->name, "tail") != 0){ //while not tail
    
      //printf("##Freeing %s in symbol table\n",ptr->name);
      if(ptr->type == 2){free(ptr->value.strval);}
      if(ptr->qual == 2){free(ptr->params);} //free function parameters
      free(ptr->name);
      free(ptr);
      ptr = next;
      next = (symrec *)ptr->next;
      //printf("##Next symbol: %s\n",ptr->name);
      
    }
    //Free the tail
    free(ptr->name);
    free(ptr);

    return 0;
  }else{ //Free the variables for only THIS scope # = sym_scope[scope_lvl];
    symrec *ptr = sym_table;
    symrec *next = (symrec *)sym_table->next;
    //Loop once for each symbol in scope, decrementing # of symbols as it goes
    for(;sym_scope[scope_lvl] > 0; sym_scope[scope_lvl]--){
    
      //printf("##Freeing %s from scope %d\n",ptr->name,scope_lvl);
      if(ptr->type == 2){free(ptr->value.strval);}
      if(ptr->qual == 2){free(ptr->params);} //free function parameters
      free(ptr->name);
      free(ptr);
      ptr = next;
      next = (symrec *)ptr->next;

    }
    sym_table = ptr;
    return 0;
  }
}


int free_sym_table_param()
{
  
    symrec *ptr = param_sym_table;
    symrec *next = (symrec *)param_sym_table->next;
    while( strcmp(ptr->name, "tail") != 0){ //while not tail
      //printf("##freeing %s in p_sym_t\n",ptr->name);
      if(ptr->type == 2){free(ptr->value.strval);}
      free(ptr->name);
      free(ptr);
      ptr = next;
      next = (symrec *)ptr->next;
      //printf("##next symbol in p_sym_t: %s\n",ptr->name);
    }
    param_sym_table = ptr;
    //Don't free the tail
    return 0;
  
}

/*
*  symrec *putsym places a symbol at the front of the symbol chain and returns it
* type 0: integer, type 1: double, type 2: char*
* qual 0: constant, qual 1: var, qual 2: function/block
*/
symrec *putsym(char const *sym_name, int sym_type, int sym_qual)
{
  symrec *ptr = malloc(sizeof *ptr);
  ptr->name = malloc(strlen(sym_name) + 1);
  strcpy(ptr->name,sym_name);
  ptr->type = sym_type;
  ptr->qual = sym_qual;
  ptr->value.intval = 0;
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  sym_scope[scope_lvl] += 1;
  //printf("##Added %s to symbol table in scope %d\n",ptr->name, scope_lvl);
  return ptr;
}

/*putsym_param functions the same as putsym, except it only works
 with the parameter symbol table and it does not increment the symbol count */
symrec *putsym_param(char const *sym_name, int sym_type, int sym_qual)
{
  symrec *ptr = malloc(sizeof *ptr);
  ptr->name = malloc(strlen(sym_name) + 1);
  strcpy(ptr->name,sym_name);
  ptr->type = sym_type;
  ptr->qual = sym_qual;
  ptr->value.intval = 0;
  ptr->next = (struct symrec *)param_sym_table;
  param_sym_table = ptr;
  //printf("##Added %s to param symbol table\n",ptr->name);
  return ptr;
}

/*
*  Updates a symbol in the table to add its value
*  For functions/blocks, no malloc necessary as that block text has already been
* allocated
*/
symrec *upsym(char const *sym_name, void *value, char **parameters)
{
  symrec *ptr;
  for(ptr = sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next){
    if(strcmp(ptr->name, sym_name) == 0){ //symbol found
      if(ptr->qual == 0 || ptr->qual == 1){
        if(ptr->type == 0){ //integer
          ptr->value.intval = *(int *)value;
         // printf("##Added value %d to int %s in symbol table\n",ptr->value.intval,ptr->name);
        }else if(ptr->type == 1){ //float
          ptr->value.doubleval = *(double *)value;
          //printf("##Added value %g to double %s in symbol table\n",ptr->value.doubleval,ptr->name);
        }else if(ptr->type == 2){ //string
          ptr->value.strval = malloc(strlen( (char*)value )+1);
          strcpy(ptr->value.strval, (char*)value);
          //printf("##Added value \"%s\" to string %s in symbol table\n",ptr->value.strval,ptr->name);
        }
      }else{ //function or block
        ptr->value.strval = (char *)value;
        ptr->params = parameters; //List of function parameters, if there are any
        //printf("##Added value \"%s\" to block %s in symbol table\n",ptr->value.strval,ptr->name);
      }
      break;
    }
  }
  return ptr;
}

/*Updates a symbol within the parameter symbol table */
symrec *upsym_param(char const *sym_name, void *value, char **parameters)
{
  symrec *ptr;
  for(ptr = param_sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next){
    if(strcmp(ptr->name, sym_name) == 0){
      if(ptr->qual == 0 || ptr->qual == 1){
        if(ptr->type == 0){ //integer
          ptr->value.intval = *(int *)value;
          //printf("##Added value %d to int %s in param symbol table\n",ptr->value.intval,ptr->name);
        }else if(ptr->type == 1){ //float
          ptr->value.doubleval = *(double *)value;
          //printf("##Added value %g to double %s in param symbol table\n",ptr->value.doubleval,ptr->name);
        }else if(ptr->type == 2){ //string
          ptr->value.strval = malloc(strlen( (char*)value )+1);
          strcpy(ptr->value.strval, (char*)value);
          //printf("##Added value \"%s\" to string %s in param symbol table\n",ptr->value.strval,ptr->name);
        }
      }else{ //function or block
        ptr->value.strval = (char *)value;
        ptr->params = parameters; //List of function parameters, if there are any
        //printf("##Added value \"%s\" to block %s in symbol table\n",ptr->value.strval,ptr->name);
      }
      break;
    }
  }
  return ptr;
}

/*
*  symrec *getsym scans through the symbol chain to find the named symbol
*  if not found, return 0, or return a ptr to that symbol
*  If the f_flag is on, it searches for the function parameter with
*  that name first
*/
symrec *getsym(char const *sym_name)
{
  //If function flag is on, search for func parameter value first
  symrec *ptr;
  if(f_flag){
    //Make fname function
    strcat(TMP_BUFF, f_name); 
    strcat(TMP_BUFF, ".");
    strcat(TMP_BUFF, sym_name);
    //printf("file param name: %s\n",TMP_BUFF);
    char *sName = malloc(strlen(TMP_BUFF) + 1);
    //Copy into new string
    strcpy(sName, TMP_BUFF);
    //Clear buffer
    memset(TMP_BUFF, '\0', strlen(TMP_BUFF));
    for(ptr = sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next){
      if(strcmp(ptr->name, sName) == 0){
        free(sName); //free alloc'd string
        return ptr;
      }
    }
    free(sName); //Free if not returned
  }
  //If not found or if flag not on, search for normal
  
  for(ptr = sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next){
    if(strcmp(ptr->name, sym_name) == 0){
      return ptr;
    }
  }
  return 0;
  
}

/*
* make_sym_name makes a symbol name to put into table based on the two parameters
* char *func will tell whether this is a function parameter name or not
* char *param tells the name of said parameter, or if is the if OR else part of
* one of those statements
*/
static char *make_sym_name(char *func, char *param)
{
  char *ret;
  if(strlen(func) == 0){
    //if-else name
    sprintf(TMP_BUFF, "%d.%s",scope_lvl,param); //scope.if, scope.else
    ret = malloc(strlen(TMP_BUFF) + 1);
    strcpy(ret, TMP_BUFF);
    memset(TMP_BUFF, '\0', strlen(TMP_BUFF));
    return ret;
  }else{
    strcat(TMP_BUFF,func); strcat(TMP_BUFF,".");
    strcat(TMP_BUFF,param); //Make a function parameter name: func.p
    ret = malloc(strlen(TMP_BUFF) + 1);
    strcpy(ret, TMP_BUFF);
    memset(TMP_BUFF,'\0',strlen(TMP_BUFF));
    return ret;
  }
}

static void yyprint(FILE *file, int type, struct symrec value)
{
  fprintf(file, "yylval: name:%s, type:%d, qual:%d", value.name,value.type,value.qual);
}

void yyerror(const char *s) {fprintf(stderr,"%s\n",s);}
