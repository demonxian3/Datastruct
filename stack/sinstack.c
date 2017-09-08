#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;
typedef struct Node{
  ElemType data;
  struct Node * next;
} Node;

Node * initStack(){
  Node * s = (Node*)malloc(sizeof(Node));
  s->next = NULL;
  return s;
}

Status  Push(Node *s,ElemType e){
  Node *new = (Node*)malloc(sizeof(Node));
  new->data = e;
  new->next = s->next;
  s->next = new;
  return OK;
}

Status  Pop(Node *s,ElemType *e){
  Node *top = s->next;
  *e = top->data;
  s->next = top->next;
  free(top);
  return OK;
}

ElemType getTopvalue(Node *s){
  Node *top = s->next;
  return top->data;
}

int getLength(Node *s){
  int len=0;
  while(s->next){ 
    s=s->next;
    len++;
  }
  return len;
}

Status stackEmpty(Node *s){
  if(s->next)return ERROR;
  else return OK;
}

Status printStack(Node *s){
  if(stackEmpty(s)){printf("stack is empty\n");return ERROR;}
  else printf("stack len is %d\n",getLength(s));  

  while(s=s->next)printf("[%d]",s->data);
  printf("\n");
  return OK;
}

int main(){
  char sel;
  ElemType val;
  Node * s = initStack();
  while(1){
    system("clear");
    printStack(s);
    printf("enter code:");
    sel = getchar();
    if(sel == 'p'){
      printf("enter value:");
      scanf("%d",&val);
      Push(s,val);
    }

    if(sel == 'P'){
      Pop(s,&val);
      printf("%d is poped\n",val);
      sleep(1);
    }
 
    if(sel == 'g'){
      printf("top value is %d\n",getTopvalue(s));
      sleep(1);
    }

    if(sel == 'e')exit(0);
  }
}
