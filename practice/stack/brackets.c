#include <stdio.h>
#include <stdlib.h>
#include "sgStack_char.h"

Status isMatchBrackets(char lef, char rig){
    switch(rig){
        case ')': if(lef == '(') return TRUE;break;
        case '}': if(lef == '{') return TRUE;break;
        case ']': if(lef == '[') return TRUE;break;
        default: return FALSE;
    }
    return FALSE;
}

Status isLeftBrackets(char c){
    switch(c){
        case '(': return TRUE;break;
        case '{': return TRUE;break;
        case '[': return TRUE;break;
        default: return FALSE;
    }
    return FALSE;
}

Status isRightBrackets(char c){
    switch(c){
        case ')': return TRUE;break;
        case '}': return TRUE;break;
        case ']': return TRUE;break;
        default: return FALSE;
    }
    return FALSE;
}

//括号匹配原理：检测字符串，遇到左括号则压栈
//遇到右括号，弹出堆栈，查看是否匹配，若弹出
//之前堆栈为空，返回匹配失败，若字符串检测完
//毕堆栈不为空，返回检测失败
Status checkBrackets(char str[]){
    int i=0;
    char a,b;
    Stack S;
    initStack(&S);

    while(str[i] != '\n'){
        if(isLeftBrackets(str[i]))
            pushStack(S,str[i]);    //存储左括号
        else if(isRightBrackets(str[i])){
            if(isEmpty_Stack(S))
                return FALSE;
            popStack(S,&a);         //弹出左括号
            if(!isMatchBrackets(a,str[i]))      //左右括号是否匹配
                return FALSE;
        }
        i++;
    }
    return isEmpty_Stack(S);
}

int main(){
  char str[100];
  while(1){
    printf("enter a string:");
    fgets(str,100,stdin);
    if(checkBrackets(str))printf("Match!!\n");
    else printf("doesn't match\n");
  }
  
  return 0;
}
