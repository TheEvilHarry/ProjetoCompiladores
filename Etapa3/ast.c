#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Node *createNode(TokenData *data)
{
  // printf("Creating node with label %s on line %d\n", data->label, data->line);

  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->numberOfChildren = 0;

  node->next = NULL; //malloc(sizeof(Node) * MAX_CHILDREN);

  return node;
}

Node *createCustomLabelNode(char *label, int line)
{
  // printf("Creating node with custom label %s\n", label);

  TokenData *data = createNonLiteralToken(line, SPECIAL_TYPE, label);
  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->numberOfChildren = 0;

  node->next = NULL; //malloc(sizeof(Node) * MAX_CHILDREN);

  return node;
}

Node *addChild(Node *node, Node *child)
{
  if (node == NULL)
  {
    printf("Adding child to NULL node\n");
  }
  if (child == NULL)
  {
    printf("Adding NULL child to node %s\n", node->data->label);
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

void exportAST(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  // printf("Exporting node with label %s and %d children\n", node->data->label, node->numberOfChildren);

  for (int i = 0; i < node->numberOfChildren; i++)
  {
    printf("Iterating over node %s's children (%d/%d)...\n", node->data->label, i + 1, node->numberOfChildren);
    printf("%p, %p\n", node, node->children[i]);
    exportAST(node->children[i]);
  }
  if (node->next != NULL)
  {
    printf("Node's next is not null, exporting...\n");
    printf("%p, %p\n", node, node->next);
    exportAST(node->next);
  }
  if (node->data && node->data->label != NULL)
  {
    printf("Node has a label, printing...\n");
    printf("%p [label=\"%s\"]\n", node, node->data->label);
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