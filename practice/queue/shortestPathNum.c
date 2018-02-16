#include <stdio.h>
#include <stdlib.h>
#include "sgQueue.h"
#include "adjMatrix.h"

int * shortestPathNum(MGraph G, int start){
    int i,s,t;
    Queue Q;
    initQueue(&Q);

    int debug = 0;          //是否调试
    
    int step[G.vexnum];
    int * stepNum = (int*)malloc(sizeof(stepNum) * G.vexnum);

    for(i=0; i<G.vexnum; i++)  //初始化路径数组
        step[i] = 0;

    for(i=0; i<G.vexnum; i++)   //初始化路径个数数组
        stepNum[i] = 0;

    enQueue(Q,start);           //从start节点开始探索
    stepNum[start] = 1;
    step[start] = 1;

    while(!isEmpty(Q)){
        deQueue(Q,&t);
        s = step[t]+1;            //计算路径

        if(debug)
            printf("\033[31m%c出队     step=%d stepNum=%d\033[0m\n",G.vexs[t],s,stepNum[t]);                               //debug


        for(i=0; i<G.vexnum; i++){
            if(G.acrs[t][i] && G.acrs[t][i] != INFINITY){
                if(debug)
                    printf("    %c有路径 step=%d stepNum=%d  ",G.vexs[i],step[i],stepNum[i]);                               //debug

                if(step[i]==0 || s < step[i]){      //首次访问，或者路径更新入队
                    enQueue(Q,i);                   //如果后到的路径小，也要入队，因为需要更新该节点所影响的其他
                    step[i] = s;
                    stepNum[i] = stepNum[t];
                    if(debug) printf("入队");                                                                               //debug
                }
                else if(s == step[i])
                    stepNum[i] += stepNum[t];

                if(debug)
                    printf("\n    %c改变后 step=%d stepNum=%d\n\n",G.vexs[i],step[i],stepNum[i]);                           //debug
            }
        }
    }

    return stepNum;
}

int main(){
    int start,i;
    MGraph G = createGraph(0,0);  //创建无向连通图
    printGraph(G);
    printf("Enter start Vertex index: ");
    scanf("%d",&start);
    
    int *stepNum = shortestPathNum(G, start);
    for(i=0; i<G.vexnum; i++)
        printf("stepNum[%d] = %d\n",i,stepNum[i]);

}
