#include <stdio.h>
#include <stdlib.h>

long long Fibonacci(int n){
  if(n == 1 || n == 2)return  1;
  else
    return  Fibonacci(n-1) + Fibonacci(n-2);
}



int main(){
  int i,num;
  printf("enter number for fibonacci:");
  scanf("%d",&num);
  if(num<=0){
    printf("Invalid input number\n");
    return -2;
  }
  
  printf("result: %ld\n",Fibonacci(num));
}
