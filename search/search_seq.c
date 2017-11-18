#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
#define TRUE 1
#define FALSE 0

typedef int KeyType;
typedef struct {
  KeyType key;
  //other data
}ElemType;



void createTestData(ElemType *data,int n){
  int i,value;
  
  for(i=1;i<=n;i++){			//保留
    printf("[%d]Input Value: ",i);
    scanf("%d",&value);
    data[i].key = value;
  }
}

int search_seq(ElemType *data,KeyType key,int n){
  int i;
  data[0].key = key;
  for(i=n;data[i].key!=key;i--);
  return i;
}

int main(){
  int i,n,key,res;
  ElemType data[MAXNUM];
  printf("Enter the num of data: ");
  scanf("%d",&n);
  createTestData(data,n);
  //debug
  for(i=1;i<=n;i++)
    printf("%d \n",data[i].key);
 
  printf("Enter the key value: ");
  scanf("%d",&key);

  res = search_seq(data,key,n); 
  if(!res){
    printf("Sorry the key was not found!\n");
  }else{
    printf("Found it,the key's index is %d\n",res);
  }
  return 0;
}
