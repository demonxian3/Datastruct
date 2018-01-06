/****************************
 * This program is that sep * 
 * arate the Create funtion *
 * and Searching function   *
 * it need to create the BS *
 * T first,and then you can *
 * search element from the  *
 * tree                     *
 * **************************/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int KeyType;
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
//这里不需要像book那样传递T的指针是因为
//book里的T初始值为NULL，也就没有具体的
//地址，而这里的T是有malloc分配地址了的
void createNode(BitTree T,int data){
  //lesser tan
  if(data < T->data){
    if(T->lchild){
      return createNode(T->lchild,data);
    }else{
      BitTree Node = (BitTree)malloc(sizeof(BitNode));
      Node->data = data;
      Node->lchild = NULL;   //如果这里不对孩子初始化，那么删除某个节点后
      Node->rchild = NULL;   //又添加了该节点，会有残留记忆现象出现孩子。
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
      Node->lchild = NULL;
      Node->rchild = NULL; 
      T->rchild = Node;
      return;
    }
  }
}

void deleteNode(BitTree T,KeyType key){
  int isRight = FALSE;
  BitTree tmp = T;
  BitTree target = NULL;
  BitTree parent = NULL;

  if(T->data = key){
    printf("Cannot delete the root node\n");
    return;
  }


  //search the parent pointer;
  while( tmp ){
    if( tmp->lchild && tmp->lchild->data == key ){
      parent = tmp;
      isRight = FALSE;
      target = parent->lchild;
      break;
    }
    else if( tmp->rchild && tmp->rchild->data == key){
      parent = tmp;
      isRight = TRUE;
      target = parent->rchild;
      break;
    }
    else if( key < tmp->data ){
      tmp = tmp->lchild;
    }
    else if( key > tmp->data ){
      tmp = tmp->rchild;
    }
  }
  
  if(parent == NULL){
    printf("Cannot find the key :%d\n",key);
    return ;
  }

  //if target no children;
  if(target->lchild==NULL && target->rchild==NULL){
    if(isRight)parent->rchild = NULL;
    else parent->lchild = NULL;
  }

  //if target have  left-child;
  if(target->lchild && !target->rchild){
    if(isRight)
      parent->rchild = target->lchild;
    else
      parent->lchild = target->lchild;
  }

  //if target have right-child; 
  if(target->rchild && !target->lchild){
    if(isRight)
      parent->rchild = target->rchild;
    else
      parent->lchild = target->rchild;
  }
    
  //if target have two children;
  if(target->rchild && target->lchild){
    //search the Inorder pre-node;
    tmp = target->lchild;
    while(tmp->rchild != NULL)
      tmp = tmp->rchild;
    
    //link the target's rchild to Inorder pre-node->rchild;
    tmp->rchild = target->rchild;
    
    if( isRight )
      parent->rchild = target->lchild;
    else 
      parent->lchild = target->lchild;
  }

  free(target);  
}

int count = 0;
BitTree search_BST(BitTree T,KeyType key){
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
  char order = 's';
  KeyType key = 0;
  BitTree res;

  //create BST tree
  printf("Enter the node number: ");
  scanf("%d",&n);
  BitTree T = createBST(n);
  //InOrder(T);   //debug
  printf("====== order ======\n"); 
  printf("s:\t search\n"); 
  printf("i:\t insert\n"); 
  printf("d:\t delete\n"); 
  printf("p:\t printi\n");
  printf("e:\t exit\n");

  getchar();  //clear buffer

  //Search from BST-tree
  while(1){
    printf("Enter order: ");
    order = getchar();

    if(order == 's'){
      printf("Enter the search key: ");
      scanf("%d",&key);
      if(search_BST(T,key))
        printf("[+]Match it!\n");
      else
        printf("[-]Not Found!\n");
    }

    if(order == 'i'){
      printf("Enter the insert key: ");
      scanf("%d",&key);
      createNode(T,key);
    }

    if(order == 'd'){
      printf("Enter the delete key: ");
      scanf("%d",&key);
      deleteNode(T,key);
    }

    if(order == 'p'){
      InOrder(T);
      printf("\n");
    } 

    if(order == 'e')break;

    getchar();  //clear buffer
  }

  return 0;
}
