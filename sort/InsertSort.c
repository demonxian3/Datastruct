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


int InsertSort(Sqlist *L){
  int i,j;
  int len = L->length;
  int count = 0;

  for(i=2; i<=len; i++){
    if( L->data[i].key < L->data[i-1].key ){
      L->data[0].key = L->data[i].key;

      for(j=i; L->data[0].key < L->data[j-1].key; j--){
         L->data[j].key = L->data[j-1].key;  //KEY[i] = KEY[i-1] pre-move one
         count++;
      }

      L->data[j].key = L->data[0].key;
    }
  }

  return count;

}

int main(){
 
  Sqlist L;  

  printf("*** InsertSort ***\nInput key's number:");
  scanf("%d",&L.length);
  
  for(int i=1;i<=L.length;i++){
     printf("input key[%d]:",i);
     scanf("%d",&L.data[i].key);
  }

  int n = InsertSort(&L);

  for(int i=1;i<=L.length;i++)
     printf("[%d] ",L.data[i].key);
  printf("\n");
  
  printf("count:%d\n",n);
  return 0;
}