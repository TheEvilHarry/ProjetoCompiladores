#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Node *createNode(TokenData *data, Type type)
{
  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->numberOfChildren = 0;
  node->type = type;

  node->next = NULL;

  return node;
}

Node *createCustomLabelNode(char *label, int line, Type type)
{
  TokenData *data = createNonLiteralToken(line, SPECIAL_TYPE, label);
  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->numberOfChildren = 0;
  node->type = type;

  node->next = NULL;
  // node->local= gen

  return node;
}

Node *addChild(Node *node, Node *child)
{
  if (node == NULL)
  {
    return child;
  }
  if (child == NULL)
  {
    return node;
  }
  node->children[node->numberOfChildren] = child;
  node->numberOfChildren++;

  return node;
}

Node *addNext(Node *node, Node *next)
{
  if (node == NULL)
  {
    return next;
  }
  if (next == NULL)
  {
    return node;
  }

  node->next = next;

  return node;
}

Node *addTypeToNode(Node *node, Type type)
{
  if (node == NULL)
  {
    printf("[WARNING] Attempted to add type to null node\n");
    return node;
  }
  else
  {
    node->type = type;
    return node;
  }
}

void exportAST(Node *node)
{
  if (node == NULL || node->data == NULL)
  {
    return;
  }

  for (int i = 0; i < node->numberOfChildren; i++)
  {
    printf("%p, %p\n", node, node->children[i]);
    exportAST(node->children[i]);
  }
  if (node->next != NULL)
  {
    printf("%p, %p\n", node, node->next);
    exportAST(node->next);
  }
  if (node->data != NULL)
  {
    if (node->data->label != NULL)
    {
      printf("%p [label=\"%s\"]\n", node, node->data->label);
    }
  }

  return;
}

void exporta(void *arvore)
{
  exportAST((Node *)arvore);
}

void freeAST(Node *node)
{
  if (node != NULL)
  {
    for (int i = 0; i < node->numberOfChildren; i++)
    {
      freeAST(node->children[i]);
    }
    if (node->next != NULL)
    {
      freeAST(node->next);
    }
    if (node->data != NULL)
    {
      freeToken(node->data);
    }
    free(node);
  }
}

void libera(void *arvore)
{
  freeAST((Node *)arvore);
  freeTableStack(getGlobalStack());
}