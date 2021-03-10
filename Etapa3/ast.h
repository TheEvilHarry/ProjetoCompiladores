#include "tokenutils.h"

#define MAX_CHILDREN 4

typedef struct t_node {
    char *label;
    LEXICAL_VALUE* value;
    struct t_node *children[MAX_CHILDREN];
    struct t_node *next;

} NODE;


struct NODE* createNode(LEXICAL_VALUE *value,char *label);

struct NODE* addChild(NODE *node, NODE *child);