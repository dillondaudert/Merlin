//data type for links in chain of symbols
struct symrec
{
  char *name; //Name of symbole
  int type; //int, float, char*
  int qual; //literal, var, funct
  char **params; //Parameter name list for functions
  union
  {
    int intval; //if integer
    double doubleval; //if double
    char *strval; //if char*
  } value;
  struct symrec *next; //link to next
};
typedef struct symrec symrec;

extern symrec *sym_table;

symrec *putsym(char const *name, int type, int qual);
symrec *getsym(char const *name);
symrec *upsym(char const *name, void *value, char **params);
symrec *putsym_param(char const *name, int type, int qual);
symrec *upsym_param(char const *name, void *value, char **params);
