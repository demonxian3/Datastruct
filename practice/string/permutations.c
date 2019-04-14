#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 4

void printARR(int *, int);
void permutation(int *, const int, int);
void swap(int *, int *);

int main(){
    int arr[] = {1,2,3,4};
    permutation(arr, 3, 0);
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
    printARR(arr, ARRAY_LEN);
    printARR(arr, ARRAY_LEN);
    if(n == len)
        printARR(arr, len+1);
    else{
        int i;
        for(i = n; i <= len; i++){
            swap(arr+i, arr+n);     
            permutation(arr, len, n+1);
            swap(arr+i, arr+n);     
        }
    }
}
