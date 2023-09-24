#include<stdio.h>
#include<math.h>

int fact(int k){
  int n=1;
  for (int i=1;i<=k;i++) {
    n *= i;
  }
  return n;
}

int main(void){
  int n,m;
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    int stn=1,dg;
    scanf("%d", &m);
    for (int l=1;l<m;l++){
      int su=0,p=l;
      while (p>0){
        int x=p%10;
        su+=fact(x);
        p/=10;
      }
      if (l==su){
        if (l>stn){
          stn=l;
        }
      }
    }
    printf("%d\n",stn);
  }
  return 0;
}