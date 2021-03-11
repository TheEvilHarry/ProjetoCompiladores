#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Node *createNode(TokenData *data, char *label)
{
  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->numberOfChildren = 0;
  node->label = strdup(label);

  memset(&node->children, (Node *)NULL, sizeof(Node) * MAX_CHILDREN);
  node->next = NULL;

  return node;
}

Node *addChild(Node *node, Node *child)
{
  node->children[node->numberOfChildren] = child;
  node->numberOfChildren++;

  return node;
}

Node *addNext(Node *node, Node *next)
{
  node->next = next;

  return node;
}

void exportAST(Node *node)
{
  if (node == NULL)
  {
    return;
  }

  for (int i = 0; i < node->numberOfChildren; i++)
  {
    printf("%p, %p\n", node, node->children[i]);
    exporta(node->children[i]);
  }
  if (node->next != NULL)
  {
    printf("%p, %p\n", node, node->next);
    exporta(node->next);
  }
  if (node->label != NULL)
  {
    printf("%p [label=\"%s\"]\n", node, node->label);
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

    freeToken(node->data);
    free(node);
  }
}

void libera(void *arvore)
{
  freeAST((Node *)arvore);
}