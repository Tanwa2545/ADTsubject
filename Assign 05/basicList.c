#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;
// Write your code here

node_t *append(node_t *snode){
  node_t *node = (node_t *)malloc(sizeof (node_t));
  int num;
  scanf("%d",&num);
  node->next = NULL;
  node->data = num;
  if (snode==NULL)
    snode=node;
  else{
    node_t *newnode = snode;
    while (newnode->next!=NULL){
      newnode=newnode->next;
    }
    newnode->next=node;
  }
  return snode;
}

void get(node_t *snode) {
  int pos;
  scanf("%d",&pos);
  node_t *current = snode;
  for (int i=0;i<pos;i++){
    current = current->next;
  }
  printf("%d ", current->data);
  printf("\n");
}

void show(node_t *snode) {
  node_t *current = snode;
  while (current != NULL) {
      printf("%d ", current->data);
      current = current->next;
  }
  printf("\n");
}

node_t *reverse(node_t *snode) {
  node_t *current = snode,*nextnode = NULL,*prevnode = NULL;
  while (current!=NULL){
    nextnode = current->next;
    current->next = prevnode;
    prevnode = current;
    current = nextnode;
  }
  snode = prevnode;
  return snode;
}

node_t *cut(node_t *snode) {
  int pos1,pos2;
  scanf("%d %d",&pos1,&pos2);
  node_t *current = snode;
  for (int i=0;i<pos1;i++){
    current = current->next;
  }
  snode = current;
  node_t *newnode = current;
  for (int i=0;i<pos2-pos1;i++){
    current = current->next;
  }
  current->next = NULL;
  return snode;
}

int main(void) {
  node_t *startNode;
  int n,i;
  char command;
  startNode = NULL;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf(" %c", &command);
    switch (command) {
      case 'A':
        startNode = append(startNode);
        break;
      case 'G':
        get(startNode);
        break;
      case 'S':
        show(startNode);
        break;
      case 'R':
        startNode = reverse(startNode);
        break;
      case 'C':
        startNode = cut(startNode);
        break;
      default:
        break;
    }
  }
  return 0;
}