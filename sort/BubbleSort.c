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


void BubbleSort(Sqlist *L){
  int i,j;
  int tmp;
  int len = L->length;

  for(i=1; i<=len; i++){
    for(j=len; j>i; j--){			//从尾开始两两比较，小的放前
      if(L->data[j].key < L->data[j-1].key){	//如果后一个小于前一个，交换
        tmp = L->data[j].key;
        L->data[j].key = L->data[j-1].key;
        L->data[j-1].key = tmp;
      }
    }
  }
  return ;

}

int main(){
 
  Sqlist L;  

  printf("*** BubbleSort ***\nInput key's number:");
  scanf("%d",&L.length);
  
  for(int i=1;i<=L.length;i++){
     printf("input key[%d]:",i);
     scanf("%d",&L.data[i].key);
  }

  BubbleSort(&L);

  for(int i=1;i<=L.length;i++)
     printf("[%d] ",L.data[i].key);
  printf("\n");
  
  return 0;
}
