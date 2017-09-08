#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;


/*****************************/
/****   Parent Notation   ****/
/*****************************/
typedef struct PTnode{
  ElemType data;          //node's data
  int parent;             //parent's position
} PTnode;

typedef struct{
  PTnode nodes[MAXSIZE];  //storage all nodes in the tree
  int r,n;                //r is root's position,n is nodes' number;
} PTree;


/*****************************/
/****  Children Notation  ****/
/*****************************/

//Mulitilinked List expression:
typedef struct MLnode{
  ElemType data;
  struct NLndoe * A;
  struct NLnode * B;
  struct NLnode * C;  
} NLnode,*NLTree;

//Children Chain expression:
typedef struct CTndoe{     //children link
  int child;               //child positon
  struct CTnode *next;     //next child 
} *ChildLink;

typedef struct{            //parent Node
  ElemType data;
  ChildLink firstchild;    //children link
} CTbox;

typedef struct{            //tree struct
  CTbox nodes[MAXSIZE];    //all node include parent and children
  int r,n;                 //r is root'position, n is number of the nodes
} CTree;


/************************************/
/****  Children Parent Notation  ****/
/************************************/

typedef struct{
  int parent;              //add this parent postion
  ChildLink firstchild;    //children link
  ElemType data;
} CPTbox;

typedef struct{
  CPTbox nodes[MAXSIZE];
} CPTree;


/************************************/
/****  Children Brother Notation ****/
/************************************/
//alias is binary tree
typedef struct CBnode{
  ElemType data;
  struct CBnode *brother;
  struct CBnode *child;    
} CBnode,*CBTree;


int main(){
  return 0;
}
