#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STACKLEN 100
#define TRUE 1
#define FALSE 0
#define ERROR 1
#define OK 0
#define OVERFLOW -2

typedef char *ElemType;
typedef int Status;
typedef struct Node{
    ElemType data;
    struct Node *next;
} Node, *Stack;

/*      Stack Libary    */
Status initStack(Stack *S){
    *S = (Stack)malloc(sizeof(Node));
    (*S)->data = (char*)malloc(sizeof(char)*STACKLEN);
    (*S)->next = NULL;
    return OK;
}

Status isEmpty_Stack(Stack S){
    if(!S && !S->next) return TRUE;
    return FALSE;
}

Status pushStack(Stack S,ElemType e){
    Stack n;
    initStack(&n);
    int i = 0;
    while(e[i] != '\0'){
        n->data[i] = e[i];
        i++;
    }
    n->next = S->next;
    S->next = n;
    return OK;
}

Status popStack(Stack S,ElemType *e){
    if(isEmpty_Stack(S)){
        printf("Stack is empty!\n");
        return ERROR;
    }

    Stack t = S->next;
    strcpy(*e,t->data);
    S->next = t->next;
    free(t);
    return OK;
}


char *getTopValue(Stack S){
    if(S->next) return S->next->data;
    else return NULL;
}

int getLength_Stack(Stack S){
    int i = 0;
    while(S->next){
        i++;
        S = S->next;
    }
    return i;
}

void printStack(Stack S){
    if(isEmpty_Stack(S)){
        printf("Stack is Empty\n");
        return ;
    }
    while(S->next){
        printf("%s ",S->next->data);
        S = S->next;
    }
    printf("\n");
}

int main(){
    int c;
    Stack S;
    char push[100];
    initStack(&S);
    printStack(S);
    
    //push
    printf("Enter push string: ");
    scanf("%s",push);
    pushStack(S,push);
    printStack(S);

    //push
    printf("Enter push string: ");
    scanf("%s",push);
    pushStack(S,push);
    printStack(S);
    //push
    printf("Enter push string: ");
    scanf("%s",push);
    pushStack(S,push);
    printStack(S);
    //push
    printf("Enter push string: ");
    scanf("%s",push);
    pushStack(S,push);
    printStack(S);
    //push
    printf("Enter push string: ");
    scanf("%s",push);
    pushStack(S,push);
    printStack(S);

    //pop
    char *str = (char*)malloc(sizeof(char)*100);
    popStack(S,&str);
    printf("pop Value: %s\n",str);
    printStack(S);

    //pop
    popStack(S,&str);
    printf("pop Value: %s\n",str);
    printStack(S);
    //pop
    popStack(S,&str);
    printf("pop Value: %s\n",str);
    printStack(S);
}

