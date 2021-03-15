#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Node *createNode(TokenData *data)
{
  printf("Creating node with label %s on line %d\n", data->label, data->line);

  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->numberOfChildren = 0;

  node->next = malloc(sizeof(Node) * MAX_CHILDREN);

  return node;
}

Node *createAttributionNode(){

    return NULL;
}

Node *createInitializationNode(){
    return NULL;
}

Node *createFuncCallNode(){

     return NULL;

}

Node *createShiftNode(TokenData *data){
    return NULL;

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
  if (node->data->label != NULL)
  {
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