#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR 1 
#define MAX  100
#define DELAY 2

typedef int ElemType;
typedef int STATUS;
typedef struct Linknode{
   int data;
   struct Linknode * next;
} Link;

Link * createLink(int num){
  
  if(num<=0||num>MAX){
    printf("num is invalid,now num is set 3\n");
    num = 3;
  }

  int i;
  Link * head, *tmp, *new;
 
  head = malloc(sizeof(Link));
  printf("link[0]:");
  scanf("%d",&head->data);
  head->next = NULL;

  tmp = head;
  for(i=1;i<num;i++){

    new = malloc(sizeof(Link));
    printf("link[i]:");
    scanf("%d",&new->data);

    new->next = NULL;
    tmp->next = new;
    tmp = tmp->next;
  }

  return head;
}

ElemType getValue(Link * head,int index){
   
   index--;

   if(index<0 || index>=MAX){
      	printf("index is invalid\n");
	return ERROR; 
   }

   Link * tmp = head;

   int i=0;
   while(tmp){
     if(i == index){
        printf("value is %d\n",tmp->data);
        return  1;
     }
     tmp = tmp->next;
     i++;
   }
 
   printf("sorry index is not found\n");
   return ERROR;
}

ElemType getIndex(Link * head,ElemType value){

   int i = 0;
   Link * tmp = head;
   while(tmp){
     if(tmp->data == value){
       printf("Index is %d\n",i+1);
       return 0;
     }
     tmp=tmp->next;
     i++;
   }
   
   printf("Sorry value is not found!\n");
   return 0;
}

Link * findNode(Link * head,int value){

  Link * tmp = head;
  
  while(tmp){
    if(tmp->data == value)return tmp;
    tmp = tmp->next;
  }
  return NULL;
}

Link * insertBefore(Link * head,Link * target,ElemType value){
   
  Link * tmp = head;
  Link * new = malloc(sizeof(Link));
  new->data=value;
  if(target == head){
    new->next = head;
    return head;
  }

  while(tmp->next != target)tmp=tmp->next;
  
  new->next = target;
  tmp->next = new;

  return head;
} 

STATUS insertAfter(Link * target,ElemType value){
   
   Link * new = malloc(sizeof(Link));
   new->data = value;
   new->next = target->next;
   target->next = new;
   return 0;
}

STATUS appendNode(Link * head,ElemType value){
   
   Link * tmp = head;
   Link * new = malloc(sizeof(Link));
   new->data = value;
   new->next = NULL;
   while(tmp->next)tmp=tmp->next;
 
   tmp->next = new;
   return 0;
}

STATUS replaceNode(Link *target,ElemType value){
   target->data=value;
   return 0;
}

Link * deleteNode(Link * head,Link * target){
  
  if(head == target)return head->next;

  Link * tmp = head;
  while(tmp->next != target)tmp=tmp->next;

  tmp->next = target->next;
  return head;
}

void freeLink(Link *head){
   Link * tmp = malloc(sizeof(Link));
   while(head){
     tmp = head;
     head = head->next;
     free(tmp);
   }
}


void printLink(Link * head){
   Link * tmp = head;
   while(tmp){
     printf("[%d] ",tmp->data);
     tmp = tmp->next;
   }
   printf("\n");
}

void printInfo(){
   system("clear");
   printf("\n");
   printf("---------------------------\n");
   printf("        a = append         \n");
   printf("        g = getValue       \n");
   printf("        G = getIndex       \n");
   printf("        i = insertBefore   \n");
   printf("        I = insertAfter    \n");
   printf("        r = replace        \n");
   printf("        d = delete         \n");
   printf("        e = exit           \n");
   printf("===========================\n");
}

int main(){
  int num,index,value;
  char select;
  printf("how many num are you want:");
  scanf("%d",&num);
  Link * head = createLink(num);
  Link * tmp  = malloc(sizeof(Link));

  while(1){
    printInfo();
    printLink(head);
    printf("please enter your choose:");
    select = getchar();
    
    if(select == 'a'){
	printf("please enter value:");
	scanf("%d",&value);
	appendNode(head,value);
    }

    else if(select == 'r'){
	printf("please enter old value:");
	scanf("%d",&value);
	tmp = findNode(head,value);
	printf("please enter new value:");
	scanf("%d",&value);
	replaceNode(tmp,value);
    }

    else if(select == 'g'){
	printf("please enter index:");
	scanf("%d",&index);
	getValue(head,index);
	sleep(DELAY);
    }

    else if(select == 'G'){
	printf("please enter value:");
        scanf("%d",&value);
 	getIndex(head,value);
	sleep(DELAY);
    }
   
    else if(select == 'i'){
        printf("enter the old value:");
	scanf("%d",&value);
	tmp = findNode(head,value);
	if(!tmp){
	  printf("Sorry value is not found\n");
	  sleep(DELAY);
	  continue;
	}
	printf("enter the new value:");
	scanf("%d",&value);
	head = insertBefore(head,tmp,value);
    }

    else if(select == 'I'){
        printf("enter the old value:");
	scanf("%d",&value);
	tmp = findNode(head,value);
	if(!tmp){
	  printf("sorry value is not found\n");
	  sleep(DELAY);
	  continue;
	}
	printf("enter the new value:");
	scanf("%d",&value);
	insertAfter(tmp,value);
    }
    
    else if(select == 'd'){
	printf("enter the old value:");	
	scanf("%d",&value);
	tmp = findNode(head,value);
	head = deleteNode(head,tmp);
    }

    else if(select == 'e'){
       free(head);
       exit(0);
    }
  }

}
