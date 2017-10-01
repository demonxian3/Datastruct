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
  HuffmanTree HT[len];
  for(i=1;i<len;i++){
    HT[i] = (HuffmanTree)malloc(sizeof(HTnode));
    HT[i]->weight=0;
    HT[i]->parent=0;
    HT[i]->lchild=0;
    HT[i]->rchild=0;
  }
  
  int val;
  for(i=1;i<=num;i++){
    printf("input HT[%d]:",i);
    scanf("%d",&val);
    HT[i]->weight = val;
  }

  int j,amin,bmin;
  for(i=1;i<num;i++){
    amin = bmin =0;

    //find amin
    for(j=1;j<num+i;j++){
      if(HT[j]->parent == 0){
        if(amin == 0){
          amin = j;
        }else{
          if(HT[j]->weight < HT[amin]->weight){
            amin = j;
          }
        }
      }
    }
 
    HT[amin]->parent = num+i;
    HT[num+i]->lchild = amin;

    //find bmin
    for(j=1;j<num+i;j++){
      if(HT[j]->parent == 0){
        if(bmin == 0){
          bmin = j;
        }else{
          if(HT[j]->weight < HT[bmin]->weight){
            bmin = j;
          }
        }
      }
    }

    HT[bmin]->parent = num+i;
    HT[num+i]->rchild = bmin;

    //aggreate the amin and bmin
    HT[num+i]->weight = HT[amin]->weight + HT[bmin]->weight;
  }

  return HT[len-1]->weight;
}

int main(){
  int res = createHuffman();
  printf("res is %d\n",res);
  return 0;
}
