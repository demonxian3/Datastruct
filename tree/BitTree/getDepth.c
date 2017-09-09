#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

void create(BitTree T,ElemType e,BitTree lc,BitTree rc){
  T->data = e;
  T->lchild = lc;
  T->rchild = rc;
  return ;
}

int getDepth(BitTree T){
  if(T==NULL){
    return 0;
  }else{
    if(getDepth(T->lchild) >= getDepth(T->rchild)) 
      return 1 + getDepth(T->lchild);
    else
      return 1 + getDepth(T->rchild);
  }
}

int main(){
   //create Tree;
   BitTree root = (BitTree)malloc(sizeof(BitNode));
   BitTree node1 = (BitTree)malloc(sizeof(BitNode));
   BitTree node2 = (BitTree)malloc(sizeof(BitNode));
   BitTree leaf1 = (BitTree)malloc(sizeof(BitNode));
   BitTree leaf2 = (BitTree)malloc(sizeof(BitNode));
   BitTree leaf3 = (BitTree)malloc(sizeof(BitNode));
   BitTree leaf4 = (BitTree)malloc(sizeof(BitNode));
   BitTree leaf6 = (BitTree)malloc(sizeof(BitNode));
   BitTree leaf7 = (BitTree)malloc(sizeof(BitNode));
   BitTree leaf8 = (BitTree)malloc(sizeof(BitNode));
   BitTree leaf9 = (BitTree)malloc(sizeof(BitNode));

   create(leaf9,77,NULL,NULL);
   create(leaf6,77,NULL,NULL);
   create(leaf7,77,NULL,NULL);
   create(leaf8,77,leaf9,NULL);
   create(leaf1,32,NULL,NULL);
   create(leaf2,44,NULL,leaf8);
   create(leaf3,39,leaf6,NULL);
   create(leaf4,30,leaf7,NULL);
   create(node1,51,leaf1,leaf2);
   create(node2,72,leaf3,leaf4);
   create(root,12,node1,node2);

   int dep = getDepth(root);
   printf("%d\n",dep);
  return 0;
}
