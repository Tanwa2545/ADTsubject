#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *next;
} node_t;

typedef node_t stack_t;

int isParenthesis(stack_t *s,int n){
  char input[n];
  scanf(" %s",input);
  for (int i=0;i<n;i++){
    if (input[i] == '(' || input[i] == '[' || input[i] == '{'){
      node_t *node = (node_t *)malloc(sizeof (node_t));
      node->data = input[i];
      node->next = s;
      s = node;
    }
    if (input[i] == ')' || input[i] == ']' || input[i] == '}'){
      if (s == NULL){
        return 0;
      }
      if ((input[i] == ')' && s->data == '(') || (input[i] == ']' && s->data == '[') || (input[i] == '}' && s->data == '{')){
        s = s->next;
      }
      else
        return 0;
    }
  }
  if (s == NULL)
    return 1;
  else
    return 0;
}

int main(void) {
  stack_t *s = NULL;
  int n;
  scanf("%d",&n);
  printf("%d",isParenthesis(s,n));
  return 0;
}