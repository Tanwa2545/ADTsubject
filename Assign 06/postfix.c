#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  float data;
  struct node *next;
} node_t;

typedef node_t stack_t;

float postfix(stack_t *s,int n){
  char input[n];
  scanf(" %s",input);
  for (int i=0;i<n;i++){
    if (input[i] >= '0' && input[i] <= '9'){
      node_t *node = (node_t *)malloc(sizeof (node_t));
      node->data = input[i] - '0';
      node->next = s;
      s = node;
    }
    if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
      if (s == NULL){
        return 0;
      }
      if (input[i] == '+'){
        s->data = s->data + s->next->data;
        s->next = s->next->next;
      }
      if (input[i] == '-'){
        s->data = s->next->data - s->data;
        s->next = s->next->next;
      }
      if (input[i] == '*'){
        s->data = s->data * s->next->data;
        s->next = s->next->next;
      }
      if (input[i] == '/'){
        s->data = s->next->data/s->data;
        s->next = s->next->next;
      }
    }
  }
  return s->data;
}

int main(void) {
  stack_t *s = NULL;
  int n;
  scanf("%d",&n);
  printf("%.2f",postfix(s,n));
  return 0;
}