#define OK 0
#define ERROR 1
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

typedef char ElemType;
typedef int Status;
typedef struct Node{
  ElemType data;
  struct Node * next;
} Node,*Stack;

Status initStack(Stack *S){
  *S = (Stack)malloc(sizeof(Node));
  (*S)->next = NULL;
  return OK;
}

Status pushStack(Stack S, ElemType e){
  Stack n = (Stack)malloc(sizeof(Node));
  n->data = e;
  n->next = S->next;
  S->next = n;
  return OK;
}

Status popStack(Stack S, ElemType *e){
  Stack p = S->next;
  if(!p) return OVERFLOW;
  *e = p->data;
  S->next = p->next;
  free(p);
  return OK;
}

Status getValue_Stack(Stack S, ElemType *e){
  if(S->next) *e = S->next->data;
  return OK;
}

int getLength_Stack(Stack S){
  int len = 0;
  while(S->next){
    S = S->next;
    ++len;
  }
  return len;
}

Status isEmpty_Stack(Stack S){
  if(S->next) return FALSE;
  else return TRUE;
}

Status printStack(Stack S){
  if( isEmpty_Stack(S) ){
    printf("Stack is empty\n"); 
    return ERROR;
  }else{
    printf("Stack's length is %d\n",getLength_Stack(S));
  }

  //print data;
  while( S = S->next )
    printf("%c",S->data);
  printf("\n");
  return OK;
}

Status clearStack(Stack S){
  Stack p;
  while(S->next){
    p = S->next;
    S->next = p->next;
    free(p);
  }

  return OK;
}

Status destoryStack(Stack S){
  Stack pre;
  while(S){
    pre = S;
    S = S->next;
    free(pre);
  }
  return OK;
}

Status destroyStack(Stack S){
  Stack pre;
  while(S){
    pre = S;
    S = S->next;
    free(pre);
  }
  return OK;
}

