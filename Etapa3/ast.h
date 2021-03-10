#include "tokenutils.h"

#define MAX_CHILDREN 4

typedef struct t_ast_node
{
  char *label;
  TokenData *data;

  struct t_node *children[MAX_CHILDREN];
  struct t_node *next;
  int numberOfChildren;
} Node;

Node *createNode(TokenData *data, char *label);

Node *addChild(Node *node, Node *child);

Node *addNext(Node *node, Node *next);

void exporta(Node *arvore);

void libera(Node *arvore);