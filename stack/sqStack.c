#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sqStack.h"

#define DELAY 1

int main(){
  Sqstack stack;
  ElemType value;
  initStack(&stack);

  while(1){
    system("clear");
    printf("p = push\nq = pop\n");
    printf("g = get\ne = exit\n");

    printStack(stack);
    printf("enter a your choose:");
    char sel = getchar();

    if( sel == 'p'){
       printf("enter push value:");
       scanf("%d",&value);
       pushStack(&stack,value);
    }
    
    else if(sel == 'q'){
       popStack(&stack,&value);
       printf("value:%d is poped\n",value);
       sleep(DELAY);
    }
  
    else if(sel == 'g'){
       getTopValue(stack,&value);
       printf("value is %d\n",value);
       sleep(DELAY);
    }

    else if(sel == 'e'){
       exit(0);
    }

  }
}

