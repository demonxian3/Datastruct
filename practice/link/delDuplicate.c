//链表去重
//输入 3->7->2>2>2>-3->4->5->5->7
//输出 2->3->4->5->7


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sgLink_EXT.h"



int main(){
  int n,m,i;
  Link L1,p;
  initLink(&L1);

  printf("Enter test number: ");
  scanf("%d",&n);

  //创建测试数据
  createNode_TI(L1, n, 0);
  printLink(L1);


  //排序基础上去重
  sortLink(&L1);
  delDuplicate(L1);
  printLink(L1);

  destroyLink(&L1);
  
  return OK;
}
