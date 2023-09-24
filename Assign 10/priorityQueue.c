#include <stdio.h>
#include <stdlib.h>
typedef struct heap {
  int *data;
  int last_index;
} heap_t;
// Write your code here

void bfs(heap_t *h){
  for (int i = 1;i <= h->last_index;i++){
    printf("%d ",h->data[i]);
  }
  printf("\n");
}

heap_t *init_heap(int m){
  int *arr = (int *)malloc(m * sizeof(int) + 1);
  heap_t *h = (heap_t *)malloc(sizeof(heap_t));
  h->data = arr;
  h->last_index = 0;
  h->data[0] = -1;
  return h;
}

void *updateinsert(heap_t *h,int i){
  int parent = i/2;
  if (parent <= 0)
    return ;
  if (h->data[parent] < h->data[i]){
    int tmp = h->data[parent];
    h->data[parent] = h->data[i];
    h->data[i] = tmp;
    updateinsert(h,parent);
  }
}

void *insert(heap_t *h,int v){
  h->last_index += 1;
  h->data[h->last_index] = v;
  updateinsert(h,h->last_index);
}

void *updatedelete(heap_t *h,int i){
  int c1 = i*2, c2 = i*2+1;
  if (c1 > h->last_index)
    return ;
  if (c1 == h->last_index){
    if (h->data[c1] > h->data[i]){
      int tmp = h->data[i];
      h->data[i] = h->data[c1];
      h->data[c1] = tmp;
    }
  }
  else {
    if (h->data[c1] > h->data[i]){
      int tmp = h->data[i];
      h->data[i] = h->data[c1];
      h->data[c1] = tmp;
      updatedelete(h,c1);
    }
    if (h->data[c2] > h->data[i]){
      int tmp = h->data[i];
      h->data[i] = h->data[c1];
      h->data[c1] = tmp;
      updatedelete(h,c2);
    }
  }
}

void *delete_max(heap_t *h){
  h->data[1] = h->data[h->last_index];
  h->data[h->last_index] = 0;
  h->last_index -= 1;
  updatedelete(h,1);
}

int find_max(heap_t *h){
  return (h->last_index == 0)? -1 : h->data[1];
}

void *update_key(heap_t *h, int okey, int nkey){
  int i = 1;
  while (h->data[i]!=okey){
    i+=1;
  }
  h->data[i] = nkey;
  updateinsert(h,i);
  updatedelete(h,i);
}

int main(void) {
  heap_t *max_heap = NULL;
  int m, n, i;
  int command, data;
  int old_key, new_key;
  scanf("%d %d", &m, &n);
  max_heap = init_heap(m);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        insert(max_heap, data);
        break;
     case 2:
        delete_max(max_heap);
        break;
      case 3:
        printf("%d\n", find_max(max_heap));
        break;
      case 4:
        scanf("%d %d", &old_key, &new_key);
        update_key(max_heap, old_key,new_key);
        break;
      case 5:
        bfs(max_heap);
        break;
    }
  }
  return 0;
}