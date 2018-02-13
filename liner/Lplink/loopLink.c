#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct Node{
  int data;
  struct Node * next;
}Node, *Lplink;

Status initLink(Lplink *link,int num){
  
  Lplink head = *link;
  Lplink new;
  head->data = 0;
  head->next = NULL;
  Lplink tmp = head;
  
  while(num--){
    new = (Lplink)malloc(sizeof(Node));
    new->data = rand()%100+1;
    new->next = tmp->next;
    tmp->next = new;
    tmp = tmp->next;
  }

  tmp->next = head;
  return OK;
}

Status invertLink(Lplink * link){

   Lplink f = *link;
   Lplink s = f->next;
   Lplink t = s->next;

   do{
     s->next = f;
     f = s;
     s = t;
     t = t->next;
   }while(f!=*link);
   
   return OK;  
}


Status deletePrior(Lplink *link,int index){

  Lplink prior = *link;
  
  int i=0;
  while( prior && i<index){
    prior = prior->next;
    i++;
  }

  if( !prior || i>index){
    printf("overflow\n");
    return OVERFLOW;
  }
 
  //exchange prior and target value
  Lplink tmp = prior->next;
  int val = prior->data;
  prior->data = tmp->data;
  tmp->data = val;
 
  //delete tmp
  prior->next = tmp->next;
  free(tmp);
  return OK;
}

Status printLink(Lplink link){
  Lplink tmp = link->next;
  
  while(tmp != link){	//if tmp isn't end node
    printf("[%d] ",tmp->data);
    tmp = tmp->next;
  }

  printf("\n");
}


int main(){

  
  int num,index;
  printf("[create]enter the num:");
  scanf("%d",&num);
  Lplink link = (Lplink)malloc(sizeof(Node));
  initLink(&link,num);
  printLink(link);
  invertLink(&link);
  printLink(link);

  //delete prior
  printf("[delete]enter the index:");
  scanf("%d",&index);
  deletePrior(&link,index);
  printLink(link);

  return OK;
}
