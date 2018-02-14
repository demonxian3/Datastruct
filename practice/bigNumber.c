//链表相加
//输入 2->4->3  5->6->4
//输出 8->0->7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sglink.h"

#define  DIGITBIT	1000000    //每个节点存储多少位，1000000表示存储6位长数字

void storageInLink(Link L, long long digit){

  while(digit){
    Link n = (Link)malloc(sizeof(Node));
    n->data = digit % DIGITBIT;			//高位低位颠倒存储，好处是方便计算
    digit /= DIGITBIT;				//因为当前处理若进一位，就可以通过next指针
    L->next = n;				//找到高位，并让其加一
    L = n;
  }
}

Link mergeLink(Link A,Link B){

  int sum = 0;
  int needCarry = 0;	//是否进位

  int A_len = getLength_Link(A);
  int B_len = getLength_Link(B);

  int i = A_len > B_len ? A_len : B_len; //比较长度，取大作为计数器

  A = A->next;		//忽略头结点
  B = B->next;		//忽略头结点

  Link R;		//R为合并A和B之后的链表,p为浮游指针
  initLink(&R);		//为R初始化创建头结点
  
  while(i--){
    Link n = (Link)malloc(sizeof(Node));

    sum = 0;
    if(A) sum += A->data;
    if(B) sum += B->data;
    sum += needCarry;		//加上上次计算的进位

    n->data = sum % DIGITBIT;
    needCarry = sum / DIGITBIT;	//超过十进位，下次多加一

    n->next = R->next;	//使用头插法，好处就是数字颠倒回来了，方便编写。
    R->next = n;

    if(A) A = A->next;	//合并下一位
    if(B) B = B->next;
  }

  if(needCarry){	//最后处理完又进一位
    Link n = (Link)malloc(sizeof(Node));
    n->data = 1;
    n->next = R->next;
    R->next = n;
  }

  return R;
}

int main(){
  int n,m;
  long long digit1,digit2;
  Link L1,L2;
  initLink(&L1);
  initLink(&L2);

  //手动输入
  //printf("Enter first digit: ");
  //scanf("%lld",&digit1);
  //
  //printf("Enter second digit: ");
  //scanf("%lld",&digit2);
  

  //随机生成
  srand(time(0));
  digit1 = rand();
  digit2 = rand();

  storageInLink(L1,digit1);
  printLink(L1);
  storageInLink(L2,digit2);
  printLink(L2);


  Link L3 = mergeLink(L1,L2); 

  while(L3 = L3->next) printf("%d",L3->data);
  printf("\n");

  destroyLink(&L1);
  destroyLink(&L2);
  destroyLink(&L3);
  
  return OK;
}
