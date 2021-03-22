#include "tokenutils.h"

#define MAX_CHILDREN 4

typedef struct t_ast_node
{
  TokenData *data;
  struct t_ast_node *children[MAX_CHILDREN];
  struct t_ast_node *next;
  int numberOfChildren;
} Node;

Node *createNode(TokenData *data);

Node *createCustomLabelNode(char *label, int line);

Node *addChild(Node *node, Node *child);

Node *addNext(Node *node, Node *next);

void exportAST(Node *node);

void freeAST(Node *node);

void exporta(void *arvore);

void libera(void *arvore);