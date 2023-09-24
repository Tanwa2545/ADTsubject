#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *next;
} node_t;

typedef node_t stack_t;

int hardpass(stack_t *x, stack_t *y){
  char input[10000];
  int f = 0,i = 0;
  scanf(" %s",input);
  while (input[i]!='y'){
    if (input[i] != 'x' && !f){
      node_t *node = (node_t *)malloc(sizeof (node_t));
      node->data = input[i];
      node->next = NULL;
      if (x==NULL)
        x = node;
      else {
        node_t *tmp = x;
        while (tmp->next!=NULL)
          tmp = tmp->next;
        tmp->next = node;
      }
    }
    if (input[i] != 'x' && f){
      node_t *node = (node_t *)malloc(sizeof (node_t));
      node->data = input[i];
      node->next = y;
      y = node;
    }
    if (input[i] == 'x')
      f = 1;
    if (input[i] == 'y')
      break;
    i++;
  }
  while (x != NULL || y!=NULL){
    if ((x==NULL && y!=NULL) || (x!=NULL && y==NULL))
      return 0;
    if (x->data != y->data)
      return 0;
    x=x->next;
    y=y->next;
  }
  return 1;
}

int main(void) {
  stack_t *x = NULL, *y = NULL;
  printf("%d",hardpass(x,y));
  return 0;
}