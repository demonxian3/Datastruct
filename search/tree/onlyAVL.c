#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
  int data;
  int bf;				//balance factor
  struct Node *lc,*rc;
} Node, *Tree;

typedef int Status;



Tree createNode(int n){
  Tree T = malloc(sizeof(Node));
  T->data = n;
  T->bf = 0;
  T->lc = T->rc = NULL;
  return T;
}



Status swap(int *A,int *B){
  if(!A || !B)    			//Error
    return FALSE; 

  *A -= *B;
  *B += *A;
  *A = *B - *A;
  return TRUE;
}



Status R_Rotate(Tree T){
  if(!T && !T->lc) {			//ERROR	
    printf("R-rotate Error\n");
    return FALSE;
  }

  Tree L = T->lc;
  swap( &(T->data) , &(L->data) );

  T->lc = L->lc;
  L->lc = L->rc;
  L->rc = T->rc;
  T->rc = L;

  return TRUE;
}




Status L_Rotate(Tree T){
  if(!T && !T->rc) {			//ERROR
    printf("L-rotate Error\n");
    return FALSE;
  }

  Tree R = T->rc;
  swap( &(T->data), &(R->data) );

  T->rc = R->rc;
  R->rc = R->lc;
  R->lc = T->lc;
  T->lc = R;

  return TRUE;
}




/* Flush every node's bf(balance factor)  */
int getDepth(Tree T){
  if(!T) return 0;
  int lbf = getDepth(T->lc);
  int rbf = getDepth(T->rc);
  
  T->bf = lbf - rbf;
  return lbf > rbf ? lbf+1 : rbf+1 ;
}




/* Find the node which is unbalanced and minimal */
Tree findNode(Tree T){
  if(!T) return NULL;
  Tree L = findNode(T->lc);
  Tree R = findNode(T->rc);
  
  if(L) return L;
  else if(R) return R;
  else if(T->bf == 2 || T->bf == -2) return T;
  else return NULL;
}




Status adjust(Tree Root){
  getDepth(Root);		//flush balance factor
  Tree T = findNode(Root);

  if(!T){
    printf("Cannot find the unbalanced node\n");
    return FALSE;
  }

  Tree R=NULL , L=NULL;
   
  if(T->bf == 2) L = T->lc;
  else if(T->bf == -2) R = T->rc;

  if(L){
    printf("L");
    switch(L->bf){		//LL
      case 1:
        printf("L  \n");
	R_Rotate(T);
	break;

      case -1:			//LR
        printf("R  \n");
	L_Rotate(L);
	R_Rotate(T);
	break;
    }
  }

  if(R){
    printf("R");
    switch(R->bf){
      case -1:			//RR
        printf("R  \n");
	L_Rotate(T);	
	break;

      case  1:			//RL
        printf("L  \n");
	R_Rotate(R);
	L_Rotate(T);
	break;
    }
  }

  return TRUE;
}

void InOrder(Tree T){
  if(T){
    InOrder(T->lc);
    printf("[%d] ",T->bf);
    InOrder(T->rc);
  }
}

/*
	    T				C
	   / \			       / \
	  A   E			      A   T
	 / \		->           / \   \
	B   C   		    B   D   E
	   /
	  D

*/
int main(){
  Tree T = createNode(70);
  Tree A = createNode(30);
  Tree B = createNode(10);
  Tree C = createNode(50);
  Tree D = createNode(40);
  Tree E = createNode(90);

  T->rc = E;
  T->lc = A;
  A->lc = B;
  A->rc = C;
  C->lc = D;

  /* debug */
  //getDepth(T);
  //InOrder(T);
  //printf("\n");
  //Tree p = findNode(T);
  //printf("data: %d",p->data);

  adjust(T);
  printf("gdb\n");
}
