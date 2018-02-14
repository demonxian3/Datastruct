#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sgstack.h"

int main(){
  int v,i,e;
  char c;
  Stack S;
  initStack(&S);
  createStack(S,10,1);

  while(1){
    system("clear");
    printStack(S);
    printf(" p  push   \n");
    printf(" q  pop    \n");
    printf(" v  value  \n");
    printf(" l  length \n");
    printf("Enter a command: ");
    c = getchar();

    if(c == 'p'){
      printf("Enter value: ");
      scanf("%d",&v);
      pushStack(S,v);
      getchar();
    }
 
    else if(c == 'q'){
      popStack(S,&v);
      printf("pop value is %d\n",v);
      sleep(1);
    }

    else if(c == 'v'){
      getValue_Stack(S,&e);
      printf("get value is %d\n",e);
      sleep(1);
    }

    else if(c == 'l'){
      printf("Stack's length is %d\n",getLength_Stack(S));
      sleep(1);
    }
  }
}
