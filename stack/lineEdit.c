#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char  ElemType;
typedef struct Node{
  ElemType data;
  struct Node *next;
} Node;

Node *initStack(){
  Node *s = (Node*)malloc(sizeof(Node));
  s->next = NULL;
  return s;
}

Status pushStack(Node *s,ElemType e){
  Node *new = (Node*)malloc(sizeof(Node));
  new->next = s->next;
  new->data = e;
  s->next = new;
  return OK; 
}

Status popStack(Node *s,ElemType *e){
  if(!s->next){
    printf("overflow!\n");
    return OVERFLOW;
  }
  Node *tmp = s->next;
  *e = tmp->data;
  s->next = tmp->next;
  free(tmp);
  return OK;
}

Status clearStack(Node *s){
  Node *tmp;
  while(s->next){
    tmp=s->next;
    s->next = tmp->next;
    free(tmp);
  }
  return OK;
}

Status destoryStack(Node *s){
  Node *pre;
  while(s){
    pre = s;
    s=s->next;
    free(pre);
  }
  return OK;
}

Status lineEdit(){
  char ch;
  Node *s = initStack();
  printf("enter a line( # del,@ cls):");
  ch=getchar();
  while(ch!=EOF){
    while(ch!='\n'){
      switch(ch){
        case '#':
          popStack(s,&ch);
          break;
        case '@':
          clearStack(s);
          break;
        default:
          pushStack(s,ch);
          break;
      }
      ch = getchar();
    }

    int i;
    char rev[1024];

    //input to array
    for(i=0;s->next;i++){
      popStack(s,&ch);
      *(rev+i)=ch;
    }
    *(rev+i)='\0';
    
    //reverse output
    for(--i;i>-1;i--){
      printf("%c",*(rev+i));
    }

    printf("\n");
    clearStack(s);
    
    if(ch!=EOF){
      printf("enter a line:");
      ch = getchar();
    }    
  }
  destoryStack(s);
}

int main(){
  lineEdit();
  return OK;
}

