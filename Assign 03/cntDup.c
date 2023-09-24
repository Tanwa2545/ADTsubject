#include <stdio.h>
int main(void) {
  int num[100],count[100];
  int n,m,i,j,max=0;
  for (i=0;i<100;i++){
    num[i]=i;
    count[i]=0;
  }
  scanf("%d",&n);
  for (i=0;i<n;i++){
    j=0;
    scanf("%d",&m);
    while (j<100){
      if (num[j]==m){
        count[j]+=1;
        break;
      }
      j++;
    }
  }
  for (i=0;i<100;i++){
    if (count[i]>max){
      max=count[i];
    }
  }
  for (i=0;i<100;i++){
    if (count[i]==max){
      printf("%d ",num[i]);
    }
  }
  return 0;
}