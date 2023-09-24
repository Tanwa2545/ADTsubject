#include <stdio.h>
int main(void) {
  int l,i=0,j=0;
  char dir;
  scanf("%c %d",&dir, &l);
  if (dir=='N'){
    for (i=0;i<=l;i++){
      for (j=0;j<l-i;j++){
        printf(" ");
      }
      for (j=0;j<=2*i;j++){
        printf("#");
    }
    printf("\n");
    }
    for (i=0;i<=l;i++){
      printf(" ");
      for (j=0;j<2*l-1;j++){
        printf("#");
      }
      printf("\n");
    }
  }
  else if (dir=='S'){
    for (i=0;i<=l;i++){
      printf(" ");
      for (j=0;j<2*l-1;j++){
        printf("#");
      }
      printf("\n");
    }
    for (i=0;i<=l;i++){
      for (j=0;j<i;j++){
        printf(" ");
      }
      for (j=0;j<=(l-i)*2;j++){
        printf("#");
      }
      printf("\n");
    }
  }
  else if (dir=='E'){
    for (i=0;i<=l;i++){
      printf(" ");
    }
    printf("#\n");
    for (i=0;i<l;i++){
      for (j=0;j<=i+l+2;j++){
        printf("#");
      }
      printf("\n");
    }
    for (i=0;i<l-1;i++){
      for (j=0;j<=2*l-i;j++){
        printf("#");
      }
      printf("\n");
    }
    for (i=0;i<=l;i++){
      printf(" ");
    }
    printf("#\n");
  }
  else if (dir=='W'){
    for (i=0;i<l;i++){
      printf(" ");
    }
    printf("#\n");
    for (i=0;i<l;i++){
      for (j=0;j<l-1-i;j++){
      printf(" ");
      }
      for (j=0;j<=i+l+2;j++){
        printf("#");
      }
      printf("\n");
    }
    for (i=0;i<l-1;i++){
      for (j=0;j<=i;j++){
        printf(" ");
      }
      for (j=0;j<=2*l-i;j++){
        printf("#");
      }
      printf("\n");
    }
    for (i=0;i<l;i++){
      printf(" ");
    }
    printf("#\n");
  }
  return 0;
}