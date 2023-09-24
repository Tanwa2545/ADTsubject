#include <stdio.h>
typedef struct datetime {
  int date; // 1-31
  int month; // 1-12
  int year; // 1970++
  int dayOfWeek; // 0-6
  int hour; // 0-23
  int minute; // 0-59
  int second; // 0-59
} datetime_t;

int isleap(int y){
  if ((y%4==0 && y%100!=0) || (y%400==0))
    return 1;
  else
    return 0;
}
datetime_t createDate(int t) {
// Write your code here
  datetime_t result;
  int nom[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int year=1970,tday=1,i=0;
  result.second = t%60;
  result.minute = (t/60)%60;
  result.hour = (t/3600)%24;
  tday += t/86400;
  result.dayOfWeek = (2+tday)%7;
  while (tday>=365){
    if (isleap(year))
      tday-=366;
    else
      tday-=365;
    year+=1;
  }
  while (tday>nom[i]){
    if (isleap(year) && nom[i]==28)
      tday-=1;
    tday-=nom[i];
    i++;
  }
  result.year = year;
  result.month = i;
  result.date = tday;
  return result;
}
void printDate(datetime_t dt) {
// Write your code here
  char* moty[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
  char* dotw[] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
  printf("%s ",dotw[dt.dayOfWeek]);
  printf("%d ",dt.date);
  printf("%s ",moty[dt.month]);
  printf("%d ",dt.year);
  printf("%02d:%02d:%02d",dt.hour,dt.minute,dt.second);
}

int main(void) {
  datetime_t inputDate;
  int timestamp;
  scanf("%d", &timestamp);
  inputDate = createDate(timestamp);
  printDate(inputDate);
  return 0;
}