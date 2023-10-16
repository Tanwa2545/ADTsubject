#include <stdio.h>
#include <stdlib.h>

void print_list(int *list, int size) {
  for(int i=0; i<size; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

void *insertion_sort(int *list, int n){
  for(int i=1; i<n; i++){
    int j = i;
    while((j > 0) && (list[j-1] > list[j])){
      int temp = list[j];
      list[j] = list[j-1];
      list[j-1] = temp;
      j--;
    }
    print_list(list, n);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  int *list = (int*)malloc(sizeof(int) * n);
  for(int i=0;i<n;i++){
    scanf("%d", &list[i]);
  }
  insertion_sort(list, n);
  return 0;
}