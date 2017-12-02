/****************************
 *  This program merge the  * 
 *  Create function and Se  *
 *  arch function, very co  *
 *  ol, the code's referer  *
 *  is book;                *
 * **************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int KeyType;

typedef struct {
  KeyType key;
  //other data;
} ElemType;

typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild, *rchild;
} BitNode, *BitTree;

Status searchBST(BitTree T,KeyType key,BitTree f,BitTree *p){
  if(!T){*p=f;return FALSE;}            //Label:NM if T is Null, it will be a root;
  else if(key == T->data.key){
    *p=T;return TRUE;    //find the node
  }
  else if(key < T->data.key)
    searchBST(T->lchild,key,T,p);
  else
    searchBST(T->rchild,key,T,p); 
}

Status insertBST(BitTree *T,KeyType e){
  BitTree p = NULL;
  if(!searchBST(*T,e,NULL,&p)){  //这里需要改变p的值，因此传递其地址
    BitTree new = (BitTree)malloc(sizeof(BitNode)); 
    new->data.key = e;
    new->lchild = NULL;
    new->rchild = NULL;
    if(!p)*T=new;  //if no parent,T as the root
    else if(e < p->data.key)
      p->lchild = new;
    else
      p->rchild = new;
    return TRUE;
  }else{
    return FALSE; //if find the node, exit normally
  }
}

BitTree createBST(n){
  int i;
  BitTree T = NULL;   //NULL must be used as an initial value, look the label :NM:
  KeyType key;
  for(i=0;i<n;i++){
    printf("[%d]key-value: ",i);
    scanf("%d",&key);
    if(!insertBST(&T,key))  //直接用T不会改变T的值，因此每次都是从T=NULL开始。
      printf("%d is exited \n",key);
  }
  return T;
}

InOrder(BitTree T){
  if(T){
    InOrder(T->lchild);
    printf("%d ",T->data.key);
    InOrder(T->rchild);
  }
}

int main(){
  int num,key;
  printf("Enter the BST-tree number: ");
  scanf("%d",&num);
  BitTree T = createBST(num); 
  //InOrder(T);  //debug
}
