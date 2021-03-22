#include "ast.h"


typedef enum{
    NATURE_literal    ,
    NATURE_variable    ,
    NATURE_vector    ,
    NATURE_function

} Nature;

typedef enum{
    TYPE_INTEGER ,
    TYPE_FLOAT   ,
    TYPE_STRING  ,
    TYPE_BOOL    ,
    TYPE_CHAR    ,
    TYPE_UNDEFINED
} Type


typedef struct symbol_table_entry {
    char *key;
    int line;
    Nature nature;
    Type type;
    int size;
    struct symbol_table_entry *args;

    struct elem_table *next_elem;
} Symbol;


Symbol* createSymbol(char *key, int line, Nature nature, Type type, int size,);