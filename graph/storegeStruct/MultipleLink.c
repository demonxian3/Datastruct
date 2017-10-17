#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20

typedef char VertexType;
typedef struct EBox{
  int mark;
  int ivex,jvex;
  struct EBox *ilink,*jlink;
}EBox;

typedef struct VexBox{
  VertexType data;
  EBox *firstEdge;
}VexBox;

typedef struct{
  VexBox adjmulist[MAXNUM];
  int vexnum,acrnum;
}AMLGraph;

AMLGraph createUDG(){
  AMLGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.adjmulist[%d].data: ",i);
    scanf("%c",&G.adjmulist[i].data);
    getchar();
    G.adjmulist[i].firstEdge = NULL;
  }

  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("%d->(i,j):",i);
    scanf("%d,%d",&a,&b);
    getchar();
    EBox *new = (EBox*)malloc(sizeof(EBox));
    new->ivex=a;
    new->jvex=b;
    new->mark=0;
    new->ilink = G.adjmulist[a].firstEdge;
    new->jlink = G.adjmulist[b].firstEdge;
    G.adjmulist[a].firstEdge = new;
    G.adjmulist[b].firstEdge = new;
  }
  return G;
}

void printUDG(AMLGraph G){
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("[%c]",G.adjmulist[i].data);
    EBox *tmp = G.adjmulist[i].firstEdge;
    while(tmp!=NULL){
      tmp->mark=1;
      if(i == tmp->ivex){
        printf(" -> %c",G.adjmulist[tmp->jvex]);
        tmp=tmp->ilink;
      }else{
        printf(" -> %c",G.adjmulist[tmp->ivex]);
        tmp=tmp->jlink;
      }
    }
    printf("\n");
  }
}

int main(){
  AMLGraph G = createUDG();
  printf("\n\n");
  printUDG(G);
  return 0;
}
