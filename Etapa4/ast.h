#include "tokenutils.h"

#define MAX_CHILDREN 4

typedef enum
{
  TYPE_UNDEFINED = 0,
  TYPE_INTEGER,
  TYPE_FLOAT,
  TYPE_STRING,
  TYPE_BOOL,
  TYPE_CHAR
} Type;

typedef struct t_ast_node
{
  TokenData *data;
  struct t_ast_node *children[MAX_CHILDREN];
  struct t_ast_node *next;
  int numberOfChildren;
  Type type;
} Node;

Node *createNode(TokenData *data, Type type);

Node *createCustomLabelNode(char *label, int line, Type type);

Node *addChild(Node *node, Node *child);

Node *addNext(Node *node, Node *next);

void exportAST(Node *node);

void freeAST(Node *node);

void exporta(void *arvore);

void libera(void *arvore);