#include <stdio.h>
#include "symbolTable.h"

#define MAXLABELSIZE 15
#define MAXREGISTERSIZE 15
#define RBSS "rbss" //register for global variables
#define RFP "rfp"   //register for local variables

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
int setsOffset(char *symbol, int *scope);

Code *createCode(Operation op, char *local, char *arg1, char *arg2, char *arg3, char *dest1, char *dest2);

Code *generateInitialInstructions();

char *getsDestForLOADAI();
Code *generateLabelCode(char *label);
Code *createCBRCode(Node *expr, char *r1, char *l1, char *l2, Node *trueExpr);
Code *generatesIfCode(Node *expr, Node *trueExpr, Node *falseExpr);
Code *generateLabelCode(char *label);
Code *generateTrueConditionalJump(char *l1);

char *generate(Node *node);