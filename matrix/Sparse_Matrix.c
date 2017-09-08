#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAX 1024

typedef int Status;
typedef int ElemType;
typedef struct{
  int i,j;
  ElemType v;
}Triple;
typedef struct{
  Triple data[MAX];
  int mu,nu,tu;
}TSMatrix;

Status createMatrix(TSMatrix *M,int *A,int m,int n){
  int k=0, col=0, row=0;
 
  for(row=0;row<m;row++){
    for(col=0;col<n;col++){
      if(*(A+(row*n)+col)){
        M->data[k].i = row;
        M->data[k].j = col;
        M->data[k].v = *(A+(row*n)+col);
        ++k;
      }
    }
  }

  M->mu = m;
  M->nu = n;
  M->tu = k;
  return OK;
}

Status Simple_Transpose(TSMatrix M,TSMatrix *T){
  int col=0, k=0, p=0;
  
  if(M.tu){
    for(col=0;col<M.nu;col++){
      for(k=0;k<M.tu;k++){
        if(M.data[k].j == col){
          T->data[p].i = M.data[k].j;
          T->data[p].j = M.data[k].i;
          T->data[p].v = M.data[k].v;
          p++;
        }
      }
    }
  }

  T->mu = M.nu;
  T->nu = M.mu;
  T->tu = M.tu;
  return OK;
}

Status Fast_Transpose(TSMatrix M,TSMatrix *T){
  int col=0, row=0, k=0 ,p;
  int num[M.nu];
  int cpot[M.nu];
  
  if(M.tu){
    for(col=0;col<M.nu;col++){  //clear num[]
      num[col]=0;
    }

    for(k=0;k<M.tu;k++){
      num[M.data[k].j]++;
    }
 
    //cpot[i] = cpot[i-1] + num[i-1] (i>0)
    cpot[0] = 0;
    for(col=1;col<M.nu;col++){
      cpot[col] = cpot[col-1] + num[col-1];
    }

    for(k=0;k<M.tu;k++){
      col = M.data[k].j;
      p = cpot[col];
      T->data[p].i = M.data[k].j;
      T->data[p].j = M.data[k].i;
      T->data[p].v = M.data[k].v;
      cpot[col]++;
    }
  }
  
  T->mu = M.nu;
  T->nu = M.mu;
  T->tu = M.tu;
  return OK;
}

Status Print(TSMatrix M){
  int k=0, col=0, row=0;
  
  for(row=0;row<M.mu;row++){
    for(col=0;col<M.nu;col++){
      if(M.data[k].i==row && M.data[k].j==col){
        printf(" [%d]\t",M.data[k].v);
        ++k;
      }else{
        printf(" [0]\t");
      }
    }
    printf("\n");
  }
  return OK;
}

int main(){

  int arr[][6]={
    {1,0,0,2,0,1},
    {0,2,0,3,1,0},
    {0,0,0,0,0,3},
    {4,0,1,0,0,2},
    {0,3,4,3,0,0},
  };

  TSMatrix M;
  TSMatrix T;
  createMatrix(&M,*arr,5,6);
  Fast_Transpose(M,&T);
  //Simple_Transpose(M,&T);
  Print(M);
  printf("\n\n");
  Print(T);
  return OK;
}
