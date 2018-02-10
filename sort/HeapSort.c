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

int SIFT(Sqlist *H, int i, int m){
  int j,tmp,count=0;
  tmp = H->data[i].key;			//record Head-top
  
  for(j=2*i; j<=m; j*=2){
    count++;
    if(j<m && H->data[j].key > H->data[j+1].key ) //minc = lc > rc ? rc : lc;
      j++;

    if( tmp < H->data[j].key )break;	//Heap-top < minc ? no adjust : need adjust;

    H->data[i].key = H->data[j].key;	//swap Heap-top and minc
    i=j;				//record minc-index
  }

  H->data[i].key = tmp;			//Insert value to minc-index;
  return count;
}

int HeapSort(Sqlist *H){
  int i,j;
  int tmp;
  int len = H->length;
  int count = 0;

  for(i=(len/2); i>0; i--){	//built Init-Heap
    count += SIFT(H,i,len);
  }

  for(i=len; i>1; i--){		
    tmp = H->data[1].key;	//swap Heap-top and Heap-last
    H->data[1].key = H->data[i].key;
    H->data[i].key = tmp;
    count += SIFT(H,1,i-1);	//adjust to Heap
  }
  
  return count;
}

int main(){
 
  Sqlist L;  

  printf("*** HeapSort ***\nInput key's number:");
  scanf("%d",&L.length);
  
  for(int i=1;i<=L.length;i++){
     printf("input key[%d]:",i);
     scanf("%d",&L.data[i].key);
  }

  int n = HeapSort(&L);

  
  for(int i=L.length;i>0;i--)
     printf("[%d] ",L.data[i].key);
  printf("\n");
  
  printf("count:%d\n",n);
  return 0;
}
