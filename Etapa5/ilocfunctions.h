#include <stdio.h>
#include "ast.h"


#define MAXLABELSIZE 15
#define MAXREGISTERSIZE 15
#define RBSS "rbss" //register for global variables
#define RFP "rfp"   //register for local variables]
#define RSP "rsp"   //register for stack

typedef enum
{
  OPERATION_TYPE_ADD,
  OPERATION_TYPE_SUB,
  OPERATION_TYPE_MULT,
  OPERATION_TYPE_DIV,
  OPERATION_TYPE_LESS_THAN,
  OPERATION_TYPE_GREATER_THAN,
  OPERATION_TYPE_LESS_EQUAL,
  OPERATION_TYPE_GREATER_EQUAL,
  OPERATION_TYPE_VAR_ACCESS,
  OPERATION_TYPE_VECTOR_ACCESS,
  OPERATION_TYPE_FUNCTION_DECLARATION,
  OPERATION_TYPE_FUNCTION_CALL,
  OPERATION_TYPE_OR,
  OPERATION_TYPE_AND,
  OPERATION_TYPE_NOT,
  OPERATION_TYPE_NEGATIVE,
  OPERATION_TYPE_ATTRIBUTION,
  OPERATION_TYPE_ATTRIBUTION_VECTOR,
  OPERATION_TYPE_RETURN,
  OPERATION_TYPE_IF,
  OPERATION_TYPE_IF_ELSE,
  OPERATION_TYPE_TERNARY,
  OPERATION_TYPE_WHILE,
  OPERATION_TYPE_FOR,
  OPERATION_TYPE_NOP
} OperationType;

char *generateLabelName();
char *generateRegisterName();
int setOffset(char *symbol, int *scope);

Code *createCode(Operation op, char *local, char *arg1, char *arg2, char *arg3, char *dest1, char *dest2);
Code *generateEmptyCode(char *local);
Code *joinCodes(Code *code1, Code *code2);

Code *generateInitialInstructions();
Code *generateAttributionCode( TokenData *identifier, Node *exp);
Code *generateIfCode(Node *expr, Node *trueExpr, Node *falseExpr);
Code *generateLabelCode(char *label);
Code *generateTrueConditionalJump(char *label);
Code *createCBRCode(Node *expr, char *r1, char *l1, char *l2, char *followingLabel, Node *trueExpr);
Code *generateI2ICode(char *r1, char *r2);
Code *generateTernaryCode(Node *expr, Node *exprTrue, Node *exprFalse);
Code *generateWhileCode(Node *expr, Node *commands);
Code *generateForCode(Node *start, Node *expr, Node *incr, Node *commands);
Code *generateBinaryExpression(char *binaryOperator, Node* parent, Node *child1, Node *child2, char *dest);
Code *generateUnaryExpression(Operation operation, Code *op);
Code *generateHaltCommand();
Code *generateMainFunctionCode(Node *header, char *identifier, Code *code, Node *commands, char *labelReturn);
Code *generateRegularFunctionCode(Node *header, char *identifier, Code *code, Node *commands, char *labelReturn);
Code *generateJump(char *reg);

Code *handleFunctionDeclaration(SymbolTableStack *stack, TokenData *identifier, Node *node, int staticFunc, Node *functionParameters, Node *parent);
Code *addFunctionCode(Node *header, Node *block, Code *code, SymbolTableStack *stack, char *returnLabel);
Code *handleFunctionCall(SymbolTableStack *stack, Node *node, Node *args);
Code *handleFunctionReturn(SymbolTableStack *stack, Node *node, Type functionType, char *returnLabel, Node *parent);

char *generate(Node *node);