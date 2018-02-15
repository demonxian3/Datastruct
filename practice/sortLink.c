//链表相加
//输入 2->4->3->1->2->7
//输出 1->2->2->3->4->7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sglink.h"



int main(){
  int n,m,i;
  Link L1,p;
  initLink(&L1);

  printf("Enter test number: ");
  scanf("%d",&n);

  //创建测试数据
  createNode_HI(L1, n, 1);
  printLink(L1);

  //快速排序
  sortLink(&L1);
  printLink(L1);

  destroyLink(&L1);
  
  return OK;
}
