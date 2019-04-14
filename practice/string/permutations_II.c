#include <stdio.h>
#include <stdlib.h>

void reverse(int *, int, int );
void printArr(int *, int);
void permutation(int *, int);
int factorial(int );

int main(){
    int arr[] = {1,2,3,4,5};
    permutation(arr, 5);

}

void permutation(int arr[], int size){
    int n = 0;
    int m = factorial(size);

    while(n++ < m){
        printArr(arr, 5);
        int i = size - 2;
        //后找
        while( i>0 && *(arr + i) > *(arr + i + 1)) i--;

        //查找
        int j = i + 1;
        while( j < size && *(arr + j) > *(arr + i)) j++;

        --j;

        //交换
        int t = arr[i];
        *(arr + i) = *(arr + j);
        *(arr + j) = t;

        //翻转
        reverse(arr, i+1, size-1);
    }
}

void printArr(int arr[], int size){
    int i = 0;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverse(int arr[], int begin, int end){
    int i = begin;
    int n = end;
    while(i < n){
        int tmp = *(arr + i);
        *(arr + i++) = *(arr + n);
        *(arr + n--) = tmp;
    }
}

int factorial(int s){
    if(s == 1)return 1;
    else return factorial(s-1) * s;
}
