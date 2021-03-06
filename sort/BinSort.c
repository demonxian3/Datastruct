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


void BinSort(Sqlist *L){
  int i,j;
  int low,mid,high;
  int len = L->length;

  for(i=2; i<=len; i++){
    low=1;
    high=i-1;

    L->data[0].key = L->data[i].key;

    while(low<=high){
      mid = (high+low)/2;
      if(L->data[i].key < L->data[mid].key)
        high = mid - 1;
      else
        low = mid + 1;		//this can prevent loop when equal
    }

    for(j=i; j>low; j--){
      L->data[j].key = L->data[j-1].key;
    }

    L->data[low].key = L->data[0].key;
  }
  return ;
}
int main(){
  
  int i;
  Sqlist L;  
  
  printf("*** BinSort ***\nInput key's number:");
  scanf("%d",&L.length);
  
  for(i=1;i<=L.length;i++){
     printf("input key[%d]:",i);
     scanf("%d",&L.data[i].key);
  }

  BinSort(&L);

  for(i=1;i<=L.length;i++)
     printf("[%d] ",L.data[i].key);
  printf("\n");
  return 0;
}
