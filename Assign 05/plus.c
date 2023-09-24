#include <stdio.h>
#include <string.h>

typedef struct numbers {
  int digits[10000];
  int size;
} numbers_t;

void zeronum(numbers_t *num){
  for (int i=0;i<10000;i++){
    num->digits[i] = 0;
  }
  num->size=0;
}

void getnum(numbers_t *num){
  char input[10000];
  scanf("%s",input);
  num->size=strlen(input);
  for (int i=0;i<num->size;i++){
    num->digits[i]=input[num->size-i-1]-'0';
  }
}

void sumnum(numbers_t *num1,numbers_t *num2,numbers_t *ans){
  int carry=0;
  for (int i=0;i<num1->size || i<num2->size;i++){
    int sum = num1->digits[i] + num2->digits[i] + carry;
    carry=sum/10;
    sum%=10;
    ans->digits[i] = sum;
    ans->size++;
  }
  if (carry){
    ans->digits[ans->size] = 1;
    ans->size++;
  }
}

void printnum(numbers_t *num){
  for (int i=0;i<num->size;i++){
    printf("%d",num->digits[num->size-i-1]);
  }
}

int main(void) {
  numbers_t num1,num2,ans;
  zeronum(&num1);
  zeronum(&num2);
  zeronum(&ans);
  getnum(&num1);
  getnum(&num2);
  sumnum(&num1,&num2,&ans);
  printnum(&ans);
  return 0;
}