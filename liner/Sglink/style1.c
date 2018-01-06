#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct Node{
  ElemType data;
  struct Node * next;
} Node;

typedef struct Node* Link;

Status createHead(Link *L,int num){
  
  srand(time(0)); 

  Link link = *L;
  Link new;

  link->data = 0;
  link->next = NULL;

  int i;

  for(i=0;i<num;i++){
    new = (Link)malloc(sizeof(Node));
    new->data = rand()%100+1;
    new->next = link->next;
    link->next = new;
  }
  
  return OK;
}

Status createTail(Link * L,int num){

  Link tmp,new,link;
  srand(time(0));

  link = *L;
  link->data=0;
  link->next=NULL;

  tmp = link;

  int i;
  for(i=0;i<num;i++){
     new = (Link)malloc(sizeof(Node));
     new->data = rand()%100+1;
     new->next = tmp->next;
     tmp->next = new;
     tmp=tmp->next;
  }

  return OK;
}

Status insertLink(Link * L,int index,ElemType e){
  
  index--;
  Link new,tmp = *L;

  int i=0;
  while( tmp && i<index ){
    tmp=tmp->next;
    i++;
  }

  if( !tmp || i>index ){
    printf("overflow\n");
    return OVERFLOW;
  }

  new=(Link)malloc(sizeof(Node));
  new->data = e;
  new->next = tmp->next;
  tmp->next = new;
  return OK;
}

Status deleteLink(Link *L,int index,ElemType *e){
  
   index--;
   Link net,tmp = *L;

   int i=0;
   while( tmp && i<index){
     tmp=tmp->next;
     i++;
   }

   if( !tmp || i>index){
     printf("overflow\n");
     return OVERFLOW;
   }
 
   net = tmp->next;
   tmp->next = net->next;
   free(net);
   return OK;
}

Status getValue(Link L,int index,ElemType* e){

  int i=0;
  index--;
  L=L->next; //ignore head node
  while(L && i<index){
    L=L->next;
    i++;
  }

  if(!L || i>index){
     printf("index is valid\n");
     return ERROR;
  }

  *e = L->data;
  return OK;
}

Status freeLink(Link*L){
  Link p,q;
  p = (*L)->next;
  while(p){
    q=p->next;
    free(p);
    p=q;
  }

  (*L)->next = NULL;
  return OK;
}

Status printLink(Link L){
  Link p = L;
  
  if(p->next==NULL){
    printf("link is empty\n");
    return OK;
  }  
  
  int i = 1;
  while(p->next){
    p=p->next;			//ignore head node
    printf("[%d] ",p->data);
    if(i%10==0)printf("\n");
    i++;
  }
  printf("\n");
  return OK;
}

int getCount(Link L,ElemType x){
  int count = 0;
  while( L->next ){
    L=L->next;
    if(L->data == x)count++;
  }
  return count;
}


int main(){
  int index,value,num = 50;
  Link L = (Link)malloc(sizeof(Node));
  createTail(&L,num);
  printLink(L);

  //insert
  printf("enter index:");
  scanf("%d",&index);
  printf("enter value:");
  scanf("%d",&value);
  insertLink(&L,index,value);
  printLink(L);

  //delete
  printf("enter index:");
  scanf("%d",&index);
  deleteLink(&L,index,&value);
  printLink(L);
 
  //getvalue
  printf("enter index:");
  scanf("%d",&index);
  getValue(L,index,&value);
  printf("value is %d\n",value);

  //getCount
  printf("enter value:");
  scanf("%d",&value);
  int c = getCount(L,value);
  printf("count is %d\n",c);
  
  //freeLink
  freeLink(&L);
  return OK;
}
