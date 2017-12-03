/****************************
 *  This program merge the  * 
 *  Create function and Se  *
 *  arch function, searchi  *
 *  ng while adding the el  *
 *  ement. if element is e  *
 *  xited, return message,  *
 *  else add the element t  *
 *  o the tree              *
 * **************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int KeyType;

typedef struct {
  KeyType key;
  //other data;
} ElemType;

typedef struct BitNode{
  ElemType data;
  struct BitNode *lchild, *rchild;
} BitNode, *BitTree;

Status searchBST(BitTree T,KeyType key,BitTree f,BitTree *p){
  if(!T){*p=f;return FALSE;}            //Label:NM if T is Null, it will be a root;
  else if(key == T->data.key){
    *p=T;return TRUE;    //find the node
  }
  else if(key < T->data.key)
    searchBST(T->lchild,key,T,p);
  else
    searchBST(T->rchild,key,T,p); 
}

Status insertBST(BitTree *T,KeyType e){
  BitTree p = NULL;
  if(!searchBST(*T,e,NULL,&p)){  //这里需要改变p的值，因此传递其地址
    BitTree new = (BitTree)malloc(sizeof(BitNode)); 
    new->data.key = e;
    new->lchild = NULL;
    new->rchild = NULL;
    if(!p)*T=new;  //if no parent,T as the root
    else if(e < p->data.key)
      p->lchild = new;
    else
      p->rchild = new;
    return TRUE;
  }else{
    return FALSE; //if find the node, exit normally
  }
}

Status delete(BitTree *T){
  BitTree p = *T;
  BitTree q=NULL, s=NULL;
  if(! p->rchild ){   //no right son
    q = p;
    p = p->lchild;
    free(q);
  }else if(!p->lchild){ //no left son
    q = p;
    p = p->rchild;
    free(p);
  }else{   //exited two son
    q = p;
    s = p->lchild;
    while(s->rchild){
      q = s;
      s = s->rchild;
    }

    p->data = s->data;
    if(q != p)
      q->rchild = s->lchild;
    else
      q->lchild = s->lchild;
  
   free(s);
  }
  return TRUE;
}

Status deleteBST(BitTree *T,KeyType key){
  if(!(*T))return FALSE;
  else{
    if(key == (*T)->data.key)
      return delete(T);
    else if(key < (*T)->data.key)
      return deleteBST( &((*T)->lchild), key );
    else return deleteBST( &((*T)->rchild), key );
  }
}

BitTree createBST(){
  int i;
  BitTree T = NULL;   //NULL must be used as an initial value, look the label :NM:
  
  KeyType key;
  printf("Enter the first key: ");
  scanf("%d",&key);

  while(key>0){    //当key=0结束

    if(!insertBST(&T,key))   //直接用T不会改变T的值，因此每次都是从T=NULL开始。
      printf("Find the key: %d\n",key);
    else
      printf("Add a element: %d\n",key);
    
    printf("Enter the key: "); //read the next key
    scanf("%d",&key);

  }

  return T;
}

InOrder(BitTree T){
  if(T){
    InOrder(T->lchild);
    printf("%d ",T->data.key);
    InOrder(T->rchild);
  }
}

int main(){
  int key;
  BitTree T = createBST(); 
  InOrder(T);  //other useage
  printf("\n");

  while(1){
    printf("[Delete Test] Enter the key: ");
    scanf("%d",&key);
    getchar();
    deleteBST(&T,key);
    InOrder(T); 
    printf("\n");
  }
}
