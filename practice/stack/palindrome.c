#include <stdio.h>
#include <stdlib.h>
#include "sgStack_char.h"

#define OK 0
#define ERROR 1
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2


Status checkPalindrome(char *str){
    char c,*p;
    Stack S;

    p = str;
    initStack(&S);

    //字符串压栈
    while(*p != '\n')
        pushStack(S, *p++);

    //字符串出栈与原生字符匹配
    while(!isEmpty_Stack(S)){
        popStack(S, &c);
        if(c != *str++) return FALSE;
    }
    return TRUE;
}

int main(){
    char text[100];

    while(1){
        printf("enter a string: ");
        fgets(text,100,stdin);

        if(checkPalindrome(text))
            printf("is palindarome\n");
        else
            printf("isn't palindarome\n");
    }
}
