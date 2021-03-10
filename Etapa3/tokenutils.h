#include <stdio.h>


typedef enum lex_val_lit_type{
    LIT_INT,
    LIT_FLOAT,
    LIT_BOOL,
    LIT_CHAR,
    LIT_STRING,
    NOT_LITERAL

} LiteralType

typedef enum lex_val_token_type{
    IDENTIFIER_TOKEN,
    LITERAL_TOKEN,
    SP_CHAR_TOKEN,
    COMPOSITE_OP
} Type

struct t_lexical_value {
    int line;
    Type type;
    LiteralType lit_type;
    union {
        int val_int;
        float val_float;
        char val_char;
        char* val_string;
    } value;
}