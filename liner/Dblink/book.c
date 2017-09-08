#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef struct Dbnode{
  int data;
  struct Dbnode * next;
  struct Dbnode * prior;
} Dbnode, *Dblink;

typedef int ElemType;
typedef int Status;

Status initLink(Dblink * link,int num){
  srand(time(0));

  Dblink L = *link;
  Dblink tmp,new;
  L->data = 0;
  L->prior = NULL;
  L->next = NULL;
  tmp = L;

  int i;
  for(i=0;i<num;i++){
    new = (Dblink)malloc(sizeof(Dbnode));
    new->data = rand()%100 +1;
    new->next = tmp->next;
    new->prior = tmp;
    tmp->next = new;
    tmp = tmp->next;
  }

  tmp->next = *link; //connect the head
  (*link)->prior = tmp;
  return OK;
}

Status insertLink(Dblink *link,int index,ElemType e){

  Dblink tmp = (*link)->next;  //ignore head node
  Dblink new,pre;
  
  int i=1;
  
  while( tmp!=*link && i<index ){
     tmp = tmp->next;
     i++;
  }

  if( tmp==*link || i>index){
     printf("overflow\n");
     return OVERFLOW;
  }

  new = (Dblink)malloc(sizeof(Dbnode));
  pre = tmp->prior;

  new->data = e;
  new->prior=pre;
  new->next =tmp;
  pre->next = new;
  tmp->prior= new;
  
  return OK;
}

Status deleteLink(Dblink *link,int index){
  
  Dblink tmp = (*link)->next;  //ignore head node 

  int i=1;
  while( tmp!=*link && i<index ){
    tmp=tmp->next;
    i++;
  }
  
  if( tmp==*link || i>index ){
     printf("overflow\n");
     return OVERFLOW;
  }

  Dblink pre = tmp->prior;
  Dblink net = tmp->next;
  pre->next = tmp->next;
  net->prior = tmp->prior;

  free(tmp);

  return OK;
}

Status convertLink(Dblink * link){

  Dblink p,q;
  p = (*link)->next;
  
  while( p != *link){
    q = p->next;
    p->next = p->prior;
    p->prior = q;
    p=q;
  }

  q = (*link)->next; //p is *link
  (*link)->next = p->prior;
  (*link)->prior = q;
  
  return OK;
}

Status printLink(Dblink link){
   Dblink p = link;
   while(p->next!=link){
     p = p->next;		//ignore head node
     printf("[%d] ",p->data);
   }

   printf("\n");
   return OK;
}

int main(){
  int num,index,value;
  Dblink link = (Dblink)malloc(sizeof(Dbnode));

  //initation
  printf("[create]enter the num:");
  scanf("%d",&num);
  initLink(&link,num);
  printLink(link);

  //convert
  printf("[convert]\n");
  convertLink(&link);
  printLink(link);

  //insert
  printf("[insert]enter the index:");
  scanf("%d",&index);
  printf("[insert]enter the value:");
  scanf("%d",&value);
  insertLink(&link,index,value);
  printLink(link);

  //delete
  printf("[delete]enter the index:");
  scanf("%d",&index);
  deleteLink(&link,index);
  printLink(link);
  return OK;
}
