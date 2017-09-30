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

BitThrTree pre;	                                         //This is global variable;

BitThrTree createTree(){
  int i=1;
  int val,num;
  BitThrTree arr[MAX];

  printf("input number:");
  scanf("%d",&num);

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


void InThreading(BitThrTree p);				 //declare funcion;

Status InOrderThreading(BitThrTree *Thrt,BitThrTree T){
  *Thrt = (BitThrTree)malloc(sizeof(BitThrNode));        //This is Head Node for Threading Tree

  (*Thrt)->ltag = 0;                //child
  (*Thrt)->rtag = 1;                //thread

  (*Thrt)->rchild = (*Thrt);        //rpointer Anaphora
  if(!T)(*Thrt)->lchild = (*Thrt);  //lpointer Anaphora

  else{                             //if tree is not NULL
    pre = *Thrt;
    (*Thrt)->lchild = T;

    InThreading(T);

    pre->rtag = 1;
    pre->rchild = *Thrt;
    (*Thrt)->rchild = pre;
  }
}

void InThreading(BitThrTree p){
  if(p){
    if(!p->lchild){                 //if p->lchild is NULL,Threading precursor
      p->lchild = pre;
      p->ltag = 1;
    }
    else
      InThreading(p->lchild);       //recursive the p->rchild

    if(!pre->rchild){               //if pre->rchild is NULL,Threading subsequence
      pre->rchild = p;
      pre->rtag =1;
    }

    pre=p;			    //pointer forwarding
    InThreading(p->rchild);         //recursive the p->lchild
  }
}

void visit(ElemType e){
  printf("%d ",e);
}


Status InOrderTraverse_Thr(BitThrTree T){
  BitThrTree p = T->lchild;                  //pointer point to Root Node
  while(p!=T){
    while(p->ltag == 0)p = p->lchild;        //begining from the left child 
    visit(p->data);
    while(p->rtag == 1 && p->rchild != T){
      p=p->rchild;visit(p->data);            //forwarding by the thread
    }
    p=p->rchild;
  }
  return OK;
}

int main(){
  BitThrTree T = createTree();
  BitThrTree Thrt;
  InOrderThreading(&Thrt,T);
  InOrderTraverse_Thr(Thrt);
  printf("\n");
  return OK;
}


