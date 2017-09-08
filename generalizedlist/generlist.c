#include <stdio.h>
#include <stdlib.h>

#define OK 1	
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct Gnode{
  int tag:1;
  union{
    int atom;
    struct Gnode *hp,*tp;
  };
} *Glist;

int getLength(Glist G){
  if(G!=NULL){
    return 1 + getLength(G->tp);
  }
  return 0;
}

int getDepth(Glist G){
  int max = 0;
  while(G!=NULL){
    if(G->hp->tag==1){
      int dep = getDepth(G->hp);
      if(dep>max)max=dep;
    }
    G = G->tp;
  }
  return 1+max;
}

Status revertList(Glist G){
  if(G->tag && G->tp){
    //switch 
    Glist tmp = G->tp;
    G->tp = G->hp;
    G->hp = tmp;

    revertList(G->hp);
    revertList(G->tp);
  }
  return OK;
}

int main(){
  Glist G;
  int len = getLength(G);
  return 0;
}
