#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct Node{
  ElemType data;
  struct Node * next;
} Node;

Node * initStack(){
  Node * s = (Node*)malloc(sizeof(Node));
  s->next =NULL;
  return s;
}

Status Push(Node *s,ElemType e){
  Node * new = (Node*)malloc(sizeof(Node));
  new->data = e;
  new->next = s->next;
  s->next = new;
  return OK;
}

Status Pop(Node *s,ElemType *e){
  Node * top = s->next;
  *e = top->data;
  s->next = top->next;
  free(top);
  return OK;
}

Status stackEmpty(Node *s){
  if(!s->next)return OK;
  else return ERROR;
}

Status checkBrackets(char str[]){
  Node * s = initStack();
  char v;
  int i = 0;
  while(str[i] != '\n'){
    switch(str[i]){
      case '(':
        Push(s,str[i]);
        break;

      case '[':
        Push(s,str[i]);
        break;
     
      case '{':
        Push(s,str[i]);
        break;

      case ')':
        if(stackEmpty(s))return ERROR;
        else{
           Pop(s,&v);
           if(v == '(')break;
           else return ERROR;
        }
       
      case ']':
        if(stackEmpty(s))return ERROR;
        else{
           Pop(s,&v);
           if(v=='[')break;
           else return ERROR;
        }

      case '}':
        if(stackEmpty(s))return ERROR;
        else{
           Pop(s,&v);
           if(v == '{')break;
           else return ERROR;
        }

    }
    i++;
  }

  if(stackEmpty(s))return OK;
}

int main(){
  char str[100];
  printf("enter a string:");
  fgets(str,100,stdin);
  if(checkBrackets(str))printf("it is matches all\n");
  else printf("sorry it didn't matches\n");
  return 0;
}
