#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct Node{
  ElemType data;
  struct Node *next;
} Node;

Node * initStack(){
  Node *s = (Node*)malloc(sizeof(Node));
  s->next = NULL;
  return s;
}

Status pushStack(Node *s,ElemType e){
  Node *new = (Node*)malloc(sizeof(Node));
  new->data = e;
  new->next = s->next;
  s->next = new;
  return OK;
}

Status popStack(Node *s,ElemType *e){
  if(isEmpty(s))return OVERFLOW;
  Node *tmp = s->next;
  *e = tmp->data;
  s->next = tmp->next;
  free(tmp);
  return OK;
}

Status isEmpty(Node *s){
  if(s->next==NULL)return TRUE;
  else return FALSE;
}

