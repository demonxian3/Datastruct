/******    Orthogonal List     ******/
//This programe cannot run in kali linux with gcc6.1.x
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 100

typedef char VertexType;
typedef struct AcrBox{
  int tailvex,headvex;
  struct AcrBox *headlink,*taillink;
}AcrBox;

typedef struct VexNode{
  VertexType data;
  struct AcrBox *firstin,*firstout;
}VexNode;

typedef struct{
  VexNode xlist[MAXNUM];
  int acrnum,vexnum;
}OLGraph;

OLGraph createDG(){
  OLGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();
  
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.xlist[%d].data: ",i);
    scanf("%c",&G.xlist[i].data);
    getchar();
  }

  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]acr-> i,j: ",i);
    scanf("%d,%d",&a,&b);
    getchar();
    AcrBox *new   = (AcrBox*)malloc(sizeof(AcrBox));
    new->tailvex  = a;
    new->headvex  = b;
    new->taillink = G.xlist[a].firstout;
    new->headlink = G.xlist[b].firstin;
    G.xlist[a].firstout = new;
    G.xlist[b].firstin  = new;
  }

  return G;
}

void printDG(OLGraph G){
  int i,c,k;
  char table[8] = "\t\t\t\t\t\t\t\t";
  int sum[G.vexnum];
  printf("==========>  OutDegree Print <==========\n");
  for(i=0;i<G.vexnum;i++){
    c=0;
    printf("[%c]",G.xlist[i].data);
    AcrBox *tmp = G.xlist[i].firstout;
    while(tmp!=NULL){
      printf(" --> <%d,%d>",tmp->tailvex,tmp->headvex);
      tmp=tmp->taillink;
      ++c;
    }
    table[c>7?0:7-c]='\0';
    printf("%sTotal :%d\n",table,c);
    strcpy(table,"\t\t\t\t\t\t\t\t");
    sum[i]=c;
  }
  
  printf("\n\n");
  printf("===========> InDegree Print <===========\n");
  for(i=0;i<G.vexnum;i++){
    c=0;
    printf("[%c]",G.xlist[i].data);
    AcrBox *tmp = G.xlist[i].firstin;
    while(tmp!=NULL){
      printf(" <-- <%d,%d>",tmp->headvex,tmp->tailvex);
      tmp=tmp->headlink;
      ++c;
    }
    for(k=0;k<7-c;k++)printf("\t");
    printf("Total :%d\n",c);
    sum[i]+=c;
  }

  printf("\n\n");
  printf("=========> AllDegree Statistics <=========\n");
  for(i=0;i<G.vexnum;i++)
    printf("[%c]:  %d\n",G.xlist[i].data,sum[i]);
  printf("\n");
}

int main(){
  OLGraph G = createDG();
  printf("\n\n");
  printDG(G);
  return 0;
}
