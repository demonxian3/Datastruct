#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

void createTree(BitTree T){
  char ch;
  ch=getchar();
  if(ch==' ')T=NULL;
  else{
    T=(BitTree)malloc(sizeof(BitNode));
    T->data = ch;
    createTree(T->lchild);
    createTree(T->rchild);
  }
  return;
}

int main(){
  BitTree T;
  createTree(T);
  return 0;
}
