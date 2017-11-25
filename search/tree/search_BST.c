#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild, *rchild;
}BitNode,*BitTree;

void createNode(BitTree T,int data);

BitTree createBST(int n){
  int i,data;
  
  if(n<=0)return (BitTree)NULL;

  //root
  BitTree T = (BitTree)malloc(sizeof(BitNode));
  printf("[0]data: ");
  scanf("%d",&data);
  T->data = data;

  //lchild or rchild
  for(i=1;i<n;i++){
    printf("[%d]data: ",i);
    scanf("%d",&data);
    createNode(T,data); 
  }

  return T;
}

//recusion
void createNode(BitTree T,int data){
  //lesser tan
  if(data < T->data){
    if(T->lchild){
      return createNode(T->lchild,data);
    }else{
      BitTree Node = (BitTree)malloc(sizeof(BitNode));
      Node->data = data;
      T->lchild = Node;
      return;
    }

  //grater than
  }else{
    if(T->rchild){
      return createNode(T->rchild,data);    
    }else{
      BitTree Node = (BitTree)malloc(sizeof(BitNode));
      Node->data = data; 
      T->rchild = Node;
      return;
    }
  }
}

int count = 0;
BitTree search_BST(BitTree T,ElemType key){
  count++;
  if(!T || key == T->data ){  //notice: 这里需要加上!T，否则非法访问内存segmentation fault
    return T;
  }
  else if( key < T->data ){
    return search_BST(T->lchild,key);
  }else{
    return search_BST(T->rchild,key);
  }
}


void InOrder(BitTree T){
  if(T){
    InOrder(T->lchild);
    printf("[%d] ",T->data);
    InOrder(T->rchild);
  }
}

int main(){
  
  int n = 0;
  ElemType key = 0;
  BitTree res;

  //create BST tree
  printf("Enter the node number: ");
  scanf("%d",&n);
  BitTree T = createBST(n);
  //InOrder(T);   //debug
  
  //Search from BST-tree
  while(1){
    printf("Enter the search key: ");
    scanf("%d",&key);
    res = search_BST(T,key);
    if(res!=NULL)
      printf("[+] MATCH \n");
    else
      printf("[-] NOT FOUND \n");
  }
  return 0;
}
