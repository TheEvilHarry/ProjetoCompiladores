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

  node->next = NULL;

  return node;
}

Node *createCustomLabelNode(char *label, int line)
{
  printf("Creating node with custom label %s\n", label);

  TokenData *data = createNonLiteralToken(line, SPECIAL_TYPE, label);
  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->numberOfChildren = 0;

  node->next = NULL;

  return node;
}

Node *addChild(Node *node, Node *child)
{
  if (node == NULL)
  {
    printf("Adding child to NULL node\n");
    return child;
  }
  if (child == NULL)
  {
    printf("Adding NULL child to node %s\n", node->data->label);
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

void exportAST(Node *node)
{
  if (node == NULL || node->data == NULL)
  {
    return;
  }
  // printf("Exporting node with label %s and %d children\n", node->data->label, node->numberOfChildren);

  for (int i = 0; i < node->numberOfChildren; i++)
  {
    // printf("Iterating over node %s's children (%d/%d)...\n", node->data->label, i + 1, node->numberOfChildren);
    printf("%p, %p\n", node, node->children[i]);
    exportAST(node->children[i]);
  }
  if (node->next != NULL)
  {
    // printf("Node's next is not null, exporting...\n");
    printf("%p, %p\n", node, node->next);
    exportAST(node->next);
  }
  if (node->data != NULL)
  {
    if (node->data->label != NULL)
    {
      // printf("Node has a label, printing...\n");
      printf("%p [label=\"%s\"]\n", node, node->data->label);
    }
  }

  return;
}

// void printNodeInfo(Node *node, char *number)
// {
//   printf("Printing node %s\n", number);
//   if (node == NULL)
//   {
//     printf("Node %s is NULL\n", number);
//     return;
//   }
//   printf("Node %s is %s and has %d children\n", number, node->data->label, node->numberOfChildren);
//   if (node->next != NULL)
//   {
//     printf("Node %s has next and is %s\n", number, node->next->data->label);
//   }
// }

void exporta(void *arvore)
{
  // Node *node = (Node *)arvore;
  // printNodeInfo(node, "0");
  // Node *child1 = (Node *)node->children[0];
  // printNodeInfo(child1, "1");

  // Node *child11 = (Node *)child1->children[0];
  // printNodeInfo(child11, "11");
  // Node *child12 = (Node *)child1->children[1];
  // printNodeInfo(child12, "12");
  // Node *child13 = (Node *)child1->children[2];
  // printNodeInfo(child13, "13");
  // Node *child14 = (Node *)child1->children[3];
  // printNodeInfo(child14, "14");

  // Node *child131 = (Node *)child13->children[0];
  // printNodeInfo(child131, "131");
  // Node *child132 = (Node *)child13->children[1];
  // printNodeInfo(child132, "132");

  // Node *child1321 = (Node *)child132->children[0];
  // printNodeInfo(child1321, "1321");
  // Node *child1322 = (Node *)child132->children[1];
  // printNodeInfo(child1322, "1322");

  // Node *child141 = (Node *)child14->children[0];
  // printNodeInfo(child141, "141");
  // Node *child142 = (Node *)child14->next;
  // printNodeInfo(child142, "142");

  // Node *child1421 = (Node *)child142->children[0];
  // printNodeInfo(child1421, "1421");
  // Node *child1422 = (Node *)child142->next;
  // printNodeInfo(child1422, "1422");

  // Node *child14221 = (Node *)child1422->children[0];
  // printNodeInfo(child14221, "14221");
  // Node *child14222 = (Node *)child1422->children[1];
  // printNodeInfo(child14222, "14222");
  // Node *child14223 = (Node *)child1422->next;
  // printNodeInfo(child14223, "14223");

  // Node *child142231 = (Node *)child14223->children[0];
  // printNodeInfo(child142231, "142231");
  // Node *child142232 = (Node *)child14223->children[1];
  // printNodeInfo(child142232, "142232");

  // Node *child1422321 = (Node *)child142232->children[0];
  // printNodeInfo(child1422321, "1422321");
  // Node *child1422322 = (Node *)child142232->children[1];
  // printNodeInfo(child1422322, "1422322");

  // Node *child121 = (Node *)child12->children[0];
  // printNodeInfo(child121, "121");
  // Node *child122 = (Node *)child12->children[1];
  // printNodeInfo(child122, "122");

  // Node *child111 = (Node *)child11->children[0];
  // printNodeInfo(child111, "111");
  // Node *child112 = (Node *)child11->children[1];
  // printNodeInfo(child112, "112");
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