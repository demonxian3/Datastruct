#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXNUM 20

typedef int KeyType;
typedef struct {
  KeyType key;
  //other data
}ElemType;

typedef struct {
  ElemType *elem;
  int length;
}Stable;


void createTestData(Stable *ST,int n){
  int i,val;
  ST->elem = (ElemType *)malloc(n *sizeof(ElemType));
  ST->length = n;
  for(i=1;i<=n;i++){
    printf("[%d]input value: ",i);
    scanf("%d",&val);
    ST->elem[i].key = val;
  }

  //output and debug
  for(i=1;i<=n;i++)
    printf("[%d] %d\n",i,ST->elem[i].key);
}

int search_bin(Stable ST,KeyType key){
  
  int low = 1;
  int len = ST.length;
  int high = len;
  
  while(low<=high){               //include '=',because match boundary element.
    int mid = (low+high)/2;
    if(key == ST.elem[mid].key){   //found it
      return mid;
    }
    else if(key < ST.elem[mid].key)  //before area
      high = mid-1;
    else
      low = mid+1;
  }
  
  return 0;
}

int main(){
  int n,r,k;
  Stable ST;

  printf("Enter the number of key: ");
  scanf("%d",&n);
  createTestData(&ST,n);

  while(1){
    printf("Enter the key value for search: ");
    scanf("%d",&k);

    if(!(r = search_bin(ST,k)))
      printf("Sorry,the key is not found\n");
    else
      printf("Found it,the key's index is:%d\n",r);
  }
  return 0;
}

