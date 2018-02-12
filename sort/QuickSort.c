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


void QuickSort(Sqlist *L,int low,int high){
  int i,j;
  int len = L->length;
  int pivotkey;

  i=low;
  j=high;
  pivotkey = L->data[0].key = L->data[i].key;

  while(i<j){
    while(i<j && L->data[j].key >= pivotkey )
      j--;
    L->data[i].key = L->data[j].key;
    
    while(i<j && L->data[i].key <= pivotkey )
      i++;
    L->data[j].key = L->data[i].key;
  }

  L->data[i].key = L->data[0].key;

  if(low < i )  QuickSort(L,low,i-1); 
  if(j < high) QuickSort(L,j+1,high);
}

int main(){
  int i;
  Sqlist L;  

  printf("*** QuickSort ***\nInput key's number:");
  scanf("%d",&L.length);
  
  for(i=1;i<=L.length;i++){
     printf("input key[%d]:",i);
     scanf("%d",&L.data[i].key);
  }

  QuickSort(&L,1,L.length);

  for(i=1;i<=L.length;i++)
     printf("[%d] ",L.data[i].key);
  printf("\n");
  
  return 0;
}
