#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创造二叉树思路：先对当前结点赋值，再递归左右结点赋值
//使用递归传递的话，字符串标准输入不能在递归的函数进行
//通过指针运算将字符串首指针向后移动一位，并传递给函数
//第一个问题：左右孩子必须提前分配空间，否则无法关联
//第二个问题：指针不能只前不退，在递归返回时也会回滚当初状态
//解决方法：利用二叉树线性存储规律来获取孩子结点的偏移量
//每次递归时将偏移量也给带上，即在函数形参添加一个变量。

typedef char ElemType;
typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

void visit(ElemType e){
  printf("%c ",e);
}

void InOrder(BitTree T){
  if(T){
    InOrder(T->lchild);
    visit(T->data);
    InOrder(T->rchild);
  }
}

void preOrder(BitTree T){
  if(T){
    visit(T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
  }
}

void postOrder(BitTree T){
  if(T){
    postOrder(T->lchild);
    postOrder(T->rchild);
    visit(T->data);
  }
}

//创造完全二叉树原理：
/* 
   value  是标准输入的字符串
   index  是储存字符串数组的下标
   offset 是寻找左右孩子的偏移量   

   index: 0    1    2    3    4    5    6    7    8    9    10
   value: A    B    C    D    E    F    G   ' '  ' '  ' '  '  '
   offse: 1,2  2,3  3,4  4,5  5,6  6,7  7,8  ..................

   注意：偏移量表示寻找自己孩子的增量，即加上自己的index便可以寻左右孩子
   
   孩子位置计算：
   pos = index + offset  //因为有左右孩子，所以每个结点都有两个offset
   
   偏移量的计算：
     如果自己对于双亲来说是左孩子：
     offset(left) = offset(Parent) * 2     //即双亲结点的左偏移量x2
     offset(right) = offset(left) + 1      //右偏移量则为左偏移量基础上+1

     如果自己对于双亲来说是右孩子：
     offset(left) = offset(Parent) * 2 + 1 //即双亲结点寻找首孩子的偏移量x2再+1
     offset(right) = offset(left) + 1       //右偏移量则为左偏移量基础上+1
   
   比如说：
     1.寻找B结点的两个孩子：
         B结点当前的位置是1，
         B结点左孩子偏移量是2,
         所以左孩子的位置是 1 + 2 = 3，即D结点是B结点的左孩子
         B结点右孩子偏移量是3,
         所以右孩子的位置是 1 + 3 = 4，即E结点是B结点的右孩子

     2.计算C结点的两个偏移量：
         C结点是A结点的右孩子，也是B的兄弟结点
         A结点的左孩子的偏移量是1,通过他可以找到左孩子B
         B结点左偏移量是 1 × 2，C结点的左偏移量是 1 x 2 + 1
         所以，C结点的左偏移量为 1 x 2 + 1     = 3
         所以，C结点的右偏移量为 1 x 2 + 1 + 1 = 4
*/

//递归回滚：递归后对指针的修改在return之后不影响当前的指针
void createNode(BitTree T,ElemType *s,int offset){
  //如果字符串数组长度为0退出递归。
  if(!strlen(s))return;

  if(*s!='\n'){
    if(*s!=' '){
      //这里会发生递归回滚
      T->data = *(s);
      T->lchild = (BitTree)malloc(sizeof(BitNode));
      T->rchild = (BitTree)malloc(sizeof(BitNode));

      //通过树的线性规律计算offset来获得儿子所在字符串的偏移量
      s+=offset;  
      if(*s==' ')return;  //若儿子的字符串为空，那么return

      createNode(T->lchild,s,offset*2);
      s++;        
      createNode(T->rchild,s,offset*2+1);
    }else{
      T=NULL;  //若根结点字符串为空,树set为NULL
    }
  }
  return;
}

void createTree(BitTree T){
  char str[100];
  printf("enter a string:");
  fgets(str,100,stdin);      //输入每个结点的值
  createNode(T,str,1);

  printf("[InOrder]: ");
  InOrder(T);
  printf("\n");

  printf("[preOrder]: ");
  preOrder(T);
  printf("\n");


  printf("[postOrder]: ");
  postOrder(T);
  printf("\n");
  return ;
}

int main(){
  int num;
  BitTree T = (BitTree)malloc(sizeof(BitNode));
  createTree(T); 
  return 0;
}
