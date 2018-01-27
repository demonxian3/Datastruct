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

int getDepth(BitTree T){
  if(!T)return 0;
  int leftLen = getDepth(T->lchild);
  int rightLen = getDepth(T->rchild);
  T->bf = leftLen - rightLen;

  return leftLen > rightLen ? leftLen+1 : rightLen+1 ;
}

BitTree findp(BitTree p){
  if(!p)return NULL;
  BitTree lc = findp(p->lchild);
  BitTree rc = findp(p->rchild);
  if(lc)return lc;
  else if(rc)return rc;
  else if(p->bf==2)return p;
  else return NULL;
}

//@@issue: how to catch p and k
//the p is that the balance facctor is more than 1
//the k is that the newNode's parents;

Status adjustTree(BitTree *p,BitTree k){
  BitTree t = NULL;
  BitTree n = NULL;

  if((*p)->bf > 0){
      t = (*p)->lchild;
 
      if(t->bf > 0){               //LL
          (*p)->lchild = t->rchild;
          t->rchild = *p;
          *p = t;


      }else{                       //LR
          if(k->bf > 0) {

            n=k->lchild;
            n->lchild = t;
            n->rchild = *p;
            (*p)->lchild = NULL;
            *p = n;
            k->lchild = NULL;
      
          }else{

            n=k->rchild;
            n->lchild = t;
            n->rchild = *p;
            (*p)->lchild = NULL;
            *p = n;
            k->rchild = NULL;

          }
      }
  }


  else{
      t = (*p)->rchild;

      if(t->bf < 0){               //RR
          (*p)->rchild = t->lchild;
          t->lchild = *p;
          *p = t;


      }else{                       //RL
          if(k->bf > 0) {

            n=k->lchild;
            n->rchild = t;
            n->lchild = *p;
            (*p)->rchild = NULL;
            *p = n;
            k->lchild = NULL;

          }else{

            n=k->rchild;
            n->rchild = t;
            n->lchild = *p;
            (*p)->rchild = NULL;
            *p = n;
            k->rchild = NULL;

          }
      }  
  }  
}
  

void ajustMain(BitTree *T,BitTree k){
  getDepth(*T);
  BitTree p = findp(*T);
  adjustTree(&p,k);
}




void InOrder(BitTree T){
  if(T){
    InOrder(T->lchild);
    printf("%d ",T->data);
    InOrder(T->rchild);
  }
}


int main(){
  //BitTree T = NULL; 
  //char c;
  //int a = 3;

  BitTree T = createNode(100);
  BitTree A = createNode(70);
  BitTree B = createNode(50);
  BitTree C = createNode(30);
  BitTree D = createNode(40);
  BitTree E = createNode(80);
  BitTree F = createNode(90);
  BitTree G = createNode(110);
  BitTree H = createNode(120);
  
  T->lchild = A;
  T->rchild = G;

  A->lchild = B;
  A->rchild = E;

  B->lchild = C;
  E->lchild = F;

  C->rchild = D;
  G->rchild = H;

  getDepth(T);
  
  BitTree p = findp(T);
  
  
  //printf("gdb\n");


  
  
  
  //while(1){
  //  InOrder(T);
  //  printf("\n");

  //  printf("input order:");
  //  c = getchar();
 
  //  if(c == 'i'){
  //    printf("insert key:");
  //    scanf("%d",&a);
  //    getchar();
  //    if(insert(&T,a))printf("Insert succesfully\n");
  //    else printf("Insert failedy\n");
  //  }

  //  if(c == 'd'){
  //    printf("delete key:");
  //    scanf("%d",&a);
  //    getchar();
  //    if(deleteAVL(&T,a))printf("delete successfully\n");
  //    else printf("Delete failed\n");
  //  }

  //}
  
  //printf("%d\n",T->data);
  return 0;
}
