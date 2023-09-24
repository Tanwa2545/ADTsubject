#include <stdio.h>
#include <stdlib.h>

typedef struct person {
  int pos;
  int maxdrink;
  int nowdrink;
  struct person *next;
} person_t;

person_t *createlist(person_t *sp, int n) {
  person_t *current = sp;
  int num;
  for (int i = 0; i < n; i++) {
    person_t *thisguy = (person_t *)malloc(sizeof(struct person));
    thisguy->next = NULL;
    scanf("%d", &num);
    thisguy->pos = i+1;
    thisguy->maxdrink = num;
    thisguy->nowdrink = 0;
    if (current == NULL)
      sp = thisguy;
    else {
      current->next = thisguy;
    }
    current = thisguy;
  }
  current->next = sp;
  return sp;
}

int checkdigit(int num, int k){
  while (num>0){
    if (num%10==k)
      return 1;
    num/=10;
  }
  return 0;
}

void gaming(person_t *sp,int n, int k){
  person_t *current = sp, *prev = sp;
  int count=1;
  while (n>1){
    while (1){
      if ((checkdigit(count, k)) || count%k==0)
        break;
      prev = current;
      current=current->next;
      count+=1;
      //printf("%d ok ",count%k);
    }
    count+=1;
    if (current->nowdrink+1 > current->maxdrink){
      prev->next=current->next;
      free(current);
      current=prev->next;
      n-=1;
    }
    else {
      //printf("%d %d %d , ",current->pos,current->nowdrink,count);
      prev = current;
      current->nowdrink++;
      current = current->next;
    }
  }
  printf("%d",current->pos);
}

int main(void) {
  person_t *startperson;
  int n,k;
  startperson = NULL;
  scanf("%d %d", &n, &k);
  startperson = createlist(startperson,n);
  gaming(startperson,n,k);
  return 0;
}