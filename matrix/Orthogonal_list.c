#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct Onode{
  int i,j;
  ElemType v;
  struct Onode *right,*down;
}Onode,*Olink;

typedef struct{
  Olink *rhead,*chead;  //head array;
  int mu,nu,tu;
}Crosslist;

Status createMatrix(Crosslist *M){
  
  int i,j;
  ElemType v;
  int m,n,t,k;
  int col,row;
  printf("please enter m,n,t:");
  scanf("%d%d%d",&m,&n,&t);

  M->mu = m;
  M->nu = n;
  M->tu = t;

  M->rhead = (Olink*)malloc(m*sizeof(Olink));
  M->chead = (Olink*)malloc(n*sizeof(Olink));
  
  //init rhead & chead
  for(row=0;row<m;row++)
    M->rhead[row]=NULL;

  for(col=0;col<n;col++)
    M->chead[col]=NULL;

  //begin input value;
  for(k=0;k<t;k++){
    printf("please enter i,j,v:");
    scanf("%d%d%d",&i,&j,&v);
 
    //create new node
    Olink new = (Olink)malloc(sizeof(Onode));
    new->i = i;
    new->j = j;
    new->v = v;
    new->down = NULL;
    new->right = NULL;

    //link the rhead & new node
    if(!M->rhead[i] || M->rhead[i]->j>j){
      new->right = M->rhead[i];
      M->rhead[i] = new;
    }else{
      Olink q = M->rhead[i];
      while(q->right && q->right->j<j)
        q = q->right;
  
      new->right = q->right;
      q->right = new;
    }
    
    //link the chead & new node
    if(!M->chead[j] || M->chead[j]->i>i){
      new->down = M->chead[j];
      M->chead[j] = new;
    }else{
      Olink q = M->chead[j];
      while(q->down && q->down->i<i)
        q = q->down;

      new->down = q->down;
      q->down = new;
    }
  }
  
  return OK; 
}

Status Print(Crosslist M){
  
  int k,row;
  int m = M.mu;
  int n = M.nu;
  int arr[m*n];
  
  //clear array
  for(k=0;k<m*n;k++)
    arr[k]=0;

  for(row=0;row<m;row++){
    Olink tmp = M.rhead[row];
    while(tmp!=NULL){
      *(arr + tmp->i*n + tmp->j) = tmp->v;
      tmp = tmp->right;
    }
  }
  
  for(k=0;k<m*n;k++){
    if(k%m==0)printf("\n");
    printf(" [%d]\t",arr[k]);
  }
  printf("\n");
  return OK;
}

Status Print2(Crosslist M){
  int col=0, row=0;
  
  for(row=0;row<M.mu;row++){

     Olink tmp = M.rhead[row];
     for(col=0;col<M.nu;col++){

        if(tmp->i==row && tmp->j==col){
          printf(" [%d]\t",tmp->v);
          if(tmp->right)tmp = tmp->right;
        }else{
          printf(" [0]\t");
        }

     }
     printf("\n");
  }
  return OK;
} 

int main(){
  Crosslist M;
  createMatrix(&M);
  Print2(M);
  return 0;
}
