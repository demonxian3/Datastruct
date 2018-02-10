#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100


typedef int KeyType;
typedef struct {
  KeyType key;
} DataType;
typedef struct {
  DataType data[MAXSIZE + 1];  //place the sentry
  int length;
} Sqlist;



void ShellSort(Sqlist *L,int *d,int t){
  int i,j,k;
  int len = L->length;
  
  for(k=0; k<t; k++){			//参数t为趟数，这里执行三趟
    for(i=d[k]+1; i<=len; i++){		//一趟增量为d[k]的插入排序  增量为１时原始的直接插入排序

      if( L->data[i].key < L->data[i-d[k]].key ){
        L->data[0].key = L->data[i].key;	//放岗哨

        //判断是否大于岗哨，是则后挪d[k]位，腾出空为插入岗哨值
        for(j=i; (j>0) && (L->data[0].key < L->data[j-d[k]].key) ; j-=d[k]){
	  L->data[j].key = L->data[j-d[k]].key;  //隔d[k]位后挪
        }

        L->data[j].key = L->data[0].key;	//插入岗哨值

      }//if

    }//for

  }//for

  return ;
}

int main(){
 
  int t = 3;		//趟数
  int d[t];		//增量数组
  Sqlist L;  

  printf("*** ShellSort ***\nInput key's number:");
  scanf("%d",&L.length);
  
  for(int i=1;i<=L.length;i++){
     printf("input key[%d]:",i);
     scanf("%d",&L.data[i].key);
  }

  d[0] = 5;
  d[1] = 3;
  d[2] = 1;

  ShellSort(&L,d,t);

  for(int i=1;i<=L.length;i++)
     printf("[%d] ",L.data[i].key);
  printf("\n");
  
  return 0;
}
