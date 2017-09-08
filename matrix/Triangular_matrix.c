#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define OK 1


typedef int ElemType;
typedef int Status;
typedef struct{
  ElemType *base;
  int index[2];
}Array;

Status initArray(Array *A,int i,int j){
  if(i<0 || j<0)return ERROR;
  A->index[0] = i;
  A->index[1] = j;
  int total = i*(i+1)/2;  //only requires a half of Memery Area
  A->base = (ElemType*)malloc(total * sizeof(ElemType));
  return OK;
}

Status Value(Array A,ElemType *e,int i,int j){
  if(i<0 || i>A.index[0] || j<0 || j>A.index[0])return ERROR;
  //mapping relation: k=i(i-1)/2+j (i>=j) 
  if(i>=j){
    int k =  i*(i+1)/2+j;
    *e = *(A.base + k);  
  }else{
    *e = 0;
  }
  return OK;
}

Status Assign(Array *A,ElemType e,int i,int j){
  if(i<0 || i>A->index[0] || j<0 || j>A->index[0])return ERROR;
  //mapping relation: k=i(i-1)/2+j (i>=j) 
  int k = i>=j?i*(i+1)/2+j:j*(j+1)/2+i;
  *(A->base + k) = e;
  return OK;
}

Status Print(Array A){
  
  int i,j,t;
  for(i=0;i<A.index[0];i++){
    for(j=0;j<A.index[1];j++){
      Value(A,&t,i,j);
      printf("[%d]\t",t);
    }
    printf("\n");
  }
  
  return OK;
}


int main(){
  Array A;
  initArray(&A,5,5);

  Assign(&A,11,0,0);
  Assign(&A,21,1,0);
  Assign(&A,22,1,1);
  Assign(&A,31,2,0);
  Assign(&A,32,2,1);
  Assign(&A,33,2,2);
  Assign(&A,41,3,0);
  Assign(&A,42,3,1);
  Assign(&A,43,3,2);
  Assign(&A,44,3,3);
  Assign(&A,51,4,0);
  Assign(&A,52,4,1);
  Assign(&A,53,4,2);
  Assign(&A,54,4,3);
  Assign(&A,55,4,4);
  Print(A);
  
  return 0;
}
