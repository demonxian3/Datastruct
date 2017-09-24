#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int ElemType;
typedef struct BitNode{
  ElemType data;
  struct BitNode *rchild,*lchild;
}BitNode,*BitTree;

void createBitTree(BitTree root){
   int num,val;
   BitTree arr[MAX];
   printf("input the number of Node:");
   scanf("%d",&num);
   
   printf("[1]value:");
   scanf("%d",&val);
   root->data = val;   
   arr[1]=root;

   int i=2;
   while(i<=num){
     BitTree node = (BitTree)malloc(sizeof(BitNode));
     printf("[%d]value:",i);
     scanf("%d",&val);
     node->data = val;
     arr[i]=node;
     i++;
   }

   i=1;
   while(((int)2*i)<=num){
     arr[i]->lchild = arr[(int)2*i];
     if(((int)2*i+1)<=num)
     arr[i]->rchild = arr[(int)2*i+1];
     i++;
   }
}

void visit(ElemType data){
  printf("[%d] ",data);
}

void InOrder(BitTree p){
  if(p){
   InOrder(p->lchild);
   visit(p->data);
   InOrder(p->rchild);
 }
}

int main(){
  BitTree root = (BitTree)malloc(sizeof(BitNode));
  createBitTree(root);
  InOrder(root);
  printf("\n");
  return 0;
}
