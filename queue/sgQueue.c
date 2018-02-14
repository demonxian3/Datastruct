#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "sgQueue.h"


int main(){
  int val;
  char sel;
 
  Queue Q;
  initQueue(&Q);
  createQueue(Q,10);
  
  while(1){
    system("clear");
    printQueue(Q);
    printf("enter you choose[e|d|D]:");
    sel = getchar();

    if(sel == 'e'){
      printf("enter value:");
      scanf("%d",&val);
      getchar();
      enQueue(Q,val);
    }

    else if(sel == 'd'){
      deQueue(Q,&val);
      printf("value is %d\n",val);
      getchar();
      sleep(1);
    }
  
    else if(sel == 'D'){
      destoryQueue(&Q);
    }
  } 
}
