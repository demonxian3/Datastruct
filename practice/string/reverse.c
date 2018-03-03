//给定一个字符串S[0-N-1], 要求将前k个字符移动到S的尾部
//比如 abcdef 移动前两个字符得到  cdefab
//如果暴力匹配需要O(n^m) 指数级时间复杂度，显然不可取
//利用转置技巧可以降时间复杂度：
//ab 转置 ba
//cdef 转置 fedc
//bafedc 转置 cdefab

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLEN 500

void transpose(char *str, int from, int to){
    while(from < to){
        char tmp = *(str + from);
        *(str + from++) = *(str + to);
        *(str + to--) = tmp;
    }
}

char* moveToEnd(char *str, int len, int head){
    transpose(str, 0, head);
    transpose(str, head+1, len-1);          //last is '\0'
    transpose(str, 0, len-1);
    return str;
}

int main(){

    char str[STRINGLEN];
    int i=0,head;

    printf("Enter test string: ");
    fgets(str,STRINGLEN,stdin);
    printf("Enter number of head: ",str);
    scanf("%d",&head);

    head -= 1;                          //head begin from 1

    while(str[i] != '\0')i++;
    printf("%d" ,i);
    if(head >= i-1 || head < 0 || head > STRINGLEN){
        printf("your enter number of head of str is invalid\n");
        return EXIT_FAILURE;
    }

    char *res = moveToEnd(str, i-1, head);      //i-1 = last index for the string 
    printf("Result: %s", res);
    return EXIT_SUCCESS;
    
}


