#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 1024

typedef struct{
  int data[MAXLENGTH];
  int last;
}LIST;

void printList(LIST * li){
  int i;
  printf("list status:\n");
  if(li->last==0)printf("empty!!\n");
  else {
    printf("The list number = %d\n",li->last);
    for(i=0;i<(li->last);i++){
       printf("[%d] ",li->data[i]);
    }
    printf("\n");
  }
}

void infomation(LIST * li){
  system("clear");
  printf("Welcome to ues sequence List!!\n");
  printf("a = append a element\n");
  printf("d = delete a element\n");
  printf("i = insert a element\n");
  printf("e = exit now\n");
  printList(li);
}

LIST * createList(){
  LIST * li = (LIST *)malloc(sizeof(LIST));
  li->last = 0;
  return li;
}

void AppendNode(LIST * li,int val){
  if(li->last>MAXLENGTH){
    printf("List is overflow\n");
    exit(1);
  }
  li->data[li->last]=val;
  li->last++;
}

void InsertNode(LIST * li,int pos,int val){
  if(li->last==MAXLENGTH || pos<0 || pos>li->last){
    printf("position is invalid\n");
    exit(1);
  }

  int i;
  for(i=li->last;i>pos;i--)
    li->data[i]=li->data[i-1];
  li->data[pos]=val;
  li->last++;
}

void DeleteNode(LIST * li,int pos){
  if(li->last==MAXLENGTH || pos<0 || pos>li->last){
    printf("position is invalid\n");
    exit(1);
  }

  int i;
  for(i=pos;i<(li->last-1);i++)
    li->data[i]=li->data[i+1];
  li->last--;
}

int main(){
  LIST * li = createList();
  int pos,val;
  char sel;
  while(1){
    infomation(li);
    printf("enter the option:");
    sel = getchar();
    if(sel == 'a'){
       printf("enter the value:");
       scanf("%d",&val);
       AppendNode(li,val);
    }else if(sel=='i'){
       printf("enter the value:");
       scanf("%d",&val);
       printf("enter the position:");
       scanf("%d",&pos);
       InsertNode(li,pos,val);
    }else if(sel=='d'){
       printf("enter the position:");
       scanf("%d",&pos);
       DeleteNode(li,pos);
    }else if(sel=='e'){
       exit(0);
    }
  }
}
