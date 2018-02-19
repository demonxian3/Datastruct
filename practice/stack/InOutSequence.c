//问:通过入栈顺序的堆栈，出栈后能否得到出栈顺序串
////如:入栈顺序：ABCDEFG
////   出栈顺序：BAEDFGC
////返回: TRUE
////
////如:入栈顺序：ABCD
////   出栈顺序：ADBC
////返回: FALSE
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sgStack.h"

Status isPossible(char *In, char *Out, int len){

    int i=0, j=0, noUse;
    Stack S;
    initStack(&S);

    while( i<(len-1) && j<(len-1) ){
        if(In[i] == Out[j]){            //如果相同比较下一个元素
            i++;
            j++;
        }else{                          //如果不同，和栈顶比较
            if(!isEmpty_Stack(S) && Out[j] == In[getTopValue(S)]){
                popStack(S,&noUse);
                j++;
            }else{                      //栈顶为空或不同，压栈
                pushStack(S,i);
                i++;
            }
        }
    }

    while(j<i && !isEmpty_Stack(S)){
        popStack(S,&noUse);
        if( Out[j++] != In[noUse] ) return FALSE;
    }

    if( i == j && j == (len-1) && isEmpty_Stack(S) )return TRUE;
    else return FALSE;
}


int main(){
    char InStr[100],OutStr[100];

    printf("Enter InStack sequence: ");
    fgets(InStr,100,stdin);
    printf("Enter OutStack sequence: ");
    fgets(OutStr,100,stdin);

    int len = strlen(InStr);
    if(len != strlen(OutStr)) {
        printf("InStack and OutStr's length is diffent\n");
        return OK;
    }

    if(isPossible(InStr, OutStr, len)){
        printf("Sequence is OK! \n");
    }else{
        printf("Sequence is no possible\n");
    }
    return OK;
}
