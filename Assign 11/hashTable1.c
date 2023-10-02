#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21
typedef struct item {
  char *text;
  struct item *next;
} item_t;
typedef struct hash {
  item_t **table;
  int size;
  int hash_key;
} hash_t;
// Write your code here

hash_t *init_hashtable(int m , int hash_key ){
  item_t **arr = (item_t **)malloc(sizeof(item_t *) * m);
  hash_t *h = (hash_t *)malloc(sizeof(hash_t));
  h->size = m;
  h->hash_key = hash_key;
  h->table = arr;
  for(int i = 0;i<m;i++){
    h->table[i] = NULL;
  }
  return h;
}

unsigned int hash_function(hash_t *h, char *text,int n){
  if (n == 0)
    return text[n];
  return (h->hash_key * hash_function(h,text,n-1)) + text[n];
}

unsigned int hash(hash_t *h,char *text){
  int n = strlen(text)-1;
  return hash_function(h,text,n) % h->size;
}

void *insert(hash_t *h,char *text){
  unsigned int pos = hash(h,text);
  item_t *item = (item_t *)malloc(sizeof(item_t));
  item->text = malloc(strlen(text) + 1);
  strcpy(item->text, text);
  item->next = h->table[pos];
  h->table[pos] = item;
}

int isfind(item_t *t,char *txt){
  if (t == NULL)
    return 0;
  if (!strcmp(t->text,txt))
    return 1;
  return isfind(t->next,txt);
}

int *search(hash_t *h,char *text){
  unsigned int pos = hash(h,text);
  if (h->table[pos] == NULL)
    return -1;
  if (isfind(h->table[pos],text))
    return pos;
  else
    return -1;
}

int main(void) {
  hash_t *hashtable = NULL;
  char *text = NULL;
  int m, n, i, hash_key;
  int command;
  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);
  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
      case 1:
        insert(hashtable, text);
        break;
      case 2:
        printf("%d\n",search(hashtable, text));
        break;
    }
  }
  return 0;
}