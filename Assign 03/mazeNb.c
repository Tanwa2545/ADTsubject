#include <stdio.h>

void prnt1(int n){
  int i,j,table[n][n];
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      table[i][j]=i+(n*j)+1;
    }
  }
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      printf("%d ",table[i][j]);
    }
    printf("\n");
  }
}

void prnt2(int n){
  int i,j,table[n][n];
  for (i=0;i<n;i++){
    if (i%2==0){
      for (j=0;j<n;j++){
        table[i][j]=(n*i)+j+1;
      }
    }
    else{
      for (j=0;j<n;j++){
        table[i][n-j-1]=(n*i)+j+1;
      }
    }
  }
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      printf("%d ",table[j][i]);
    }
    printf("\n");
  }
}

void prnt3(int n){
  int i,j,table[n][n],count=1;
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      table[i][j]=0;
    }
  }
  for (i=0;i<n;i++){
    for (j=0;j<i+1;j++){
      if (i%2!=0){
        table[i-j][j]=count;
        count++;
      }
      else{
        table[j][i-j]=count;
        count++;
      }
    }
  }
  for (i=0;i<n-1;i++){
    for (j=0;j<n-i-1;j++){
      if ((i+n)%2!=0){
        table[n-j-1][i+j+1]=count;
        count++;
      }
      else{
        table[i+j+1][n-j-1]=count;
        count++;
      }
    }
  }
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      printf("%d ",table[n-i-1][j]);
    }
    printf("\n");
  }
}

void prnt4(int n){
  int i,j,table[n][n],count=1;
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      table[i][j]=1;
    }
  }
  for (i=0;i<(n+1)/2;i++){
    for (j=0;j<n-1-(2*i);j++){
      table[j+i][i]=count;
      count++;
    }
    for (j=0;j<n-1-(2*i);j++){
      table[n-i-1][j+i]=count;
      count++;
    }
    for (j=0;j<n-1-(2*i);j++){
      table[n-i-j-1][n-i-1]=count;
      count++;
    }
    for (j=0;j<n-1-(2*i);j++){
      table[i][n-j-i-1]=count;
      count++;
    }
  }
  if (n%2!=0){
    table[n/2][n/2]=count;
  }
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      printf("%d ",table[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int n,i,type;
  scanf("%d %d",&n,&type);
  if (type==1){
    prnt1(n);
  }
  if (type==2){
    prnt2(n);
  }
  if (type==3){
    prnt3(n);
  }
  if (type==4){
    prnt4(n);
  }
  return 0;
}