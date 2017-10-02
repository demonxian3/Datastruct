#include <stdio.h>
#include <stdlib.h>

void fun(char *str,int m,int n){
  
  int i,j;
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      printf("%c ",*(str+i*n+j));
}

int main(){
  /*
   用堆上分配的一维数组表示二维数组，函数参数使用指针形式
  */

  int i,j,m,n;
  m=n=3;
  char *str = (char*)malloc(m*n*sizeof(char));

  //assign
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    *(str+i*n+j) = (char)97+(i*n+j);

  fun(str,m,n);
 
  return 0;
}
