#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100


typedef int KeyType;
typedef struct {
  KeyType key;
} DataType;
typedef struct {
  DataType data[MAXSIZE + 1];  //place the sentry
  int length;
} Sqlist;


int SelectSort(Sqlist *L){
  int i,j;
  int min;
  int len = L->length;
  int count = 0;

  for(i=1; i<=len; i++){
    min = i;			//min记录最小关键字的索引
 
    for(j=i+1; j<=len; j++){
      count++;
      if(L->data[j].key < L->data[min].key)	//寻找位排序序列最小值
        min = j;
    }
 
    if(min != i){				//最小值与头部交换值
      int tmp = L->data[min].key;
      L->data[min].key = L->data[i].key;
      L->data[i].key = tmp;
    }
  }

  return count;

}

int main(){
 
  Sqlist L;  

  printf("*** SelectSort ***\nInput key's number:");
  scanf("%d",&L.length);
  
  for(int i=1;i<=L.length;i++){
     printf("input key[%d]:",i);
     scanf("%d",&L.data[i].key);
  }

  int n = SelectSort(&L);

  for(int i=1;i<=L.length;i++)
     printf("[%d] ",L.data[i].key);
  printf("\n");
  
  printf("count:%d\n",n);
  return 0;
}
