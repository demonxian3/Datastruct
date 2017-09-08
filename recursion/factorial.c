#include <stdio.h>
#include <stdlib.h>

int Fac(int num){
  if(num<=1)return 1;
  return num * Fac(num-1);
}

int main(){
  int num;
  printf("enter a num:");
  scanf("%d",&num); 
  printf("Factorial is %d\n",Fac(num));
}
