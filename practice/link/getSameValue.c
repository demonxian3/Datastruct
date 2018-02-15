//寻找链表相同的值
//输入 L1: 22->43->31->14->22->76
//     L2: 43->33->81->22
//输出 43 22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sgLink_EXT.h"

typedef struct Rnode{		//记录两个链表
  ElemType data;
  int count;
  struct Rnode *next;
} Rnode, *Record;

int main(){
  int n,m,i;
  Link L1,L2,p;
  initLink(&L1);
  initLink(&L2);


  //创建测试数据
  createNode_HI(L1, 20, 0);
  printLink(L1);

  //创建测试数据
  createNode_HI(L2, 10, 1);
  printLink(L2);

  //获取相同值
  p = getSameValue(L1,L2);
  printLink(p);

  destroyLink(&L1);
  
  return OK;
}
