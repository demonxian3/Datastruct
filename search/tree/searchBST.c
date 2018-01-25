#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct Bitnode{
  ElemType data;
  struct Bitnode *lchild,*rchild;
} Bitnode , * BitTree;

BitTree createNode(int a){
  BitTree T = (BitTree)malloc(sizeof(Bitnode));
  T->lchild = NULL;
  T->rchild = NULL;
  T->data = a;
  return T;
}

Status search(BitTree T,int a,BitTree *p){

  if(!T)return FALSE;
  else if(T->data == a)return TRUE;
  else {
    *p=T;
    if(T->data > a)
       search(T->lchild,a,p);
    else
       search(T->rchild,a,p);
  }

}

Status insert(BitTree *T,int a){
  BitTree p = NULL;
  if(!search(*T,a,&p)){
    BitTree new = malloc(sizeof(Bitnode));
    new->data = a;
    new->lchild = new->rchild = NULL;
    if(!*T)
       *T=new;
    else if(p->data > a) 
       p->lchild = new;
    else
       p->rchild = new;

    return TRUE;

  }else 
    return FALSE;
}

Status delete(BitTree *T){
  BitTree tmp = *T;
  if(!tmp->rchild && !tmp->lchild ) {*T=NULL;free(tmp);}
  else if(!tmp->lchild) {*T=tmp->rchild;free(tmp);}
  else if(!tmp->rchild) {*T=tmp->lchild;free(tmp);}
  else{
    BitTree p,lc,rc;
    rc = tmp->rchild;
    p = lc = tmp->lchild;
    while(lc->rchild){
      p = lc;
      lc = lc->rchild;
    }

    //method 1
    //lc->rchild = rc;
    //*T = tmp->lchild;
    //free(tmp);
    

    //method 2
    (*T)->data = lc->data;
    if(p==lc)   //被删节点左孩子没有右孩子，重接左孩子
      (*T)->lchild = lc->lchild;
    else        //被删节点左孩子存在右孩子，重接右孩子
      p->rchild = lc->lchild;
    lc=NULL;
    free(lc);
    
  }
 
}


Status deleteBST(BitTree *T,int key){
  if(!(*T))return FALSE;
  else{
    if((*T)->data == key){
      delete(T);
      return TRUE;
    }
    else if((*T)->data > key)deleteBST(&((*T)->lchild),key);
    else deleteBST(&((*T)->rchild),key); 
  }
}



void InOrder(BitTree T){
  if(T){
    InOrder(T->lchild);
    printf("%d ",T->data);
    InOrder(T->rchild);
  }
}


int main(){
  BitTree T = NULL; 
  char c;
  int a = 3;
  
  while(1){
    InOrder(T);
    printf("\n");

    printf("input order:");
    c = getchar();
 
    if(c == 'i'){
      printf("insert key:");
      scanf("%d",&a);
      getchar();
      if(insert(&T,a))printf("Insert succesfully\n");
      else printf("Insert failedy\n");
    }

    if(c == 'd'){
      printf("delete key:");
      scanf("%d",&a);
      getchar();
      if(deleteBST(&T,a))printf("delete successfully\n");
      else printf("Delete failed\n");
    }

  }
  
  

    
  //printf("%d\n",T->data);
  return 0;
}
