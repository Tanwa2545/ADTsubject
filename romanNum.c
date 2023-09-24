#include <stdio.h>
int main(void) {
  int line,num,a,i,j;
  char str[1];
  scanf("%d",&line);
  for (i=0;i<line;i++){
    scanf("%d",&num);
    if (num>=1000){
      a=num/1000;
      if (a>0){
        for (j=0;j<a;j++){
          printf("M");
        }
      }
      num-=a*1000;
    }
    if (num>=100){
      a=num/100;
      if (a==9)
        printf("CM");
      else if (a==8)
        printf("DCCC");
      else if (a==7)
        printf("DCC");
      else if (a==6)
        printf("DC");
      else if (a==5)
        printf("D");
      else if (a==4)
        printf("CD");
      else if (a==3)
        printf("CCC");
      else if (a==2)
        printf("CC");
      else if (a==1)
        printf("C");
    num-=a*100;
    }
    if (num>=10){
      a=num/10;
      if (a==9)
        printf("XC");
      else if (a==8)
        printf("LXXX");
      else if (a==7)
        printf("LXX");
      else if (a==6)
        printf("LX");
      else if (a==5)
        printf("L");
      else if (a==4)
        printf("XL");
      else if (a==3)
        printf("XXX");
      else if (a==2)
        printf("XX");
      else if (a==1)
        printf("X");
    num-=a*10;
    }
    if (num>=1){
      a=num;
      if (a==9)
        printf("IX");
      else if (a==8)
        printf("VIII");
      else if (a==7)
        printf("VII");
      else if (a==6)
        printf("VI");
      else if (a==5)
        printf("V");
      else if (a==4)
        printf("IV");
      else if (a==3)
        printf("III");
      else if (a==2)
        printf("II");
      else if (a==1)
        printf("I");
    }
    printf("\n");
  }
}