#include "stack.h"

#define MAXNUM 100
#define INFINITY 1000

typedef char VertexType;
typedef int VRType;

typedef struct EdgeNode{
  int adjvex;
  VRType info;
  struct EdgeNode *nextacr;
}EdgeNode;

typedef struct {
  VertexType data;
  EdgeNode *firstedge;
} AdjList[MAXNUM];

typedef struct {
  AdjList vexs;
  int vexnum,acrnum;
} ALGraph;

/********************
 *        DN        *
 ********************/

ALGraph createDN(){
  ALGraph G;
  printf("G.vexnum: "); 
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d].data: ",i);
    scanf("%c",&G.vexs[i].data);
    G.vexs[i].firstedge = NULL;     //注意：之前少了这句，代码运行时一直报segment fault,此句很重要
    getchar();
  }    

  int a,b,w;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]i,j,w: ",i);
    scanf("%d,%d,%d",&a,&b,&w);
    EdgeNode *new =(EdgeNode*)malloc(sizeof(EdgeNode));
    new->adjvex = b;
    new->info = w;
    new->nextacr = G.vexs[a].firstedge;
    G.vexs[a].firstedge = new;
  }
  return G;
}

void printDN(ALGraph G){
  int i;
  EdgeNode *tmp = (EdgeNode*)malloc(sizeof(EdgeNode));
  for(i=0;i<G.vexnum;i++){
    printf("[%c]: ",G.vexs[i].data);
    tmp = G.vexs[i].firstedge;
    while(tmp){
      printf(" -> %c(%d) ",G.vexs[tmp->adjvex].data,tmp->info);
      tmp = tmp->nextacr;
    }
    printf("\n");
  }
}

/***********************
 *    Critical Paht    *
 ***********************/
int ve[MAXNUM];

void findIndegree(ALGraph G,int *indegree){
  int i;
  for(i=0;i<G.vexnum;i++)
    indegree[i]=0;

  for(i=0;i<G.vexnum;i++){
    EdgeNode *p = G.vexs[i].firstedge;
    while(p){
      indegree[p->adjvex]++;
      p=p->nextacr;
    }
  }
}

// ve[j] = Max { ve[i] + dut<i,j> }
Status TopoLogicalSort(ALGraph G,Sqstack *T){
  int i,j;
  int count = 0;
  int indegree[G.vexnum];
  Sqstack S;
  initStack(&S);
  findIndegree(G,indegree);

  for(i=0;i<G.vexnum;i++)
    if(indegree[i] == 0) 
      pushStack(&S,i);

  //init ve
  for(i=0;i<G.vexnum;i++)
    ve[i]=0;
 
  //debug
  //for(i=0;i<G.vexnum;i++)
  //  printf("[%d] = %d\n",i,indegree[i]);

  //使用T栈存储逆排序，方便计算vl
  while(!isEmpty(S)){
    count++;
    popStack(&S,&j);
    pushStack(T,j);
    
    //求ve 和 删点j
    EdgeNode *p = G.vexs[j].firstedge;
    while(p){
      if( ve[j]+p->info > ve[p->adjvex] )
        ve[p->adjvex] = ve[j] + p->info;
      if(--indegree[p->adjvex] == 0)
        pushStack(&S,p->adjvex);
      p = p->nextacr;
    }
  }

  if(count!=G.vexnum)return ERROR; //1
  else return OK; //0
}


// vl[i] = Min{ vl[j] - dut<i,j> }
Status CriticalPath(ALGraph G){
  int i,j;
  int vl[G.vexnum];
  int ae,al;
  Sqstack T;
  initStack(&T);
  if(TopoLogicalSort(G,&T)){
    printf("The AOE have loop!!\n");
    return ERROR;
  }
  
  //求vl
  for(i=0;i<G.vexnum;i++)
    vl[i] = INFINITY;

  //汇点 最迟开始时间 等于 最早开始时间
  vl[G.vexnum-1] = ve[G.vexnum-1];

  while(!isEmpty(T)){
    popStack(&T,&j);
    EdgeNode* p = G.vexs[j].firstedge;
    while(p){
      if( vl[p->adjvex] - p->info < vl[j])
        vl[j] = vl[p->adjvex] - p->info;
      p = p->nextacr;
    }
  }

  // debug 
  /*
  for(i=0;i<G.vexnum;i++)
    printf("[%d] = %d\n",i,ve[i]);

  for(i=0;i<G.vexnum;i++)
    printf("[%d] = %d\n",i,vl[i]);
  */

  //比较 Ae 和 Al,相等则输出关键路径
  for(i=0;i<G.vexnum;i++){
    EdgeNode *p = G.vexs[i].firstedge; 
    ae = ve[i];
    while(p){
      j = p->adjvex;
      al = vl[j] - p->info;
      if(ae == al)
        printf("[Critical] %c -> %c : %d\n", 
          G.vexs[i].data,
          G.vexs[j].data,
          p->info
        );
      p = p->nextacr;
    }
  }
}


int main(){ 
  ALGraph G = createDN();
  //printDN(G);
  CriticalPath(G);
  return 0;
}
