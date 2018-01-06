#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR 1
#define MAX 1024
#define delay 2

typedef int ElemType;
typedef int STATUS;
typedef struct{
  ElemType data[MAX];
  int last; 
} List;
 
List * createList(){

  List * list = (List *)malloc(sizeof(List));
  list->last = 0;
  return list;
}

void clearList(List * list){
  list->last = 0;
}

STATUS appendList(List *list,ElemType val){

  if(list->last >= MAX){
    printf("list length is overflow the MAX length\n");
    return ERROR;
  }

  list->data[list->last]=val;
  list->last++;
}

STATUS insertList(List *list,int index,ElemType val){

  index--;	//because array begin num is 0,but list begin num is 1;

  if(index<0 || index>list->last){
    printf("index is invalid\n");
    return ERROR;
  }

  int i;
  for(i=list->last;i>index;i--)
     list->data[i]=list->data[i-1];
   
  list->data[index] = val;    
  list->last++;
}

STATUS replaceList(List *list,int index,ElemType val,ElemType * docker){
   
   index--;	//because array begin num is 0,but list bgein num is 1;
  
   if(list->last==0){
     printf("list is empty!!\n");
     return ERROR;
   }
 
   if(index<0 || index > list->last){
     printf("input index is invaild\n");
     return ERROR;
   }

   *docker = list->data[index];
   list->data[index]=val;
}

STATUS deleteList(List *list,int index,ElemType * docker){
  
  index--; 	//because array begin num is 0,but list begin num is 1;
 
  if(list->last==0){
    printf("no element can be deleted\n");
    return ERROR;
  };

  if(index<0 || index>list->last){
    printf("index is invalid\n");
    return ERROR;
  }

  *docker = list->data[index];  

  int i;
  for(i=index;i<(list->last-1);i++)
     list->data[i]=list->data[i+1];
  
  list->last--;
}


STATUS getElement(List *list,int index,ElemType * docker){
  
  index--;	//because array begin num is 0,but list begin num is 1;
  
  if(index<0 || index>list->last){
     printf("index is invalid\n");
     return ERROR;
  }
  
  *docker = list->data[index];
}

STATUS getIndex(List *list,int beginIndex,ElemType value){

  beginIndex--;	//because array begin num is 0,but list begin num is 1;

  if(beginIndex >=list->last || beginIndex<0){
     printf("beginIndex is invalid\n");
     return ERROR;
  }

  int i=beginIndex;
  while(i<list->last){
    if(list->data[i]==value)return ++i;
    i++;
  }

  return 0;
}


void printList(List *list){
  
  if(list->last == 0){
     printf("List is empty\n"); 
     return;
  }
 
  int i;
  for(i=0;i<list->last;i++){
    printf("[%d] ",list->data[i]);
    if((i+1)%10==0)printf("\n");
  }
   
  printf("\n");
}

void printInfo(void){
  system("clear");
  printf("welcome to use sequence list\n");
  printf("----------------------------\n");
  printf("a = append    d = delete\n");
  printf("i = insert    r = replace\n");
  printf("g = getValue  G = getIndex\n");
  printf("c = clear     e = exit\n");
  printf("=========== list ===========\n");
}

int main(){

  ElemType val;
  List * list = createList();
  int index;
  char select;

  while(1){

     printInfo();
     printList(list);
     printf("please enter your choose:"); 
     select = getchar();
   
     if(select == 'a'){
        printf("please enter value:");
        scanf("%d",&val);
        appendList(list,val);
     }
  
     if(select == 'c'){
        clearList(list);
     }

     else if(select == 'i'){
       printf("please enter index:");
       scanf("%d",&index);
       printf("please enter value:");
       scanf("%d",&val);
       insertList(list,index,val);
     }

     else if(select == 'd'){
       printf("please enter index:");
       scanf("%d",&index);
       deleteList(list,index,&val);
       printf("last delete value: [%d]\n",val);
       sleep(delay);
     }
 
     else if(select == 'r'){
       int tmp;
       printf("please enter index:");
       scanf("%d",&index);
       printf("please enter new value:");
       scanf("%d",&val);
       replaceList(list,index,val,&tmp);
       printf("last replace value: [%d]\n",tmp);
       sleep(delay);
     }

     else if(select == 'g'){
       printf("please enter index:");
       scanf("%d",&index);
       getElement(list,index,&val);
       printf("list[%d] = %d\n",index,val);
       sleep(delay);
     }

     else if(select == 'G'){
       printf("please enter beginIndex:");
       scanf("%d",&index);
       printf("please enter value:");
       scanf("%d",&val);
       int num = getIndex(list,index,val);
       if(num)
         printf("%d's index is %d\n",val,num);
       else
         printf("sorry not find\n");
       sleep(delay);
     }

     else if(select == 'e'){
       return 0;
     }
     printf("\n");
  } 
}
