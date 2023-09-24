#include <stdio.h>
#include <stdlib.h>
void findStats(int *nums,int n,double *avg,int *maxi,int *mini) {
// Write your code here
  int max=nums[0],min=nums[0],i;
  float sum=0;
  for (i=0; i<n; i++){
    if (nums[i]>=max){
      max=nums[i];
    }
    if (nums[i]<min){
      min=nums[i];
    }
    sum+=nums[i];
  }
  *avg=sum/n;
  *maxi=max;
  *mini=min;
}
int main() {
  int n, i, maxi, mini;
  double avg;
  int *nums;
  
  scanf("%d", &n);
  nums = (int *)malloc(sizeof (int) *n);
  for (i=0; i<n; i++){
    scanf("%d", nums+i);
  }
  findStats(nums,n,&avg,&maxi,&mini);
  printf("%.2f %d %d", avg, maxi, mini);
  return 0;
}