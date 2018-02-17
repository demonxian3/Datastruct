#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sgStack_str.h"

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

