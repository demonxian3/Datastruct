#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void create(BitTree T,int e,BitTree l,BitTree r){
  T->data = e;
  T->lchild = l;
  T->rchild = r;
  return;
}

void visit(int e){
  printf("%d ",e);
  return;
}

void LevelOrder(BitTree T){
  if(T==NULL)return;
  Queue Q;
  BitTree p;

  initQueue(&Q);
  enQueue(&Q,T);
 
  while(!emptyQueue(Q)){
    deQueue(&Q,&p);
    visit(p->data);
    if(p->lchild)enQueue(&Q,p->lchild);
    if(p->rchild)enQueue(&Q,p->rchild);
  }
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
    
    LevelOrder(root);
    printf("\n");
    return;
}
