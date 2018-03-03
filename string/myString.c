#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define TEST_STR_LEN 44

int main(){
    char c;
    char tst[TEST_STR_LEN];
    char tsn[TEST_STR_LEN];
    char str[TEST_STR_LEN];

    //test for function readLine myStrlen
    printf("Enter a string: ");
    int len  = readLine(str, sizeof(str));
    printf("[str] %s\nlen:%d mylen:%d\n", str, len, myStrlen(str));

    //test for function myStrcpy myStrlen
    //It is danger when myStrlen(str) > sizeof(tst)
    printf("[tst] %s\n", myStrcpy(tst, str));   
    printf("mylen:%d\n", myStrlen(tst));


    //test for function myStrncpy
    int readNum;
    printf("Enter len for strncpy: ");
    scanf("%d",&readNum);
    printf("[tsn] %s\n", myStrncpy(tsn, tst, readNum));
    printf("mylen:%d\n", myStrlen(tsn));

    //test for function myStrcat
    printf("[tsn]%s\n", myStrcat(tsn," ,Oh My God!"));

    //test for function myStrncat
    printf("[tsn]%s\n", myStrncat(tsn," ,Oh My God!",4));

    //test for function countChar;
    //printf("Enter a character: ");
    //c = getchar();
    //printf("%c in \"%s\" have %d counts\n",c,str,countChar(str, c));

}

