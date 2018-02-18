#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

#define STACKLEN 100

typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType *base;
    ElemType *top;
} Sqstack;

Status initStack(Sqstack *S){
    S->top = S->base = (ElemType*)malloc(STACKLEN * sizeof(ElemType));
    return OK;
}

Status stackEmpty(Sqstack S){
    if(S.top == S.base)return OK;
    else return ERROR;
} 

Status stackLength(Sqstack S){
    int count = S.top - S.base;
    return count;
}

Status getTopValue(Sqstack S, ElemType *e){
    *e = *(S.top-1);
    return OK;
}

Status pushStack(Sqstack *S, ElemType e){
    if(stackLength(*S) == STACKLEN ) return ERROR;
    *(S->top++) = e ;
    return OK;
}

Status popStack(Sqstack *S, ElemType *e ){
    if(stackEmpty(*S)) return ERROR;
    *e = *(--S->top);
    return OK;
}

Status printStack(Sqstack S){
    if(stackEmpty(S)) {
        printf("Stack is Empty\n");
        return ERROR;
    }
    printf("Stack len is %d \n", stackLength(S));
    while(S.base < S.top)
        printf("%d ",*(S.base++));
    printf("\n");
    return OK;
}


