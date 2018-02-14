#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define OK 0
#define ERROR 1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

typedef struct BNode{
  ElemType  data;
  struct BNode *lc,*rc;	//left child and right child
} BNode, *BTree;

typedef struct BTQnode{
  BTree data;
  struct BTQnode *next;
} BTQnode, *BTQlink;

typedef struct {
  BTQlink front;
  BTQlink rear;
} BTQ , *BTQueue;


int FastLog2(int x){  
  float fx;  
  unsigned long ix, exp;  
  fx = (float)x;  
  ix = *(unsigned long*)&fx;  
  exp = (ix >> 23) & 0xFF;  
  return exp - 127;  
}  

Status isBTQEmpty(BTQueue Q){
  if(Q->rear == Q->front) return TRUE;
  else return FALSE;
}

Status initBTQ(BTQueue *Q){
  *Q = (BTQueue)malloc(sizeof(BTQ));
  (*Q)->front = (*Q)->rear = (BTQlink)malloc(sizeof(BTQnode));
  (*Q)->front->next = NULL;
  return OK;
}

Status enBTQ(BTQueue Q, BTree e){
  BTQlink n = (BTQlink)malloc(sizeof(BTQnode));
  n->data = e;
  n->next = NULL;
  Q->rear->next = n;
  Q->rear = n;
  return OK;
}

Status deBTQ(BTQueue Q,BTree *e){
  if(isBTQEmpty(Q)) return ERROR;
  
  BTQlink t = Q->front->next;
  Q->front->next = t->next;
  *e = t->data;
  if(Q->rear == t) Q->rear = Q->front;
  free(t);
  return OK;
}

Status destroyBTQ(BTQueue *Q){
  while( (*Q)->front != NULL ){
    (*Q)->rear = (*Q)->front->next;
    free( (*Q)->front );
    (*Q)->front  = (*Q)->rear;
  }
  return OK;
}

void createTestTree(BTree *T,int number){
  srand(time(0));

  *T = (BTree)malloc(sizeof(BNode));

  int i;
  int * datas = (int*)malloc(number * sizeof(int));

  for(i=0; i<number; i++){
    datas[i] = rand()%100 + 1;
  }

  BTQueue Q;
  initBTQ(&Q);

  BTree p = *T;
  i = 0;

  int h = number/2 - 1;  

  do{
    p->data = datas[i];
    
    if(i<=h){
      p->lc = malloc(sizeof(BNode));
      p->rc = malloc(sizeof(BNode));
      enBTQ(Q,p->lc);
      enBTQ(Q,p->rc);
    }else{
      p->lc = NULL;
      p->rc = NULL;
    } 

    if(i==h && number%2==0 ) p->rc=NULL;
    deBTQ(Q,&p);
  } while(++i < number);
   
}

void InOrder(BTree T){
  if(T){
    InOrder(T->lc);
    printf("%d ",T->data);
    InOrder(T->rc);
  }
}

void PreOrder(BTree T){
  if(T){
    printf("%d ",T->data);
    PreOrder(T->lc);
    PreOrder(T->rc);
  }
}

void layerPrint(BTree T){ 
  BTree p;
  BTQueue Q;
  initBTQ(&Q);

  int i = 0;
  int level = -1;
  
  enBTQ(Q,T);

  while(!isBTQEmpty(Q) && ++i<=100){		//i用于防止死循环，和计算当前行数

    if(level != FastLog2(i)){			//如果换行了，打印行号
      level = FastLog2(i);
      printf("\nLEVEL-%d: ",level+1);
    }

    deBTQ(Q,&p);
    printf("%d ",p->data);
    if(p->lc)enBTQ(Q,p->lc);
    if(p->rc)enBTQ(Q,p->rc);
  }

  printf("\n");
}

int main(){
  int n;
  BTree T;
  
  printf("Enter the scale of the problem: ");
  scanf("%d",&n);

  createTestTree(&T,n);

  printf("Inorder:  ");  
  InOrder(T);
  printf("\n");

  printf("Preorder: ");  
  PreOrder(T);
  printf("\n");

  printf("Layer: ");
  layerPrint(T);
}
