#include <stdio.h>
#include "ast.h"

#define MAXLABELSIZE 15
#define MAXREGISTERSIZE 15
#define RBSS "rbss" //register for global variables
#define RFP "rfp"   //register for local variables]
#define RSP "rsp"   //register for stack
#define RPC "rpc"   //register for program counter

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
Code *getFirstCode(Code *code);
int setOffset(char *symbol, int *scope);

Code *createCode(Operation op, char *pointer, char *arg1, char *arg2, char *arg3, char *dest1, char *dest2, char *label);
Code *generateEmptyCode(char *local);
Code *joinCodes(Code *code1, Code *code2);

Code *generateInitialInstructions();
Code *generateAttributionCode(TokenData *identifier, Node *exp);
Code *generateIfCode(Node *expr, Node *trueExpr, Node *falseExpr);
Code *generateLabelCode(char *label);
Code *generateTrueConditionalJump(char *label);
Code *createCBRCode(Node *expr, char *r1, char *l1, char *l2, char *followingLabel, Node *trueExpr);
Code *generateI2ICode(char *r1, char *r2);
Code *generateTernaryCode(Node *expr, Node *exprTrue, Node *exprFalse);
Code *generateWhileCode(Node *expr, Node *commands);
Code *generateForCode(Node *start, Node *expr, Node *incr, Node *commands);
Code *generateBinaryExpression(char *binaryOperator, Node *parent, Node *child1, Node *child2);
Code *generateUnaryExpression(Node *expression);
Code *generateHaltCommand();
Code *generateFunctionCode(Node *header, char *identifier, Node *commands);
Code *generateMainFunctionCode(Node *header, char *identifier, Code *code, Node *commands, char *labelReturn);
Code *generateRegularFunctionCode(Node *header, char *identifier, Code *code, Node *commands, char *labelReturn);
Code *generateJump(char *reg);
Code *generateLocalVarCode(Node *identifier, Node *init, int initialized);
Code *generateReturnCode(Node *child);
Code *generateLoadVariableCode(Node *variableNode);
Code *generateFunctionCallCode(char *functionName, Node *params);

char *generateILOCFromCode(Code *code);
char *getOperationName(Operation operation);
int getNumberOfInstructions(Code *code);

typedef struct node_list_t
{
  Node *node;
  struct node_list_t *previous;
  struct node_list_t *next;
} NodeList;

NodeList *getGlobalNodeList();
Code *getGlobalCodeList();
NodeList *createNodeList(Node *node);
void exportCodeFromNodeList(NodeList *node);
NodeList *addToGlobalNodeList(Node *node);

void exportCodeList(Code *code);

Code *addToGlobalCodeList(Code *code);

void updateCurrentFunction(char *function);
char *getCurrentFunction();