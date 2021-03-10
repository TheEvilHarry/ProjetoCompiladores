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
    COMPOSITE_OPERATOR_TOKEN
} Token;

typedef struct t_token_data
{
    int line;
    Token type;
    Literal literal;
    union
    {
        int valueInt;
        float valueFloat;
        int valueBoolean;
        char valueChar;
        char *valueString;
    } value;
} TokenData;

TokenData *createNonLiteralToken(int line, Token type, char *value);

TokenData *createIntegerLiteralToken(int line, int value);

TokenData *createFloatLiteralToken(int line, float value);

TokenData *createBooleanLiteralToken(int line, int value);

TokenData *createCharLiteralToken(int line, char value);

TokenData *createStringLiteralToken(int line, char *value);

void freeToken(TokenData *data);