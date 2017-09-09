#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//binary linked struct
typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

void create(BitTree T,ElemType e,BitTree l,BitTree r){
  T->data = e;
  T->lchild = l;
  T->rchild = r;
  return;
}

void visit(ElemType e){
  printf("%d ",e);
}

//preOrder traverse
void preOrder(BitTree T){
  if(T){
    visit((ElemType)T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
  }
  return;
}

//inOrder traverse
void inOrder(BitTree T){
  if(T){
    inOrder(T->lchild);
    visit(T->data);
    inOrder(T->rchild);
  }
  return;
}

//postOrder traverse
void postOrder(BitTree T){
  if(T){
    postOrder(T->lchild);
    postOrder(T->rchild);
    visit(T->data);
  }
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

  printf("[preOrder]: ");
  preOrder(root);
  printf("\n");

  printf("[inOrder]: ");
  inOrder(root);
  printf("\n");

  printf("[postOrder]: ");
  postOrder(root);
  printf("\n");
}   
