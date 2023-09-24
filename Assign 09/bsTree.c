#include <stdio.h>
#include <stdlib.h>
#include "week9.h"
#ifndef __avl_tree__
typedef struct node {
  int data;
  int height;
  struct node *left;
  struct node *right;
} node_t;
typedef node_t avl_t;
#endif
// Write your code here
// ** Note that the print_tree() function has been implemented already and included in the week9.h header

node_t *createnode(int v){
  node_t *node = malloc(sizeof(node_t));
  node->data = v;
  node->height = 0;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int heightof(avl_t *t){
  if (t==NULL)
    return -1;
  return t->height;
}

int updateheight(avl_t *t){
  if (t == NULL)
    return 0;
  if (heightof(t->left) > heightof(t->right))
    return heightof(t->left)+1;
  else
    return heightof(t->right)+1;
}

int find_min(avl_t *t){
  while (t->left!=NULL){
    t=t->left;
  }
  return t->data;
}

avl_t *right_rotation(avl_t *a){
  avl_t *b = a->left;
  avl_t *tmp = b->right;
  b->right = a;
  a->left = tmp;
  a->height = updateheight(a);
  b->height = updateheight(b);
  return b;
}

avl_t *left_rotation(avl_t *a){
  avl_t *b = a->right;
  avl_t *tmp = b->left;
  b->left = a;
  a->right = tmp;
  a->height = updateheight(a);
  b->height = updateheight(b);
  return b;
}

avl_t *left_right_rotation(avl_t *a){
  avl_t *b = a->left;
  b = left_rotation(b);
  a->left = b;
  a = right_rotation(a);
  a->height = updateheight(a);
  b->height = updateheight(b);
  return a;
}

avl_t *right_left_rotation(avl_t *a){
  avl_t *b = a->right;
  b = right_rotation(b);
  a->right = b;
  a = left_rotation(a);
  a->height = updateheight(a);
  b->height = updateheight(b);
  return a;
}

avl_t *rotatetree(avl_t *t,int v){
  if ((heightof(t->left) > heightof(t->right)+1) && (v < t->left->data))
    return right_rotation(t);
  else if ((heightof(t->right) > heightof(t->left)+1) && (v > t->right->data))
    return left_rotation(t);
  else if ((heightof(t->left) > heightof(t->right)+1) && (v > t->left->data))
    return left_right_rotation(t);
  else if ((heightof(t->right) > heightof(t->left)+1) && (v < t->right->data))
    return right_left_rotation(t);
  return t;
}

/*avl_t *updateheight(avl_t *t){
  if (t==NULL)
    return t;
  if (t->left == NULL && t->right == NULL)
    t->height = 0;
  if (t->left != NULL && t->right == NULL){
    updateheight(t->left);
    t->height = t->left->height+1;
  }
  if (t->left == NULL && t->right != NULL){
    updateheight(t->right);
    t->height = t->right->height+1;
  }
  if (t->left != NULL && t->right != NULL){
    updateheight(t->left);
    updateheight(t->right);
    if (t->left->height >= t->right->height)
      t->height = t->left->height+1;
    else
      t->height = t->right->height+1;
  }
  return t;
}*/

avl_t *insert(avl_t *t,int v){
  if (t == NULL)
    return (createnode(v));
  if (t->data > v)
    t->left = insert(t->left,v);
  else if (t->data < v)
    t->right = insert(t->right,v);
  t->height = updateheight(t);
  return rotatetree(t,v);
}

int moreleft(avl_t *t){
  if (heightof(t->left) > heightof(t->right))
    return 1;
  return 0;
}

avl_t *delete(avl_t *t,int v){
  if (t == NULL)
    return t;
  if (t->data > v)
    t->left = delete(t->left,v);
  else if (t->data < v)
    t->right = delete(t->right,v);
  if (t->data == v){
    if (t->left == NULL && t->right == NULL)
      t = NULL;
    else if (t->left != NULL && t->right == NULL)
      t = t->left;
    else if (t->left == NULL && t->right != NULL)
      t = t->right;
    else if (t->left != NULL && t->right != NULL){
      int rpnode = find_min(t->right);
      t->right = delete(t->right,rpnode);
      t->data = rpnode;
    }
  }
  if (t==NULL)
    return t;
  t->height = updateheight(t);
  if ((heightof(t->left) > heightof(t->right)+1) && (moreleft(t->left)))
    return right_rotation(t);
  else if ((heightof(t->right) > heightof(t->left)+1) && !(moreleft(t->right)))
    return left_rotation(t);
  else if ((heightof(t->left) > heightof(t->right)+1) && !(moreleft(t->left)))
    return left_right_rotation(t);
  else if ((heightof(t->right) > heightof(t->left)+1) && (moreleft(t->right)))
    return right_left_rotation(t);
  return t;
}

int main(void) {
  avl_t *t = NULL;
  int n, i;
  int command, data;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        t = insert(t, data);
        break;
      case 2:
        scanf("%d", &data);
        t = delete(t, data);
        break;
      case 3:
        print_tree(t);
        break;
    }
  }
  return 0;
}