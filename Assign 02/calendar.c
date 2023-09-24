#include <stdio.h>

int isleap(int y){
  if ((y%4==0 && y%100!=0) || (y%400==0))
    return 1;
  else
    return 0;
}
int main(void) {
  int year,month,strday = 1,i;
  char* moty[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int nom[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  printf("Enter year: ");
  scanf("%d",&year);
  printf("Enter month: ");
  scanf("%d",&month);
  printf("====================\n");
  printf("%s %d\n", moty[month-1], year);
  printf("Sun Mon Tue Wed Thu Fri Sat\n");
  for (i=0;year-i>1990;i++){
    if (isleap(year-i-1))
      strday+=2;
    else
      strday+=1;
  }
  for (i=0;i<month-1;i++){
    strday+=nom[i];
  }
  if (isleap(year) && (month>2))
    strday+=1;
  strday%=7;
  for (i=0;i<strday;i++){
    printf("    ");
  }
  i=0;
  while (i<nom[month-1]){
    if ((i+strday)%7==0){
      printf("\n");
    }
    printf("%3d ",i+1);
    if (i==27 && isleap(year) && month==2)
      printf("%3d ",i+2);
    i++;
  }
  return 0;
}