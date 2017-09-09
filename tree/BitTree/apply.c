#include <stdio.h>
#include <stdlib.h>

//打印树中度为2的节点
typedef int ElemType;
typedef struct BitNode{
  ElemType data;
  struct  BitNode *lchild,*rchild; 
}BitNode,*BitTree;

void visit(ElemType e){
  printf("%d ",e);
  return;
}

void order(BitTree T){
   if(T){
     order(T->lchild);
     if(T->lchild && T->rchild)
       visit(T->data);
     order(T->rchild);
   }
   return;
}

void create(BitTree T,ElemType e,BitTree lc,BitTree rc){
  T->data = e;
  T->lchild = lc;
  T->rchild = rc;
  return;
}

int main(){
  
  //create Tree;
  BitTree root = (BitTree)malloc(sizeof(BitNode));
  BitTree leaf1 = (BitTree)malloc(sizeof(BitNode));
  BitTree leaf2 = (BitTree)malloc(sizeof(BitNode));
  BitTree leaf3 = (BitTree)malloc(sizeof(BitNode));
  BitTree node1 = (BitTree)malloc(sizeof(BitNode));
  BitTree node2 = (BitTree)malloc(sizeof(BitNode));

  create(leaf1,32,NULL,NULL);
  create(leaf2,44,NULL,NULL);
  create(leaf3,39,NULL,NULL);
  create(node1,51,leaf1,leaf2);
  create(node2,72,leaf3,NULL);
  create(root,12,node1,node2);

  order(root);
  return 0;
}
