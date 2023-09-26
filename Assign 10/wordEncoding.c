#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *s;
    int freq;
    struct node *left;
    struct node *right;
} node_t;

typedef struct heap {
    node_t **data;
    int last_index;
} heap_t;

heap_t *init_heap(int n){
    node_t **arr = (node_t **)malloc(n * sizeof(node_t));
    node_t *node = (node_t *)malloc(sizeof(node_t));
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    node->s = "";
    node->freq = 0;
    node->left = NULL;
    node->right = NULL;
    h->data = arr;
    h->last_index = 0;
    h->data[0] = node;
    return h;
}

void bfs(heap_t *h){
  for (int i = 1;i <= h->last_index;i++){
    printf("%d-%d-%s ",i,h->data[i]->freq,h->data[i]->s);
  }
  printf("\n");
}

void *updateinsert(heap_t *h,int i){
    int parent = i/2;
    if (parent <= 0)
        return NULL;
    if (h->data[parent]->freq > h->data[i]->freq){
        node_t *tmp = h->data[parent];
        h->data[parent] = h->data[i];
        h->data[i] = tmp;
        updateinsert(h,parent);
    }
}

void *updatedelete(heap_t *h,int i){
    int c1 = i*2, c2 = i*2+1;
    if (c1 > h->last_index)
      return NULL;
    if (c1 == h->last_index){
      if (h->data[c1]->freq < h->data[i]->freq){
        node_t *tmp = h->data[i];
        h->data[i] = h->data[c1];
        h->data[c1] = tmp;
      }
    }
    else {
      if (h->data[c1]->freq < h->data[i]->freq && h->data[c1]->freq <= h->data[c2]->freq){
        node_t *tmp = h->data[i];
        h->data[i] = h->data[c1];
        h->data[c1] = tmp;
        updatedelete(h,c1);
      }
      if (h->data[c2]->freq < h->data[i]->freq){
        node_t *tmp = h->data[i];
        h->data[i] = h->data[c2];
        h->data[c2] = tmp;
        updatedelete(h,c2);
      }
    }
}

void *delete_min(heap_t *h){
    h->data[1] = h->data[h->last_index];
    h->data[h->last_index] = NULL;
    h->last_index --;
    updatedelete(h,1);
}

void *insert(heap_t *h,char *st, int v){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->s = st;
    node->freq = v;
    node->left = NULL;
    node->right = NULL;
    h->last_index ++;
    int i = h->last_index;
    h->data[i] = node;
    updateinsert(h,i);
}

void *huffmanround(heap_t *h){
    node_t *tmp1 = NULL, *tmp2 = NULL;
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    int i = 0;
    if (h->last_index > 1){
        tmp1 = h->data[1];
        i += tmp1->freq;
        delete_min(h);
        if (h->last_index >= 1){
            tmp2 = h->data[1];
            i += tmp2->freq;
            delete_min(h);
        }
    }
    newnode->freq = i;
    newnode->s = "";
    newnode->left = tmp1;
    newnode->right = tmp2;
    h->last_index++;
    i = h->last_index;
    h->data[i] = newnode;
    updateinsert(h,i);
}

void printhuffman(node_t *arr, char code[100]){
    if (arr == NULL){
        return;
    }
    if (arr->s != ""){
        printf("%s: %s\n",arr->s,code);
    }
    char left[100], right[100];
    strcpy(left, code);
    strcpy(right, code);
    strcat(left, "0");
    strcat(right, "1");
    printhuffman(arr->left,left);
    printhuffman(arr->right,right);
}

int main(void) {
    int n,i;
    heap_t *h = NULL;
    scanf("%d",&n);
    int num;
    char code[100] = "";
    h = init_heap(n);
    for (i=0;i<n;i++){
        char *st = (char *)malloc(sizeof(char) * 16);
        scanf("%s %d",st,&num);
        insert(h,st,num);
    }
    while (h->last_index > 1){
        huffmanround(h);
    }
    printhuffman(h->data[1],code);
}