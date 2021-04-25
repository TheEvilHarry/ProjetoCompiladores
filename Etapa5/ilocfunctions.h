#include <stdio.h>
#include "symbolTable.h"

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
Code *generateAttributionCode(Node *attr, Node *exp);
Code *generateIfCode(Node *expr, Node *trueExpr, Node *falseExpr);
Code *generateLabelCode(char *label);
Code *generateTrueConditionalJump(char *label);
Code *createCBRCode(Node *expr, char *r1, char *l1, char *l2, Node *trueExpr);
Code *generateI2ICode(char *r1, char *r2);
Code *generateTernaryCode(Node *expr, Node *exprTrue, Node *exprFalse);
Code *generateWhileCode(Node *expr, Node *commands);
Code *generateForCode(Node *start, Node *expr, Node *incr, Node *commands);
Code *generateBinaryExpression(Operation op, Node *child1, Node *child2, char *dest);
Code *generateUnaryExpression(Operation operation, Code *op);

// Code *handleGlobalVariable(SymbolTableStack *stack, Type type, Node *nodo1, Node *nodo2); // Update RBSS offset
// Code *addFunctionArgument(SymbolTableStack *stack, TokenData *identifier, Node *type, int isConst);
/*
 - Create label
 - 
*/
Code *handleFunctionDeclaration(SymbolTableStack *stack, TokenData *identifier, Node *node, int staticFunc, Node *functionParameters, Node *parent);
Code *addFunctionCode(Node *header, Node *block, Code *code, SymbolTableStack *stack, char *returnLabel);
Code *handleFunctionCall(SymbolTableStack *stack, Node *node, Node *args);
Code *handleFunctionReturn(SymbolTableStack *stack, Node *node, Type functionType, char *returnLabel, Node *parent);

// se o nodo é um token literal ou identificador cria o código correspondente
// node_t *ILOC_cria_nodo(char *label, TOKEN_INFO *valor_lexico, char *type, STACK *stack);

// int ILOC_verify_var_declaration(STACK *stack, TOKEN_INFO *ident, int type, node_t *var_value, int is_static, int is_const);

// void ILOC_add_local_var(node_t *parent, node_t *ident, node_t *initializer, char *type, STACK *stack);

// void ILOC_add_rbss_offset(CODE_BLOCK *iloc_code);

// CODE_BLOCK *ILOC_cmd_attrib(char *ident, STACK *stack, node_t *exp);

// CODE_BLOCK *ILOC_cmd_if(STACK *stack, node_t *exp, node_t *true_cmds, node_t *false_cmds);

// CODE_BLOCK *ILOC_cmd_while(STACK *stack, node_t *exp, node_t *do_cmds);

// CODE_BLOCK *ILOC_cmd_for(STACK *stack, node_t *initial, node_t *condition, node_t *increment, node_t *cmds);

// CODE_BLOCK *ILOC_cmd_ternary_op(STACK *stack, node_t *exp, node_t *cmd_true, node_t *cmd_false);

// int ILOC_binary_exp(node_t *parent, node_t *left, node_t *right);

// int ILOC_unary_exp(node_t *parent, node_t *child);

// void print_iloc(CODE_BLOCK *iloc_code);

// void free_iloc(CODE_BLOCK *iloc_code);

char *generate(Node *node);