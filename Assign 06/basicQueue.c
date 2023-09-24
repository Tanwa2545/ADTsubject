#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef node_t queue_t;
// Write your code here

queue_t *enqueue(queue_t *q,int v){
  node_t *node = (node_t *)malloc(sizeof (node_t));
  node->data = v;
  node->next = NULL;
  if (q == NULL)
    q = node;
  else{
    node_t *tmp = q;
    while (tmp->next!=NULL)
      tmp = tmp->next;
    tmp->next = node;
  }
  return q;
}

queue_t *dequeue(queue_t *q){
  node_t *tmp = q;
  if (q==NULL){
    printf("Queue is empty.\n");
    return q;
  }
  while (tmp!=NULL){
    if (tmp->next==NULL){
      printf("%d\n",tmp->data);
      q = NULL;
      break;
    }
    if (tmp->next!=NULL && tmp->next->next==NULL){
      printf("%d\n",tmp->next->data);
      tmp->next = NULL;
      break;
    }
    tmp=tmp->next;
  }
  return q;
}

void show(queue_t *q){
  if (q==NULL)
    printf("Queue is empty.\n");
  while (q!=NULL){
    printf("%d ",q->data);
    q=q->next;
  }
  printf("\n");
}

void empty(queue_t *q){
  if (q==NULL)
    printf("Queue is empty.\n");
  else
    printf("Queue is not empty.\n");
}

void size(queue_t *q){
  int n=0;
  while (q!=NULL){
    q=q->next;
    n++;
  }
  printf("%d\n",n);
}

int main(void) {
  queue_t *q = NULL;
  int n, i, command, value;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;
    }
  }
  return 0;
}