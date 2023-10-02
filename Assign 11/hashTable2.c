#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21
typedef char* item_t;
typedef struct hash {
  item_t *table;
  int size;
  int hash_key;
} hash_t;
// Write your code here

hash_t *init_hashtable(int m , int hash_key ){
  item_t *tb = (item_t *)malloc(sizeof(item_t) * m);
  hash_t *h = (hash_t *)malloc(sizeof(hash_t));
  h->size = m;
  h->hash_key = hash_key;
  h->table = tb;
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
  int startpos = pos;
  int i = 0;
  while (h->table[pos] != NULL){
    pos = (startpos+(i+i*i)/2) % h->size;
    i++;
  }
  item_t item = (item_t)malloc(strlen(text));
  strcpy(item, text);
  h->table[pos] = item;
}

int search(hash_t *h,char *text){
  unsigned int pos = hash(h,text);
  unsigned int startpos = pos;
  int i = 0;
  while (h->table[pos] != NULL){
    i++;
    if (!strcmp(h->table[pos], text))
      return pos;
    pos = (startpos+(i+i*i)/2) % h->size;
    if (pos == startpos)
      return -1;
  }
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