#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "singleLink.h"
/************************* link.h API *******************************    
 *                                                                  *       
 *	struct	Link                                                *       
 *		Link->data	(ElemType)                          *       
 *		Link->next	(Link)                              *       
 *		ElemType	(int)                               *       
 *		Status		(int)                               *       
 *                                                                  *       
 *	Status	OK		0                                   *       
 *		ERROR		1                                   *       
 *		OVERFLOW	-2                                  *       
 *		TRUE		1                                   *       
 *		FALSE		0                                   *       
 *                                                                  *       
 *                                                                  *       
 *	初始化链表	initLink(Link *L)                           *       
 *	头插法创建节点	createNode_HI(Link L, int num, int isRand)  *       
 *	尾插法创建节点	createNode_TI(Link L, int num, int isRand)  *       
 *	                                                            *       
 *	插入节点	insertNode(Link L, int i, ElemType e)       *       
 *	追加节点	appendNode(Link L, ElemType e)              *       
 *	删除节点	deleteNode(Link L, int i, ElemType *e)      *       
 *	替换节点	replaceNode(Link L, int i, ElemType e)      *       
 *	销毁链表	destroyLink(Link *L)                        *       
 *	打印链表	printLink(Link L)                           *       
 *                                                                  *       
 *	获取长度	getLength_Link(Link L);                     *       
 *	获取节点值	getValue_Link(Link L, int i);               *       
 *	获取索引	getIndex_Link(Link L, int begin, ElemType e)*       
 *                                                                  *       
 *		                                                    *       
 ********************************************************************/         
 
void printCommand(){
  system("clear");
  printf("\n");
   printf("-----------------------------\n");
   printf("|        c = HeadInsert     |\n");
   printf("|        C = TailInsert     |\n");
   printf("|        a = append         |\n");
   printf("|        i = insert         |\n");
   printf("|        d = delete         |\n");
   printf("|        r = replace        |\n");
   printf("|        g = getValue       |\n");
   printf("|        G = getIndex       |\n");
   printf("|        l = getLength      |\n");
   printf("|        D = destroy        |\n");
   printf("|        e = exit           |\n");
   printf("=============================\n");
}


int main(){
  int e,i,n,r;
  char c;
  Link L;

  initLink(&L);

  while(1){
    printCommand();
    printLink(L);
    printf("Enter command[c|C|a|i|d|r|g|G|l|D|e]: ");
    c = getchar();
  
    if(c == 'c'){
	printf("[HeadInsert] Enter number: ");
	scanf("%d",&n);
	printf("[HeadInsert] Auto make value?[1|0]: ");
        scanf("%d",&r);
	createNode_HI(L, n, r);
	getchar();
    }

    else if(c == 'C'){
	printf("[TailInsert] Enter number: ");
	scanf("%d",&n);
	printf("[TailInsert] Auto make value?[1|0]: ");
        scanf("%d",&r);
	createNode_TI(L, n, r);
	getchar();
    }

    else if(c == 'a'){
	printf("[Append] Enter value: ");
	scanf("%d",&e);
	appendNode(L, e);
	getchar();
    }

    else if(c == 'i'){
	printf("[Insert] Enter index: ");
	scanf("%d",&i);
	printf("[Insert] Enter value: ");
	scanf("%d",&e);
	insertNode(L, i, e);
	getchar();
    }

    else if(c == 'd'){
	printf("[Delete] Enter index: ");
	scanf("%d",&i);
	deleteNode(L, i, &e);
	getchar();
	
    }

    else if(c == 'r'){
	printf("[Replace] Enter index: ");
	scanf("%d",&i);
	printf("[Replace] Enter value: ");
	scanf("%d",&e);
	replaceNode(L, i, e);
	getchar();

    }

    else if(c == 'g'){
	printf("[getValue] Enter index: ");
	scanf("%d",&i);
	printf("value is %d\n",getValue_Link(L, i));
	getchar();
	sleep(2); 
    }

    else if(c == 'G'){
	printf("[getIndex] Enter begin Index: ");
	scanf("%d",&i);
	printf("[getIndex] Enter value: ");
	scanf("%d",&e);
	printf("index is %d\n", getIndex_Link(L, i, e));
	getchar();
	sleep(2); 
    } 

    else if(c == 'l'){
	printf("length is %d\n",getLength_Link(L));
	getchar();
	sleep(2);
    }

    else if(c == 'D'){
	destroyLink(&L);
	printf("Link is destroied, bye\n");
	exit(0);
    }

    else if(c == 'e'){
	exit(0);
    }


    
  }
}
