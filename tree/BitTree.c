#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//binary linked struct
typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;


//preorder traverse
void preOrder(BitTree T){
  if(T){
    visit(T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
  }
  return;
}

void visit(ElemType e){
  printf("%d\n",e);
  return;
}

int main(){
  BitTree T;
  
  return 0;
} 
