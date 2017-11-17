#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXNUM 20

typedef int KeyType;
typedef struct {
  KeyType key;
}ElemType;

void createTestData(ElemType *data,int n){
  int i;
  for(i=1;i<=n;i++){
    printf("[%d]Enter the value: ",i);
    scanf("%d",&data[i].key);
  }
}

int search_bin(ElemType *data,KeyType key,int n){
  int low,high,mid;

  low = 1;
  high = n;
  mid = (low+high)/2;
  
  while(data[mid].key!=key){
    if(key<data[mid].key)
      high = mid - 1;
    else
      low = mid + 1;

    mid = (low+high)/2;
    //can't use the "low<=mid||high<=low", 
    //because it exclude the boundary element
    if(high<low)          
      return 0;
   
  }
  
  return mid;
}

int main(){
  int i,n,key,res;
  ElemType data[MAXNUM];
  printf("Enter the number of key: ");
  scanf("%d",&n);
  
  createTestData(data,n);

  for(i=1;i<=n;i++)
    printf("[%d]: %d \n",i,data[i].key);

  while(1){
    printf("Enter the key value: ");
    scanf("%d",&key);
    
    res = search_bin(data,key,n);
    if(!res)
      printf("Sorry, the key was not found\n");
    else
      printf("Found it,the key's index is:%d\n",res);
  }
}

