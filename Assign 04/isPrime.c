#include <stdio.h>
#include <math.h>
int isPrime(int n,int d){
  for (int i=2;i<=d;i++){
    if (n%i==0)
      return 0;
  }
  return 1;
}
int main(void) {
  int n,i,d;
  scanf("%d",&n);
  d=sqrt(n);
  printf("%d",isPrime(n,d));
  return 0;
}
// bigO = O(sqrt(n))