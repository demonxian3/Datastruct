//LCS: 公共最长子序列
//input:  abcdefg
//input:  cxkdffg
//output: cdfg

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myInput.h"

#define STRING_LEN 50
void LCS(char *s1, char *s2);
int max(int a, int b){return a>b?a:b;}

int main(){
    char str1[STRING_LEN];
    char str2[STRING_LEN];

    *str1 = *str2 = '0';        //从1开始用，方便写代码

    INPUT(STR, str1+1, "Enter a string: ");
    INPUT(STR, str2+1, "Enter a string: ");

    printf("%s\n",str1+1);
    printf("%s\n",str2+1);

    LCS(str1, str2);
}

void LCS(char *s1, char *s2){
    int n = strlen(s1);
    int m = strlen(s2);

    printf("n is %d\n", n);
    printf("m is %d\n", m);

    int chess[n][m];       //矩阵存储LSC信息   

    int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            chess[i][j] = 0;

    for(i = 1; i < n; i++)
        for(j = 1; j < m; j++){
            if(s1[i] == s2[j]){
                chess[i][j] = chess[i-1][j-1] + 1;
            }
            else{
                chess[i][j] = max(chess[i-1][j], chess[i][j-1]);
            }
        }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++)
            printf("%d ",chess[i][j]);
        printf("\n");
    }

    // i = n , j = m    in here
    int maxlen = chess[i-1][j-1];
    char LCS_res[maxlen+1];

    int k = maxlen - 1;
    i--, j--;
    while( i != 0 && j != 0 ){
        if( *(s1 + i) == *(s2 + j) ){        //chess value is from the left-top
            LCS_res[k--] = *(s1 + i);
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

    LCS_res[maxlen] = '\0';
    printf("LCS: %s\n", LCS_res);

}


