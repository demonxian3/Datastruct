#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define NUM 26
#define LEN 2*NUM

typedef char ** HuffmanCode;
typedef int Status;
typedef int ElemType;
typedef struct{
  int weight;
  int parent,lchild,rchild;
}HTnode,*HuffmanTree;

HuffmanTree AlphabetHuffman(){
  
  int i;
  HuffmanTree HT = (HuffmanTree)malloc(LEN*sizeof(HTnode));
  for(i=1;i<LEN;i++){
    HT[i].parent=0;
    HT[i].lchild=0;
    HT[i].rchild=0;
  }

  //Alphabet for weight
  HT[1].weight=25;
  HT[2].weight=10;
  HT[3].weight=17;  
  HT[4].weight=13;
  HT[5].weight=26;
  HT[6].weight=8;
  HT[7].weight=11;
  HT[8].weight=12;
  HT[9].weight=24;
  HT[10].weight=1;
  HT[11].weight=5;
  HT[12].weight=18;
  HT[13].weight=14;
  HT[14].weight=20;
  HT[15].weight=21;
  HT[16].weight=15;
  HT[17].weight=2;
  HT[18].weight=23;
  HT[19].weight=19;
  HT[20].weight=22;
  HT[21].weight=16;
  HT[22].weight=7;
  HT[23].weight=6;
  HT[24].weight=4;
  HT[25].weight=9;
  HT[26].weight=3;

  //create a HuffmanTree
  for(i=1;i<NUM;i++){
    int j,amin=0,bmin=0;

    //find amin
    for(j=1;j<NUM+i;j++){
      if(HT[j].parent==0){
        if(amin==0)
          amin=j;
        else{
          if(HT[j].weight < HT[amin].weight)
            amin=j;
        }
      }
    }

    HT[amin].parent = NUM+i;
    HT[NUM+i].lchild = amin;

    //find bmin
    for(j=1;j<NUM+i;j++){
      if(HT[j].parent==0){
        if(bmin==0)
          bmin=j;
        else
	  if(HT[j].weight < HT[bmin].weight)
            bmin=j;
      }
    }

    HT[bmin].parent = NUM+i;
    HT[NUM+i].rchild = bmin;
 
    //sum amin and bmin
    HT[NUM+i].weight = HT[amin].weight + HT[bmin].weight;
  }

  return HT;
}

HuffmanCode HuffmanCoding(HuffmanTree HT){
  int c,f,i,start;
  HuffmanCode HC = (char**)malloc((NUM+1)*sizeof(char*));
  char *path = (char*)malloc((NUM+1)*sizeof(char));
  path[NUM]='\0';

  for(i=1;i<=NUM;i++){
    start = NUM-1;
    for(c=i,f=HT[c].parent;f!=0;c=f,f=HT[c].parent){
      if(c==HT[f].lchild)
        path[start--]='0';
      else
        path[start--]='1';
    }
    HC[i]=(char*)malloc((NUM-start)*sizeof(char));
    strcpy(HC[i],&path[start+1]);
  }
  free(path);
  return HC;
}

int main(){
  HuffmanTree ht = AlphabetHuffman();
  HuffmanCode hc = HuffmanCoding(ht);
  return 0;
}
