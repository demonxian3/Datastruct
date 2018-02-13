#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 1000

typedef int Status;
typedef int ElemType;

typedef struct{
  ElemType data;
  int cur;
}Component, StaticLink[MAX];

Status initList(StaticLink space){
  int i;
  for(i=0;i<(MAX-1);i++){
    space[i].cur = i+1;
  }
  space[MAX-1].cur=0;
  return OK;
}

int mallocSpace(StaticLink space){
  int bak = space[0].cur;		  //get free cursor
  if( space[0].cur )              //space is empty?
    space[0].cur = space[bak].cur;  //move after one
  return bak;			  //return index
} 

int getLength(StaticLink space){
  int i,j=0;
  i = MAX-1;
  
  while(i){
    i = space[i].cur;
    j++;
  }

  return j;
}

Status deleteList(StaticLink space,int index){
  
  int i;
  int k = MAX-1;

  if(index<1 || index>getLength(space))return ERROR;
  
  for(i=1;i<index-1;i++)
    k = space[k].cur;

  int next = space[k].cur;
  space[k].cur = space[next].cur;
  freeList(space,next); 
  return OK;
}

Status insertList(StaticLink space,int index,ElemType value){
  
  int new,k,i;
  k = MAX -1;
  if(index<1 || index>getLength(space))return ERROR;
  
  new = mallocSpace(space);
  if( new ){
    space[new].data = value;
    for(i=1;i<=index;i++)
      k = space[k].cur;    //k is insert node's prenoede

    space[new].cur = space[k].cur;
    space[k].cur = new;
    return OK;
  }

  return ERROR;
}


Status freeList(StaticLink space,int k){
  
  space[k].cur = space[0].cur;
  space[0].cur = k;

  return OK;
}

int main(){
  return 0;
}
