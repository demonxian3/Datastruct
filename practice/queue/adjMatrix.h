#define INFINITY 1000
#define MAXNUM 100

typedef char VertexType;
typedef int VRType;
typedef struct {
    VertexType vexs[MAXNUM];
    VRType acrs[MAXNUM][MAXNUM];
    int acrnum,vexnum;
}MGraph;

MGraph createGraph(int isDirected, int isNetwork){
    MGraph G;
    printf("G.vexnum: ");
    scanf("%d",&G.vexnum);
    printf("G.acrnum: ");
    scanf("%d",&G.acrnum);
    getchar();

    int i,j,k,a,b,c,t;

    //input the vertexs
    for(i=0; i<G.vexnum; i++){
        printf("G.vexs[%d]: ",i);
        scanf("%c",&G.vexs[i]);
        getchar();
    }

    //initialized the matrix
    for(i=0; i<G.vexnum; i++)
        for(j=0; j<G.vexnum; j++){
            if(isNetwork){
                G.acrs[i][j] = INFINITY;    //网
            }else{
                G.acrs[i][j] = 0;           //图
            }
        }

    if(isNetwork){
        for(i=0; i<G.acrnum; i++){
            printf("[%d]i,j,v:",i);
            scanf("%d,%d,%d",&a,&b,&c);
            getchar();
            G.acrs[a][b]=c;
            if(!isDirected)
                G.acrs[b][a]=c;
        }

    }else{
        for(i=0; i<G.acrnum; i++){
            printf("[%d]i,j:",i);
            scanf("%d,%d",&a,&b);
            getchar();
            G.acrs[a][b]=1;
            if(!isDirected)
                G.acrs[b][a]=1;
        }
    }

    printf("\n\n");
    return G;
}

void printGraph(MGraph G){
    int i,j,show=0;
    int indegree[G.vexnum],outdegree;

    printf("    ");

    //输出每个节点的信息
    for(i=0; i<G.vexnum; i++){
        indegree[i] = 0;
        printf("(%c) ",G.vexs[i]);
    }
    printf("\033[31mout\033[0m\n");

    //输出头部banner
    printf("   *");
    for(i=0; i<=G.vexnum; i++)
        printf("--- ");
    printf("\n");

    //输出主体部分
    for(i=0; i<G.vexnum; i++){
        outdegree = 0;
        printf("(%c)|",G.vexs[i]);

        for(j=0; j<G.vexnum; j++){
            if(G.acrs[i][j] && G.acrs[i][j] != INFINITY ){
                outdegree++;
                indegree[j]++;
            }

            if(G.acrs[i][j] == INFINITY)
                printf("[N] ");
            else if(G.acrs[i][j] != 0){
                printf("\033[33m[%d]\033[0m ",G.acrs[i][j]);
            }else{
                printf("[0] ");
            }
        }
        printf(" \033[31m%d\033[0m\n",outdegree);
    }


    //输出尾部入度值
    printf("\033[34min:\033[0m| ");
    for(i=0; i<G.vexnum; i++)
        printf("\033[34m%d\033[0m   ",indegree[i]);
    printf("\n");
}

