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
/*
 *Thinking:
 *1.connect precursor || connect subsequence when lchild or rchild is NULL
 *2.let prepointer equal the p-pointer
 *3.recursive lchild
 *4.recursive rchild
 *There's bug which will make loop after threading the lchild and recursive it in step3;
 *There's bug which will make loop after threading the rchild in step4 when the numbers of node is even
 */ 
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

     //let prepointer track the p-pointer
     pre = p;
  
     //recursive left/right son
     if(p->ltag==0)             //prevent loop
       PreThreading(p->lchild);
     if(p->rtag==0)             //prevent loop
       PreThreading(p->rchild);
   }     
}

void visit(ElemType e){
  printf("%d ",e);
}

Status PreOrderTraverse_Thr(BitThrTree T){
  BitThrTree p = T->lchild;
  while(p!=T){
    while(p->ltag==0){
      visit(p->data);
      p=p->lchild;
    }
    while(p->rtag && p!=T){
      visit(p->data);
      p=p->rchild;
    }
  }
}

int main(){
  BitThrTree Thrt;
  BitThrTree T = createTree();
  PreOrderThreading(&Thrt,T);
  PreOrderTraverse_Thr(Thrt);
  printf("\n");
  return 0;
}
