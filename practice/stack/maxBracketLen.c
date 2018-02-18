#include <stdio.h>
#include <stdlib.h>
#include "sgStack.h"                            //存储索引的数组

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

int max(int a, int b){
    return a>b?a:b;
}

int checkBracketsMaxLength(char str[]){
    int a,i,anwser,start;
    Stack S;

    start = -1;
    anwser = i = 0;
    initStack(&S);

    while(str[i] != '\n'){
        if(isLeftBrackets(str[i]))              //左括号压栈
            pushStack(S,i);                     //压索引方便计算长度              
        else{                                   //右括号出栈
            if(isEmpty_Stack(S)){
                start = i;
                ++i;
                continue;                       //栈空继续考察
            }else{                              //栈不空弹出
                popStack(S,&a);
                if(isMatchBrackets(str[a],str[i])){ //匹配了
                    if(isEmpty_Stack(S))
                        anwser = max(anwser,i-start);
                    else
                        anwser = max(anwser,i-getTopValue(S));
                }
                else {                              //失配了
                    start = i;
                    clearStack(S);          
                }   
            }   
        }
        i++;
    }
    return anwser;
}

int main(){
  char str[100];
  while(1){
    printf("enter a string:");
    fgets(str,100,stdin);
    int len = checkBracketsMaxLength(str);
    printf("length is %d\n",len);
  }
  
  return 0;
}

//求解最大连续括号匹配子串长度 
//enter a string:(([)))             //遇到这种情况，不匹配就直接清空堆栈
//length is 0
//enter a string:(([[]}))
//length is 2
//enter a string:[(){()]]           //遇到这种情况，需要通过索引差值来求
//length is 2
//enter a string:(()(()))
//length is 8
//enter a string:(()(())
//length is 6
//enter a string:(()[(())
//length is 4
//
//索引差值求法：
//检索一个字符，如果是左括号，压栈
//如果是右括号，判断堆栈是否为空
//      如果堆栈为空，让开始索引移动到当前位置 start = cur
//      如果堆栈不空，弹出字符索引，判断是否匹配
//          如果匹配，判断弹出后的堆栈是否为空
//              如果不空，长度为 maxlen = max(maxlen,start - cur);
//              如果为空，长度为 maxlen = max(maxlen,start - S.top);
//          如果失配，清空堆栈，开始索引移动当前位置 start = cur
//注意：堆栈存储索引，不存储字符，start 初始值为-1
