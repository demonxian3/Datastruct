#ifndef sgStack_H
#define sgStack_H
typedef int ElemType;
typedef enum{
    OK = 0,
    ERROR = 1,
    OVERFLOW = -2,
    TRUE = 1,
    FALSE = 0,
} Status;

typedef struct Node{
  ElemType data;
  struct Node * next;
} Node,*Stack;

Status initStack(Stack *);
Status isEmpty_Stack(Stack);
Status createStack(Stack, int, int);
Status pushStack(Stack, ElemType);
Status popStack(Stack, ElemType *);
Status printStack(Stack);
Status clearStack(Stack);
Status destroyStack(Stack);
Status destoryStack(Stack);
Status getValue_Stack(Stack, ElemType *);

int getLength_Stack(Stack);
int getTopValue(Stack);



Status initStack(Stack *S){
  *S = (Stack)malloc(sizeof(Node));
  (*S)->next = NULL;
  return OK;
}

Status isEmpty_Stack(Stack S){
  if(!S || !S->next) return TRUE;
  else return FALSE;
}

Status createStack(Stack S, int num, int isRand){
  srand(time(0));
  while(num--){
    Stack n = (Stack)malloc(sizeof(Node)); 
    if(isRand){
      n->data = rand()%100+1; 
    }else{
      printf("Enter Data: ");
      scanf("%d",&n->data);
    }
    n->next = S->next;
    S->next = n;
  }
}

Status pushStack(Stack S, ElemType e){
  Stack n = (Stack)malloc(sizeof(Node));
  n->data = e;
  n->next = S->next;
  S->next = n;
  return OK;
}

Status popStack(Stack S, ElemType *e){
  if(isEmpty_Stack(S)) return ERROR;
  Stack p = S->next;
  *e = p->data;
  S->next = p->next;
  free(p);
  return OK;
}

Status getValue_Stack(Stack S, ElemType *e){
  if(S->next) *e = S->next->data;
  return OK;
}

int getTopValue(Stack S){
    if(S->next) return S->next->data;
    else return -1;
}

int getLength_Stack(Stack S){
  int len = 0;
  while(S->next){
    S = S->next;
    ++len;
  }
  return len;
}


Status printStack(Stack S){
  if( isEmpty_Stack(S) ){
    printf("Stack is empty\n"); 
    return ERROR;
  }else
    printf("Stack's length is %d\n",getLength_Stack(S));

  //print data;
  while( S = S->next )
    printf("[%d] ",S->data);
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

#endif
