//寻找两个链表的公共节点，注意是节点不是相同值
//输入 L1:  1->3->3->7->2->3->5->8->1->2
//输入 L2:        1->4->8->3->5->8->1->2
//输出 5


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sgLink_EXT.h"

//当两个链表等长，那么等位置向后比较即可
//如果不等长，长链表前面多出的部分一定不存在公共节点
//假设长链表前面的部分存在公共节点，则公共节点长度会
//大于短链表，短链表里不可能存在公共节点，长度又比公
//共节点小，所以长链表前面的比短链表多出的部分不存在
//公共节点。
Link findCommonNode(Link A, Link B){
  int i,count;
  Link p ,q;
  p = q =NULL;
  int A_len = getLength_Link(A);
  int B_len = getLength_Link(B);
  
  count = A_len - B_len;	//计算空转次数

  if(count < 0){		//找到较长的链表
    p = B->next;		//p为长链表
    q = A->next;		//q为短链表
    count = -count;
  }else{ 
    p = A->next;		//头结点不考虑
    q = B->next;
  }

  for(i=0; i<count; i++)	//长链表多出的部分一定不存在公共节点，直接进行空转向后移动
    p = p->next;
    
  while(p && q){
    if( p == q ) return p;	//比较发现是公共节点，直接返回，注意不能比较值，因为值相等
				//的节点next指针不一定相同，所以需要比较结构域的地址值
    p = p->next;		//齐头并进
    q = q->next;		
  }
  
  return NULL;
}

int main(){
  int n,m,i;
  Link A,B,C,D,common,p;

  initLink(&A);
  initLink(&B);
  initLink(&C);
  initLink(&D);

  printf("输入公共链表：");
  createNode_TI(C, 4, 0);

  //A和B 非公共部分数据创建
  printf("输入链表A：");
  createNode_TI(A,7,0);
  printf("输入链表B：");
  createNode_TI(B,3,0);

  //创建无公共部分的链表数据
  printf("输入链表D：");
  createNode_TI(D,11,0);

  //连接A和C  B和C
  p = A;
  while(p->next)p=p->next;
  p->next = C->next;

  p = B;
  while(p->next)p=p->next;
  p->next = C->next;


  //打印输出：
  printf("公共链表： ");
  printLink(C);
  printf("A链表： ");
  printLink(A);
  printf("B链表： ");
  printLink(B);
  printf("D链表： ");
  printLink(D);
  common = findCommonNode(A,B);
  if(common)
    printf("A,B链表的公共节点：%d\n",common->data);
  else
    printf("A,B链表没有公共节点\n");
  
  common = findCommonNode(A,D);
  if(common)
    printf("A,D链表的公共节点：%d\n",common->data);
  else
    printf("A,D链表没有公共节点\n");
  
  destroyLink(&A);
  destroyLink(&B);
  destroyLink(&C);
  destroyLink(&D);
  
  return OK;
}
