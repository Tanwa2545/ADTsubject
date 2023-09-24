#include <stdio.h>

int planner(int w,int h){
  if (w<=0 || h<=0)
    return 0;
  int i=1;
  while (i*2<=w && i*2<=h){
    i*=2;
  }
  if (w==1 && h==1)
    return 1;
  if (w==1)
    return h;
  if (h==1)
    return w;
  else
    return planner(w-i,h)+planner(i,h-i)+1;
}

int main(void) {
  int w,h,x;
  scanf("%d %d",&w,&h);
  x=planner(w,h);
  printf("%d",x);
  return 0;
}
// big-o notation is O((log(min(w,h))^2))