#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct BitThrNode{
  ElemType data;
  int ltag,rtag;
  struct BitThrNode *lchild,*rchild;
}BitThrNode,*BitThrTree;

BitThrTree pre;

BitThrTree createTree(){
  int i;
  int val,num;
  BitThrTree arr[MAX];

  printf("input number:");
  scanf("%d",&num);

  i=1;
  while(i<=num){
    BitThrTree node = (BitThrTree)malloc(sizeof(BitThrNode));
    printf("[%d]value:",i);
    scanf("%d",&val);
    node->data = val;
    arr[i]=node;
    i++;
  }

  i=1;
  while((int)2*i<=num){
    arr[i]->ltag = 0;
    arr[i]->lchild = arr[(int)2*i];
    if((int)2*i+1<=num){
    arr[i]->rtag = 0;
    arr[i]->rchild = arr[(int)2*i+1];
    }
    i++;
  }
  return arr[1];
}

void PreThreading(BitThrTree p);

Status PreOrderThreading(BitThrTree *Thrt,BitThrTree T){
  BitThrTree Tree = (BitThrTree)malloc(sizeof(BitThrNode));
  Tree->ltag = 0;
  Tree->rtag = 1;
  Tree->data = 99;

  Tree->rchild = Tree;
  if(!T) 
    Tree->lchild = Tree;
  else{
    Tree->lchild = T;
    pre = Tree;
    PreThreading(T);
    Tree->rchild = pre;
    pre->rchild = Tree;
    pre->rtag = 1;
  }

  *Thrt = Tree;
}

void PreThreading(BitThrTree p){
   if(p){
     //Threading first
     if(!p->lchild){    //Threading precursor
       p->ltag = 1; 
       p->lchild = pre;
     }
     if(!pre->rchild){  //Threading subsequence
       pre->rtag = 1;
       pre->rchild = p;
     }

     //pointer forwarding
     pre = p;
  
     //recursive left/right son
     if(p->ltag==0)             //prevent loop
       PreThreading(p->lchild);
     else
       pre = p;

     PreThreading(p->rchild);
   }     
}

//void preOrder(BitThrTree p){
//  if(p){
//    printf("%d ",p->data);
//    preOrder(p->lchild);
//    preOrder(p->rchild);
//  }
//}

int main(){
  BitThrTree Thrt;
  BitThrTree T = createTree();
  PreOrderThreading(&Thrt,T);
  return 0;
}
