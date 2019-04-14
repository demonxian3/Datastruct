#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LEN 4
typedef enum{
    TRUE = 1,
    FALSE = 0,
} Bool;

void printARR(int *, int);
void permutation(int *, const int, int);
void swap(int *, int *);
Bool isDuplicate(int *,int ,int);

int main(){
    int arr[] = {1,2,2,3};
    permutation(arr, ARRAY_LEN, 0);
}

void printARR(int *arr, int size){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", *(arr+i));
    printf("\n");
}

void swap(int *a, int *b){
    int m = *a;
    *a = *b;
    *b = m;
} 

void permutation(int arr[], const int len, int n){
    if(n == len-1)
        printARR(arr, len);
    else{
        int i,dup[256] = {0};
        for(i = n; i < len; i++){
           //检测[n,i)集合中是否存在与n相同的元素
           if(dup[arr[i]]) continue;
           //可以使用函数判断，但是花费时间多：if(isDuplicate(arr, n, i)) continue;
           dup[arr[i]] = 1;
           swap(arr+i, arr+n);     
           permutation(arr, len, n+1);
           swap(arr+i, arr+n);   
        }
    }
}

Bool isDuplicate(int arr[], int n, int i){
    while(n < i){
        if(arr[n] == arr[i]) return TRUE;
        n++;
    }
    return FALSE;
}
