D		[0-9]
NZ		[1-9]
L		[a-zA-Z_]
A		[a-zA-Z_0-9]
E		([Ee][+-]?{D}+)

%{
#include "TESTsymbol.tab.h"
#include <string.h>
#include "symb.h"
char buf[100]; //A buffer to copy strings into. STRING MAX SIZE IS 100
char *s;
%}
%x STRSTATE
%%
(?i:scribe)		{return SCRIBE;}
(?i:exit)		{return EXIT_COMMAND;}
(?i:cast)		{return CAST;}
(?i:smite)		{return SMITE;}	
(?i:inquire)		{return INQUIRE;}
(?i:alternate)		{return ALTERNATE;}
(?i:research)		{return RESEARCH;}
(?i:era)		{return ERA;}		
\"			{BEGIN STRSTATE; s = buf;}
<STRSTATE>\\n		{*s++ = '\n';}
<STRSTATE>\\t		{*s++ = '\t';}
<STRSTATE>\\\"		{*s++ = '\"';}
<STRSTATE>\"		{*s = 0;
			BEGIN 0;
			yylval.name = malloc(strlen(buf) + 1);
			strcpy(yylval.name,buf);
			yylval.type = 2; //string
			yylval.value.strval = buf; return STRING;}
<STRSTATE>\n		{ECHO; yyerror("Invalid string"); exit(1);}
<STRSTATE>.		{*s++ = *yytext;}
{D}+			{yylval.name = malloc(strlen(yytext) + 1);
			strcpy(yylval.name,yytext); //name is the int
			yylval.type = 0; //Set type to integer
			yylval.value.intval = atoi(yytext); return INTEGER;}
{D}*"."{D}+{E}?		{yylval.name = malloc(strlen(yytext) + 1);
			strcpy(yylval.name,yytext);
			yylval.type = 1; //Set type to float
			yylval.value.doubleval = atof(yytext); return REAL;}
{L}{A}*			{yylval.name = malloc(strlen(yytext) + 1);
			strcpy(yylval.name,yytext); return IDENTIFIER;}
">"			{return '>';}
"<"			{return '<';}
"=="			{return EQ_OP;}
"<="			{return LE_OP;}
">="			{return GE_OP;}
"!="			{return NE_OP;}
[,-=+*/\n()^]		{return yytext[0];}
"%"			{return '%';}
[ \t]			;
.			{ECHO; yyerror("Unexpected character");}

%%
int yywrap(void) {return 1;}
