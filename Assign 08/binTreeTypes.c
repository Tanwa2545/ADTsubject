#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;
#endif
// Write your code here
// ** Note that the attach() function hasbeen implemented already and includedin the week8.h header

typedef struct queue {
  tree_t *address;
  struct queue *next;
} queue_t;

queue_t *enqueue(queue_t *q, tree_t *t) {
  queue_t *newQueue;
  newQueue = (queue_t *)malloc(sizeof(queue_t));
  newQueue->address = t;
  newQueue->next = NULL;

  if (q == NULL)
    return newQueue;

  queue_t *current = q;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newQueue;
  return q;
}

tree_t *dequeue(queue_t **q) {
  tree_t *tree_node = NULL;
  queue_t *firstQueue = *q;

  tree_node = firstQueue->address;
  *q = firstQueue->next;
  free(firstQueue);
  return tree_node;
}

int isEmpty(queue_t *q) {
  if (q == NULL)
    return 1;
  return 0;
}

int size(tree_t *t){
    if (t == NULL)
        return 0;
    return size(t->left)+ size(t->right)+ 1;
}

int height(tree_t *t){
    int hl,hr;
    if (t == NULL)
        return -1;
    hl = height(t->left);
    hr = height(t->right);
    return (hl>hr)? hl+1 : hr+1;
}


int is_full(tree_t *t){
    if (t == NULL || (t->left==NULL && t->right==NULL))
        return 1;
    if ((t->left==NULL && t->right!=NULL) || (t->left!=NULL && t->right==NULL))
        return 0;
    else
        return is_full(t->left) && is_full(t->right);
}

int is_perfect(tree_t *t){
    int h,n,count=1;
    h = height(t);
    n = size(t);
    for (int i=0;i<=h;i++){
        count*=2;
    }
    count-=1;
    if ((h==-1) || (n==count))
        return 1;
    else
        return 0;
}

int hperfect(tree_t *t, int h){
    int n,count=1;
    n = size(t);
    for (int i=0;i<=h;i++){
        count*=2;
    }
    count-=1;
    if ((h==-1) || (n==count))
        return 1;
    else
        return 0;
}

int completetree(tree_t *t, int h){
    if (t == NULL || (t->left==NULL && t->right==NULL))
        return 1;
    if (t->left==NULL && t->right!=NULL)
        return 0;
    if (hperfect(t->left,h-1))
        return completetree(t->right,h-1);
    if (hperfect(t->right,h-2))
        return completetree(t->left,h-1);
    return 0;
}

int is_complete(tree_t *t){
    if (t == NULL || (t->left==NULL && t->right==NULL))
        return 1;
    int h = height(t);
    if (t->left==NULL && t->right!=NULL)
        return 0;
    if ((height(t->left) > height(t->right)+1 ) || (height(t->right) > height(t->left)))
        return 0;
    return completetree(t,h);
}

/*int is_complete(tree_t *t) {
  if (t == NULL)
    return 1;
  int seen_end = 0;
  queue_t *q = NULL;
  q = enqueue(q, t);
  while (!isEmpty(q)) {
    tree_t *current_tree = dequeue(&q);
    if (current_tree == NULL) {
      seen_end = 1;
    } else {
      if (seen_end)
        return 0;
      q = enqueue(q, current_tree->left);
      q = enqueue(q, current_tree->right);
    }
  }
  return 1;
}*/

int is_degenerate(tree_t *t){
    if (t==NULL || (t->left==NULL && t->right==NULL))
        return 1;
    if (t->left==NULL && t->right!=NULL)
        return is_degenerate(t->right);
    if (t->left!=NULL && t->right==NULL)
        return is_degenerate(t->left);
    else
        return 0;
}

int is_skewed(tree_t *t){
    if (t==NULL || (t->left==NULL && t->right==NULL))
        return 1;
    if (t->left==NULL && t->right!=NULL){
        while (t!=NULL){
            if (t->left!=NULL)
                return 0;
            t=t->right;
        }
        return 1;
    }
    if (t->left!=NULL && t->right==NULL){
        while (t!=NULL){
            if (t->right!=NULL)
                return 0;
            t=t->left;
        }
        return 1;
    }
    else
        return 0;
}

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child,&branch);
        t = attach(t, parent, child, branch);
    }
    printf("%d %d %d %d %d\n", is_full(t),is_perfect(t),is_complete(t),is_degenerate(t),is_skewed(t));
    return 0;
}