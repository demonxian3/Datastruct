#include <stdio.h>
#include <stdlib.h>

int Fibonacci(long long *arr,int n){

  if( n == 1 || n == 2){
    arr[1] = 1;
    if(n == 2)arr[n] = 1;
    return 0;
  }
  
  arr[1] = arr[2] = 1;
   
  int i;
  for(i=3; i<=n; i++)
    arr[i] = arr[i-1] + arr[i-2];

  return 0;
}



int main(){
  int i,num;

  printf("enter number for fibonacci:");
  scanf("%d",&num);

  if(num<=0){
    printf("Invalid input number\n");
    return -2;
  }

  long long arr[num+1];
  Fibonacci(arr,num);

  for(i=1; i<=num; i++)
    printf("%ld ",arr[i]);
}
