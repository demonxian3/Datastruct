#include <stdio.h>
#include <stdlib.h>
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct{
  int weight;
  int parent,lchild,rchild;
}HTnode,*HuffmanTree;

int createHuffman(){
  int num;
  printf("input the number of the node:");
  scanf("%d",&num);
  
  int i;
  int len = (int)2*num;
  HuffmanTree Tarr[len];
  for(i=1;i<len;i++){
    Tarr[i] = (HuffmanTree)malloc(sizeof(HTnode));
    Tarr[i]->weight=0;
    Tarr[i]->parent=0;
    Tarr[i]->lchild=0;
    Tarr[i]->rchild=0;
  }
  
  int val;
  for(i=1;i<=num;i++){
    printf("input Tarr[%d]:",i);
    scanf("%d",&val);
    Tarr[i]->weight = val;
  }

  int j,amin,bmin;
  for(i=1;i<num;i++){
    amin = bmin =0;

    //find amin
    for(j=1;j<num+i;j++){
      if(Tarr[j]->parent == 0){
        if(amin == 0){
          amin = j;
        }else{
          if(Tarr[j]->weight < Tarr[amin]->weight){
            amin = j;
          }
        }
      }
    }
 
    Tarr[amin]->parent = num+i;
    Tarr[num+i]->lchild = amin;

    //find bmin
    for(j=1;j<num+i;j++){
      if(Tarr[j]->parent == 0){
        if(bmin == 0){
          bmin = j;
        }else{
          if(Tarr[j]->weight < Tarr[bmin]->weight){
            bmin = j;
          }
        }
      }
    }

    Tarr[bmin]->parent = num+i;
    Tarr[num+i]->rchild = bmin;

    //aggreate the amin and bmin
    Tarr[num+i]->weight = Tarr[amin]->weight + Tarr[bmin]->weight;
  }

  return Tarr[len-1]->weight;
}

int main(){
  int res = createHuffman();
  printf("res is %d\n",res);
  return 0;
}
