#include "symbolTable.h"

Node *createNode(TokenData *data, Type type);

Node *createCustomLabelNode(char *label, int line, Type type);

Node *addChild(Node *node, Node *child);

Node *addNext(Node *node, Node *next);

void exportAST(Node *node);

void freeAST(Node *node);

void exporta(void *arvore);

void libera(void *arvore);