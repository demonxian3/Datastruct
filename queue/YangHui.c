#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "sgQueue.h"

void YangHui(int row){
  int i,j,e,s,p;
  Queue Q;
  initQueue(&Q);
  
  enQueue(Q,1);
  for(i=1; i<=row; i++){
    s = 0;
    enQueue(Q,1);
    for(j=0; j<=i; j++){
      deQueue(Q,&p);
      printf("%d ",p);
      enQueue(Q,s+p);
      s=p;
    }
    printf("\n");
  }
}

int main(){
  int row;
  printf("Enter the row: ");
  scanf("%d",&row);
  YangHui(row);
}
