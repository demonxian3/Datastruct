#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}

void echo(int a){
  printf("%d",a);
  return;
}

void output(int n,int arr[]){
  int i,j;
  for(i=1;i<=n;i++){

    //print
    for(j=1;j<=n;j++){
      printf("%d ",arr[j]);
    }
    printf("\n");

    //swap
    if(i==n)swap(&arr[i],&arr[1]);
    else swap(&arr[i],&arr[i+1]);

  }
  
  int tag = 1;
  for(i=1;i<=n;i++)
    if(arr[i]!=i){tag=0;break;}

  if(tag)return;

  output(n,arr);
}

int main(){
  int i;
  int n,arr[MAX];
  printf("enter a num:");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    arr[i]=i;

  output(n,arr);
  return 0;
}
