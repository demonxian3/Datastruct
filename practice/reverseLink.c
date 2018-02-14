//链表相加
//输入 2->4->3  5->6->4
//输出 8->0->7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sglink.h"



int main(){
  int n,m,i;
  Link L1,p;
  initLink(&L1);

  //创建测试数据
  createNode_HI(L1, 10, 1);
  printLink(L1);

  //全翻转
  reverseLink(&L1);
  printLink(L1);

  //部分翻转
  printf("Enter begin number for reversing: ");
  scanf("%d",&m);
  printf("Enter end number for reversing: ");
  scanf("%d",&n);

  //翻转前输出蓝色
  i = 1;
  p = L1->next;
  while(p){
    if(i == m)printf("\033[44m");
    if(i > n) printf("\033[0m");
    printf("[%2d] ",p->data);
    p=p->next;
    ++i;
  }
  printf("\n");

  if(reverseLink_partly(&L1,m,n)){
    printf("The parameter in begin number or end number or both is error\n");
  }

  
  //翻转后输出红色
  i = 1;
  p = L1->next;
  while(p){
    
    if(i == m)printf("\033[41m");
    if(i > n) printf("\033[0m");
    printf("[%2d] ",p->data);
    p=p->next;
    ++i;
  }
  printf("\033[0m\n");

  destroyLink(&L1);
  
  return OK;
}
