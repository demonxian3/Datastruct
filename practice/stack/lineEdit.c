#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sgStack_char.h"

Stack lineEdit(char *str){

    int i = 0;
    char c;
    Stack S ;
    initStack(&S);

    while(str[i] != '\n'){
        if(str[i] == '@')
            popStack(S,&c);

        else if(str[i] == '#'){
            pushStack(S,' ');
            pushStack(S,' ');
            pushStack(S,' ');
        }
        else
            pushStack(S,str[i]);
        i++;
    }
    
    return S;
}

int main(){
    int i;
    char c,str[100];

    while(1){
        i=0;
        printf("Enter the string[# space, @ del]: ");
        fgets(str,100,stdin);
        Stack S = lineEdit(str);

        memset(str,0,100);
        while(!isEmpty_Stack(S))
            popStack(S,&str[i++]);   

        for(--i; i>-1; --i)
            printf("%c",str[i]);
        printf("\n");
    }
    free(str);
    return 0;
}
