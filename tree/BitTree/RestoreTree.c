#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

BitTree RestoreTree(char *pre,char *in,int n){
  if(n<=0)return NULL;
  BitTree T = (BitTree)malloc(sizeof(BitNode));
  T->data = *pre;
  char *p = in;
  while(p<(in+n-1) && *p!=*pre)  //find root from "IN"
    p++;

  int k = p - in;              //calc the num of lchild
  T->lchild = RestoreTree(pre+1,in,k);
  T->rchild = RestoreTree(pre+k+1,p+1,n-k-1);
  return T;
}

void postOrder(BitTree T){
  if(T){
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c",T->data);
  }
}

int main(){
  int num;
  char *pre =(char*)malloc(100*sizeof(char));
  char *in  =(char*)malloc(100*sizeof(char));

  num = 7;
  pre = "ABDECFG\0";
  in  = "DBEAFCG\0";

  BitTree T = RestoreTree(pre,in,num);
  postOrder(T);
  printf("\n");
  
  return 0;
}
