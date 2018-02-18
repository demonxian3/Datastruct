#include <stdio.h>
#include <stdlib.h>

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

Status initStack(Stack *S){
    *S = (Stack)malloc(sizeof(Node));
    (*S)->data = (char*)malloc(sizeof(char)*STACKLEN);
    (*S)->next = NULL;
    return OK;
}



Status isOperation(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '%': return TRUE; break;
        default: return FALSE;
    }
    return FALSE;
}

int calcStation(char *a, char o, char *b){
    int x = atoi(a);
    int y = atoi(b);

    switch(o){
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': return x/y;
        case '&': return x%y;
    }

    return FALSE;
}

Status calcReversePolish(char *station, int *result){

    int i=0,j=0;
    char num1[30],num2[30],t;
    Stack S;
    initStack(&S);

    while(station[i] != '\n'){
        if(isOperation){
            j = 0;
            memset(num1,0,30);
            memset(num2,0,30);
            popStack(S,&t);
            
            
        }
        i++;
    }
}

int main(){
    int res;
    char station[100] ;
    printf("Enter the reverse Polish station: ");
    fgets(station,100,stdin);
    if(calcReversePolish(station,&res))
        printf("result is %d\n");
    else
        printf("Invalid station\n");
}
