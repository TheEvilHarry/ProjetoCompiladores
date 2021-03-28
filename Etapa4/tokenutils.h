#define MAX_LABEL_SIZE 100

typedef enum
{
    TYPE_UNDEFINED = 0,
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_CHAR
} Type;

typedef enum lexicalValueLiteralType
{
    LIT_INTEGER,
    LIT_FLOAT,
    LIT_BOOLEAN,
    LIT_CHAR,
    LIT_STRING,
    NOT_LITERAL
} Literal;

typedef enum lexicalValueTokenType
{
    IDENTIFIER_TOKEN,
    LITERAL_TOKEN,
    SPECIAL_CHAR_TOKEN,
    COMPOSITE_OPERATOR_TOKEN,
    SPECIAL_TYPE
} Token;

typedef union lexicalValue
{
    int valueInt;
    float valueFloat;
    int valueBoolean;
    char valueChar;
    char valueString[MAX_LABEL_SIZE];
} LexicalValue;

typedef struct t_token_data
{
    int line;
    Token type;
    Literal literal;

    char label[MAX_LABEL_SIZE];
    LexicalValue value;

} TokenData;

TokenData *createNonLiteralToken(int line, Token type, char *value);

TokenData *createIntegerLiteralToken(int line, char *value);

TokenData *createFloatLiteralToken(int line, char *value);

TokenData *createBooleanLiteralToken(int line, char *value);

TokenData *createCharLiteralToken(int line, char *value);

TokenData *createStringLiteralToken(int line, char *value);

void freeToken(TokenData *data);