#include <stdio.h>

int fun(char *str,int m,int n){
   int i,j;
   for(i=0;i<m;i++){
    printf("[para]:");
     for(j=0;j<n;j++)
       printf("%c ",*(str+i*n+j));
     printf("\n");
   }
}

int main(){
/*
　　静态数组形式：二维数组在栈上分配，
　　各行地址空间连续，传递函数参数转成指针
*/
  //  [initialization]
  char str[][3] = {"abc","efg","hij"};

  //  [visit]
  
  int i,j;
  for(i=0;i<3;i++){
    printf("[visit1]:");
    for(j=0;j<3;j++)
      printf("%c ",*(*(str+i)+j));
    printf("\n");
  }

  //  [visit]
  for(i=0;i<3;i++){ 
    printf("[visit2]:");
    for(j=0;j<3;j++)
      printf("%c ",str[i][j]);
    printf("\n");
  }


  printf("arr[1][4]: %c\n",*(*(str+1)+4));

  /*
　　这种分配是在栈上进行的，能够保证所有元素的地址空间连续。
　　所以array[i][j] 和 *(*(array +i) +j)是一样的，
　　程序是知道array+i的i实际上偏移了i*N个单位，
　　这也导致了在二维数组array[3][3]中，
　　使用下标array[2][1]和array[1][4]是访问的同一个元素，
　　尽管后者的下标对于一个3*3矩阵来说是非法的，但这并不影响访问
  */


  //  [rows_length]
  int len = sizeof(str)/sizeof(str[0]);
  

  //  [parameter]
  /*
    不能使用str作为参数，而需使用*str作参数，因为：
    当把这种二维数组的指针直接作为参数传递时，数组名退化为指针，
    函数并不知道数组的列数，N对它来说是不可见的，即使使用*(*(array +i) +j)，
    第一层解引用失败。这时，编译器会报warning，运行生成的文件会发生segment fault。
    那么，为了指导这个函数如何解引用，也就是人为地解引用，
    数组实际类型是int [3][3]，在作为右值时可以被转化为int (*)[3]，它们都和int **不同，自然不可用。
    需要把这个二维数组的首元素地址传给函数，于是就变成了下面的形式：
  */	

  fun(*str,len,3);

  return 0;
}

