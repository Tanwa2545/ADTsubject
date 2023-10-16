#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(char *list, int n){
  for(int i=1; i<n; i++){
    int j = i;
    while((j > 0) && list[j-1]>list[j]){
      char temp = list[j];
      list[j] = list[j-1];
      list[j-1] = temp;
      j--;
    }
  }
}

int main(void) {
  int i,m,n;
  scanf("%d %d",&m, &n);
  char **dict = (char**)malloc(sizeof(char* ) * m);
  char *inputstr = (char*)malloc(sizeof(char[50]));
  char *fromdict = (char*)malloc(sizeof(char) * 50);
  for(i=0;i<m;i++){
    char *tmp = (char*)malloc(sizeof(char) * 50);
    scanf(" %s", tmp);
    dict[i] = tmp;
  }
  for(i=0;i<n;i++){
    scanf(" %s", inputstr);
    insertion_sort(inputstr,strlen(inputstr));
    for (int j=0;j<m;j++){
      strcpy(fromdict, dict[j]);
      insertion_sort(fromdict,strlen(dict[j]));
      if (strcmp(inputstr, fromdict) == 0){
        printf("%s ",dict[j]);
      }
    }
      printf("\n");
  }
  return 0;
}