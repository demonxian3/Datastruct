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

//This is three diagonal matrix
Status initArray(Array *A,int i,int j){
  if(i<0 || j<0)return ERROR;
  A->index[0] = i;
  A->index[1] = j;
  int total = 3*i-2;  
  A->base = (ElemType*)malloc(total * sizeof(ElemType));
  return OK;
}

Status Value(Array A,ElemType *e,int i,int j){
  if(i<0 || j<0 || j>=A.index[1] || i>=A.index[0])return ERROR;
  //mapping relation: k=2*i+j
  if(j>=i-1 && j<=i+1){
    int k = 2*i+j;
    *e = *(A.base + k);  
  }else{
    *e = 0;
  }
  return OK;
}

Status Assign(Array *A,ElemType e,int i,int j){
  if(i<0 || j<0 || j>i+1 || j<i-1 || i>=A->index[0])return ERROR;
  //mapping relation: k=i(i-1)/2+j (i>=j) 
  int k = 2*i+j;
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
  Assign(&A,12,0,1);
  Assign(&A,21,1,0);
  Assign(&A,22,1,1);
  Assign(&A,23,1,2);
  Assign(&A,32,2,1);
  Assign(&A,33,2,2);
  Assign(&A,34,2,3);
  Assign(&A,43,3,2);
  Assign(&A,44,3,3);
  Assign(&A,45,3,4);
  Assign(&A,54,4,3);
  Assign(&A,55,4,4);
  Assign(&A,31,3,1);
  Print(A);
  
  return 0;
}
