#include "symbolTable.h"


Node *createNode(TokenData *data, Type type);

Node *createCustomLabelNode(char *label, int line, Type type);

Node *addChild(Node *node, Node *child);

Node *addNext(Node *node, Node *next);

Node *addTypeToNode(Node *node, Type type);

Node *addCodeToNode(Node *node, Code *code);

void exportAST(Node *node);

void freeAST(Node *node);

void exporta(void *arvore);

void libera(void *arvore);