#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "sgQueue.h"


void YangHui(int row){
    Queue Q;
    initQueue(&Q);

    int n, i, s, t;
    i = s = 0;
    n = 1;

    enQueue(Q,1);
    enQueue(Q,1);
    while(!isEmpty(Q)){
        deQueue(Q,&t);
        printf("%d ",t);

        if(n == row+1)
            break;


        if(i == n-1) printf("\n");

        if(i == n){
            printf("\n");
            enQueue(Q,1);
            i = s = 0;
            n++;
            continue;
        }

        enQueue(Q, s+t);
        s = t;
        i++;

    }
}

int main(){
  int row;
  printf("Enter the row: ");
  scanf("%d",&row);
  YangHui(row);
}
