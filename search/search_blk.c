#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100
#define TRUE 1
#define ERROR 0

typedef int KeyType;
typedef struct {
  KeyType key;
  //other data
} ElemType;

typedef struct {
  int beginIdx; 
  KeyType maxValue;
} Block;

typedef struct {
  ElemType *elem;
  Block *indx;
  int keylen,idxlen;
} Stable;

void createBlock(Stable *ST){
  int i,j;
  int keynum,blknum;
  int index,maxvalue,keyvalue;
  
  printf("Enter the num of key: ");
  scanf("%d",&keynum);
  printf("Enter the num of block: ");
  scanf("%d",&blknum);

  ST->indx = (Block *)malloc((blknum) * sizeof(Block));
  ST->elem = (ElemType *)malloc((keynum+1) * sizeof(ElemType));
  ST->idxlen = blknum;
  ST->keylen = keynum;

  //input for index block
  for(i=0;i<blknum;i++){
    printf("[%d] Enter beginIndex: ",i+1);
    scanf("%d",&index);
    printf("[%d] Enter maxValue: ",i);
    scanf("%d",&maxvalue);
    ST->indx[i].beginIdx = index;
    ST->indx[i].maxValue = maxvalue;
  }

  //input for key value
  j=0;
  for(i=1;i<=keynum;i++){ 
    if(i==ST->indx[j].beginIdx)
      printf("======= Don't more than the MaxValue: %d =========\n",
             ST->indx[j++].maxValue);
    
    printf("[%d] Enter Keyvalue: ",i);
    scanf("%d",&ST->elem[i].key);
  }
  
  //output for index
  for(i=0;i<blknum;i++)
    printf("indx[%d]: beginIdx=%d, maxValue=%d \n",
            i+1,ST->indx[i].beginIdx,ST->indx[i].maxValue);

  //output for key value
  j=1;
  for(i=1;i<=keynum;i++){
    printf("(%2d)%d ",i,ST->elem[i].key);
    if(i % (ST->indx[j].beginIdx - 1) == 0){
      printf("\n");
      j++;
    }
  }
  printf("\n");  
}

int search_block(Stable ST,KeyType key){
  int i,f,l;
  for(i=0;i<ST.idxlen;i++){
    f = ST.indx[i].beginIdx;
    if( key <= ST.indx[i].maxValue)  //must include boundary
      break;
  }

  i==ST.idxlen ? (l=ST.keylen) : (l=ST.indx[i+1].beginIdx) ;

  printf("search in range [%d ~ %d] \n",f,l);
  
  ST.elem[l].key = key;          //监视哨 Surveillance post
  for(i=f; ST.elem[i].key!=key; i++);

  if(i==l)return 0;
  else return i;
    
}

int main(){
  int key,res;
  Stable ST;

  createBlock(&ST);
  
  while(1){
  printf("Enter the key value: ");
  scanf("%d",&key);
  res = search_block(ST,key);
  
  if(!res)
    printf("Sorry the key was not found\n");
  else
    printf("Found it,the index is %d\n",res);
  }
}
