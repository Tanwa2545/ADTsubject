#include <stdio.h>
#include <stdlib.h>
// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// Write your code here

typedef struct node {
  int value;
  int parent;
  struct node *next_sibling;
  struct node *first_child;
} node_t;

typedef node_t tree_t;

typedef struct queue {
  int data;
  node_t* front;
  node_t* rear;
} queue_t;

tree_t *searchpos(tree_t *t,int v){
  if (t == NULL || t->value == v)
    return t;
  tree_t *pos = searchpos(t->first_child, v);
  if (pos != NULL)
    return pos;
  else
    return searchpos(t->next_sibling, v);
}

tree_t *attach(tree_t *t,int parent,int child){
  node_t *node = (node_t *)malloc(sizeof (node_t));
  node->value = child;
  node->parent = parent;
  node->next_sibling = NULL;
  node->first_child = NULL;
  if (parent == -1){
    node->parent = NULL;
    return node;
  }
  tree_t *pos = searchpos(t, parent);
  if (pos->first_child == NULL)
    pos->first_child = node;
  else {
    pos = pos->first_child;
    while (pos->next_sibling != NULL){
      pos = pos->next_sibling;
    }
    pos->next_sibling = node;
  }
  return t;
}

tree_t *detach(tree_t *t,int node){
  tree_t *pos = searchpos(t,node);
  if (pos == t){
    return NULL;
  }
  tree_t *ppos = searchpos(t,pos->parent);
  if (ppos->first_child == pos)
    ppos->first_child = pos->next_sibling;
  else{
    ppos = ppos->first_child;
    while (ppos->next_sibling!=pos){
      ppos = ppos->next_sibling;
    }
    ppos->next_sibling = pos->next_sibling;
  }
  return t;
}

int search(tree_t *t,int node){
  tree_t *pos = searchpos(t,node);
  if (pos == NULL)
    return 0;
  else
    return 1;
}

int degree(tree_t *t,int node){
  int n = 0;
  tree_t *pos = searchpos(t,node);
  pos = pos->first_child;
  while (pos!=NULL){
    n++;
    pos = pos->next_sibling;
  }
  return n;
}

int is_root(tree_t *t, int node){
  if (t->value == node)
    return 1;
  return 0;
}

int is_leaf(tree_t *t, int node){
  tree_t *pos = searchpos(t,node);
  if (pos->first_child == NULL)
    return 1;
  else
    return 0;
}

void siblings(tree_t *t, int node){
  tree_t *pos = searchpos(t,node);
  tree_t *ppos = searchpos(t,pos->parent);
  if (ppos!=NULL)
    ppos = ppos->first_child;
  while (ppos!=NULL){
    if (ppos->value != node)
      printf("%d ",ppos->value);
    ppos = ppos->next_sibling;
  }
  printf("\n");
}

int depth(tree_t *t, int node){
  int n=0;
  tree_t *pos = searchpos(t,node);
  while (pos->parent!=NULL){
    n++;
    pos=searchpos(t,pos->parent);
  }
  return n;
}

void print_path(tree_t *t,int st,int end){
  tree_t *pos = searchpos(t,end);
  while (pos->value!=st){
    tree_t *tmp = pos;
    printf("%d ",st);
    while (tmp->parent!=st){
      tmp = searchpos(t,tmp->parent);
    }
    st = tmp->value;
  }
  printf("%d\n",st);
}

int path_length(tree_t *t,int st,int end){
  int n = 1;
  tree_t *pos = searchpos(t,end);
  while (pos->value!=st){
    tree_t *tmp = pos;
    n++;
    while (tmp->parent!=st){
      tmp = searchpos(t,tmp->parent);
    }
    st = tmp->value;
  }
  return n;
}

void ancestor(tree_t *t,int node){
  int st = t->value;
  tree_t *pos = searchpos(t,node);
  while (pos->value!=st){
    tree_t *tmp = pos;
    printf("%d ",st);
    while (tmp->parent!=st){
      tmp = searchpos(t,tmp->parent);
    }
    st = tmp->value;
  }
  printf("%d\n",st);
}

queue_t *enqueue(queue_t *s,int v){
  node_t *node;
  node->value = v;
  node->parent = 0;
  node->next_sibling = NULL;
  node->first_child = NULL;
  if (s == NULL) {
    s->front = node;
    s->rear = node;
  } 
  else {
    s->rear->next_sibling = node;
    s->rear = node;
  }
  return s;
}

queue_t *dequeue(queue_t *s){
  if (s == NULL || s->front == NULL) {
    return s;
  }
  s->front = s->front->next_sibling;
  if (s->front == NULL) {
    s->rear = NULL;
  }
  return s;
}

void bfs(tree_t *t){
  queue_t *s = NULL;
  tree_t *r;
  s = enqueue(s, t->value);
  while(s!=NULL){
    printf("%d ",s->front->value);
    r = searchpos(t, s->front->value);
    if (r->first_child != NULL){
      r = r->first_child;
      while(r!=NULL){
        s = enqueue(s,r->value);
        r = r->next_sibling;
      }
    }
   s = dequeue(s);
  }
  printf("\n");
}

void descendant(tree_t *t,int node){
  tree_t *pos = searchpos(t,node);
  bfs(pos);
}

void dfs(tree_t *t){
  tree_t *s = t;
  printf("%d ",s->value);
  if (s->first_child != NULL)
    dfs(s->first_child);
  if (s->next_sibling != NULL)
    dfs(s->next_sibling);
}

void printingtree(tree_t *t,int n){
  tree_t *s = t;
  for (int i=0;i<n;i++)
    printf("    ");
  printf("%d\n",s->value);
  if (s->first_child != NULL){
    printingtree(s->first_child,n+1);
  }
  if (s->next_sibling != NULL)
    printingtree(s->next_sibling,n);
}

void print_tree(tree_t *t){
  int n = 0;
  if (t!=NULL) 
    printingtree(t,n);
}

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;
  
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n",path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}