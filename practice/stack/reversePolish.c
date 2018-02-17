#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sgStack.h"


Status isOperation(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '&':
        case '|':
        case '^':
        case '%': return TRUE; break;
        default:  return FALSE;
    }
    return FALSE;
}

Status isDigit(char c){
    if(c >= '0' && c <= '9') return TRUE;
    else return FALSE;
}

int calcStation(int a, int b, char o){
    printf("%d %c %d\n",a,o,b);
    switch(o){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '%': return a%b;
        case '&': return a&b;
        case '|': return a|b;
        case '^': return a^b;
    }
    return 0;
}

Status calcReversePolish(char *station, int *result){

    int i=0, t=0;
    int res,digit, popA, popB;
    char push[100];

    Stack S;
    initStack(&S);
    while(station[i] != '\n'){
        if( isDigit(station[i]) ){
            push[t++] = station[i];
        }else{
            //来到这说明读取到非数字，对之前积累读取的数字压栈
            if( t != 0 ){
                push[t] = '\0';
                digit = atoi(push);
                pushStack(S, digit);
                t = 0;
                memset(push, digit,0);
            }
            if( isOperation(station[i]) ){            //若为操作符，出栈两个计算结果压栈
                if(popStack(S, &popA)) return FALSE;  //若堆栈为空，返回错误
                if(popStack(S, &popB)) return FALSE;
                res = calcStation(popB, popA, station[i]); //堆栈影响数字顺序，颠倒一次计算
                pushStack(S, res);
            }
        }
        i++;
    }//while

    popStack(S, result);        //读取最后计算的结果
    if( !isEmpty_Stack(S) ){
        printf("result error \n");
        return FALSE;
        *result = 0;
    }
    return TRUE;
}

int main(){
    int res;
    char RPS[100];      //Reverse Polish Station
    printf("Enter a RPS: ");

    fgets(RPS, 100, stdin);

    if(calcReversePolish(RPS,&res))
        printf("[Result]: %d\n",res);
    else
        printf("[Error]: Station Invalid\n");
    

    //char c;
    //printf("enter test c:");
    //c = getchar();
    //if(isDigit(c)){
    //    printf("isdigit\n");
    //}else{
    //    printf("isn't\n");
    //}
}


// Reverse Polish Station
// 说明：合法的逆波兰表达式在每个元素间必须空格隔离
// 如: 37 41 +
// 若无空格无法区分位数如: 3741+
//
// 计算逆波兰原理：
// 读取字符串，检测每个字符
// 若为数字，存储, 但不立刻压栈，等相邻数字读取完才压栈
// 若为非数字字符，如空格，对之前读取的数字字符串末尾填上
// 结束符'\0'压栈, 重置字符串变量和索引为下次读数字取做准备
//
// 若为符号，出栈两元素计算其值，再将计算结果压栈
//
// 若出现堆栈弹不出元素计算，或表达式检测完毕后堆栈不为空
// 那么函数返回FALSE表示逆波兰表达式有问题.
//
// Example: 
// Enter a RPS: 25 5/10 + 7a% hello 10 ^ 35 97 & | 68 + 6 *
// [Result]: 666
//
// 注意：这里没有对字母进行处理，所以读取到字母时直接无视了
// 也算是增加了容错率吧
