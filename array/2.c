#include <stdio.h>
#include <stdlib.h>

void fun(char **str,int m,int n){
   int i,j;
   printf("[para]:");
   for(i=0;i<m;i++)
     for(j=0;j<n;j++)
       printf("%c ",*(*(str+i)+j));

   printf("\n");
}

int main(){ 
 
  /*
  动态数组形式：二维数组在堆上分配，
  各行地址空间不一定连续，函数参数使用指针形式
  */ 

  int i,j;
  int m = 3;  //rows
  int n = 3;  //cols
  char **str;
  str = (char**)malloc(m*sizeof(char*));

  for(i=0;i<m;i++)
    str[i] = (char*)malloc(n*sizeof(char));

  //assign
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      *(*(str+i)+j) = (char)97+i+j;

  //visit
  printf("[visit]:");
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      printf("%c ",*(*(str+i)+j)); //cannot use *(str + i*n +j)
  printf("\n");

  //parameter
  fun(str,m,n);
  return 0;
}
