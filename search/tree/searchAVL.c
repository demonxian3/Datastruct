#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct Bitnode{
  ElemType data;
  struct Bitnode *lchild,*rchild;
  int bf;				//Balance Factor
} Bitnode , * BitTree;

BitTree createNode(int a){
  BitTree T = (BitTree)malloc(sizeof(Bitnode));
  T->lchild = NULL;
  T->rchild = NULL;
  T->bf = 0;
  T->data = a;
  return T;
}

Status swap(int *A,int *B){
  *A -= *B;
  *B += *A;
  *A = *B - *A;
}

void InOrder(BitTree T){
  if(T){
    InOrder(T->lchild);
    printf("%d ",T->data);
    InOrder(T->rchild);
  }
}



int getDepth(BitTree T){
  if(!T) return 0;
  int lbf = getDepth(T->lchild);
  int rbf = getDepth(T->rchild);
  T->bf = lbf - rbf;
  return lbf > rbf ? lbf+1 : rbf+1;
}

BitTree findNode(BitTree T){
  if(!T) return NULL;
  BitTree L = findNode(T->lchild);
  BitTree R = findNode(T->rchild);
  if(L) return L;
  else if(R) return R;
  else if(T->bf == 2 || T->bf == -2)return T;
  else return NULL;
}

Status R_Rotate(BitTree T){
  if(!T && T->lchild) return FALSE;
  
  BitTree L = T->lchild;

  swap(&(T->data) , &(L->data) );
  T->lchild = L->lchild;
  L->lchild = L->rchild;
  L->rchild = T->rchild;
  T->rchild = L;

  return TRUE;
}

Status L_Rotate(BitTree T){
  if(!T && T->rchild) return FALSE;
  
  BitTree R = T->rchild;
  
  swap( &(T->data) , &(R->data));
  T->rchild = R->rchild;
  R->rchild = R->lchild;
  R->lchild = T->lchild;
  T->lchild = R;
 
  return TRUE;
}

Status adjustTree(BitTree Root){
  if(!Root) return FALSE;
  getDepth(Root);  			//flush every node's bf
  
  BitTree R = NULL, L = NULL;
  BitTree T = findNode(Root);		//unbalance node
  if(!T) return FALSE;
  //printf("%d\n",T->data);

  switch(T->bf){
    case -2: R = T->rchild;break;
    case  2: L = T->lchild;break;
  }
  
  if(R){
    switch(R->bf){
      case -1: 				//RR
	L_Rotate(T);
	break;

      case  1:				//RL
	R_Rotate(R);
	L_Rotate(T);
	break;
    }
  }

  if(L){
    switch(L->bf){
      case   1:				//LL
	R_Rotate(T);
	break;

      case  -1:				//LR
	L_Rotate(L);
	R_Rotate(T);
	break;
    }
  }

  return TRUE;
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
    new->bf = 0;
    if(!*T)
       *T=new;
    else if(p->data > a) 
       p->lchild = new;
    else
       p->rchild = new;

    //AVL adjust
    printf("gdb");
    if(!adjustTree(*T))printf("no adjust\n");
    else printf("adjusted\n");
    printf("gdb");

    return TRUE;

  }else 
    return FALSE;
}

Status delete(BitTree *T){
  BitTree tmp = *T;
  BitTree test = malloc(sizeof(Bitnode));
  test->data = 77;

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

  printf("gdb");
  adjustTree(*T);
  printf("gdb");
}

Status deleteAVL(BitTree *T,int key){
  if(!(*T))return FALSE;
  else{
    if((*T)->data == key){
      delete(T);
      return TRUE;
    }
    else if((*T)->data > key)
      deleteAVL(&((*T)->lchild),key);
    else 
      deleteAVL(&((*T)->rchild),key); 
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
      if(deleteAVL(&T,a))printf("delete successfully\n");
      else printf("Delete failed\n");
    }

  }
  
  printf("%d\n",T->data);
  return 0;
}
