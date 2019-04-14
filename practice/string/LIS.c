//LIS: 最长公共递增子序列
//input: 567128
//output: 5678
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myInput.h"

#define NUMBER_LEN 50
void LIS(int *s1, int *s2, int len);
int max(int a, int b){return a>b?a:b;}

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int len,i;
    INPUT(INT, &len, "Enter test len:");
    
    int num1[NUMBER_LEN], num2[NUMBER_LEN];

    for(i = 0; i < len; i++)
        INPUT(INT, (num1+i),"");

    for(i = 0; i < len; i++)
        num2[i] = num1[i];

    qsort(num2, 6, sizeof(int), compare);

    PRINTI_ARR(num1,len);
    printf(CR);
    LIS(num1, num2, len);
}

void LIS(int *s1, int *s2, int len){

    int i, j;
    int chess[len+1][len+1];  

    s1 -= 1;
    s2 -= 1;

    for(i = 0; i <= len; i++)
        for(j = 0; j <= len; j++)
            chess[i][j] = 0;

    for(i = 1; i <= len; i++)
        for(j = 1; j <= len; j++){
            if(s1[i] == s2[j]){
                chess[i][j] = chess[i-1][j-1] + 1;
            }
            else{
                chess[i][j] = max(chess[i-1][j], chess[i][j-1]);
            }
        }

    for(i = 0; i <= len; i++){
        for(j = 0; j <= len; j++)
            printf("%d ",chess[i][j]);
        printf("\n");
    }

    int maxlen = chess[i-1][j-1];

    int LIS_res[maxlen];
    int k = maxlen-1;

    i--, j--;
    while( i != 0 && j != 0 ){
        if( *(s1 + i) == *(s2 + j) ){        //chess value is from the left-top
            LIS_res[k--] = *(s1 + i);
            i--;
            j--;
        }
        else{
            if(chess[i-1][j] > chess[i][j-1])  //chess value is from the left
                i--;
            else
                j--;
        }
    }

    printf("result: ");
    PRINTI_ARR(LIS_res, maxlen);
    printf(CR);
}


