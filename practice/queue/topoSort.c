#include <stdio.h>
#include <stdlib.h>
#include "adjMatrix.h"
#include "sgQueue.h"

typedef struct Node{
  int data;
  struct Node * next;
} Node ,*Link;

void printLink(Link L);

void initLink(Link *L){
  *L =(Link)malloc(sizeof(Node));
  (*L)->next = NULL;
  return ;
}

Link newNode(ElemType e){
  Link n = malloc(sizeof(Node));
  n->data = e;
  n->next = NULL;
  return n;
}

Link topoSort(MGraph G){
  int i,j;
  ElemType t;
  int indegree[G.vexnum], isshow[G.vexnum];
  for(i=0; i<G.vexnum; i++)		//初始化入度数组
    indegree[i] = 0;

  for(i=0; i<G.vexnum; i++)		//初始化输出标记数组
    isshow[i] = 0;

  for(i=0; i<G.vexnum; i++)		//计算邻接表入度
    for(j=0; j<G.vexnum; j++)
      if(G.acrs[j][i])indegree[i]++;

  Link L;
  Queue Q;
  initLink(&L);
  initQueue(&Q);
  Link p = L;

  for(i=0; i<G.vexnum; i++){		//寻找入度为0的元素
    if(indegree[i] == 0) 
        if(!isshow[i])enQueue(Q,i);

    while(!isEmpty(Q)){
      deQueue(Q,&t);
      
      if(!isshow[t]){			//如果没输出过，加入链表
         Link n = newNode(t);
	 n->next = p->next;		//尾插法
         p->next = n;
         p = n;
         isshow[t] = 1;
      }
     
      for(j=0;j<G.vexnum;j++)
        if(G.acrs[t][j])
          if(--indegree[j] == 0)
            enQueue(Q,j);
    }//while
  }//for

  return L;
} 

void printLink(Link L){
  if(!L) return;
  Link p = L->next;
  int i = 0;			//防止无线输出
  while(p && ++i < 100){
    printf("%d ",p->data);
    p = p->next;
  }
  printf("\n");
}

int main(){ 
  MGraph G = createGraph(1,0);
  printGraph(G);
  Link r = topoSort(G);
  printLink(r);
  return 0;
}
