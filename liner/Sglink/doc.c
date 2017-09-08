#include <stdio.h>
#include <stdlib.h>

typedef struct linknode{
  int data;
  struct linknode *next;
} LinkNode;

LinkNode * CreateNode(){
  int i;
  LinkNode * head, * ptr, * p;
  head = (LinkNode*)malloc(sizeof(LinkNode));
  
  printf("data1:");
  scanf("%d",&head->data);

  head->next=NULL;
  ptr=head;

  for(i=1;i<6;i++){
    p = (LinkNode*)malloc(sizeof(LinkNode));
    printf("data%d:",i+1);
    scanf("%d",&p->data);

    p->next=NULL;
    ptr->next = p;
    ptr = ptr->next;
  }
  return  head;
}

LinkNode * FineNode(LinkNode * head,int val){
  LinkNode * ptr = (LinkNode*)malloc(sizeof(LinkNode));
  ptr = head;
  while(ptr->next!=NULL){
    if(ptr->data==val)return ptr;
    ptr=ptr->next;
  }

  return ptr;
}

LinkNode * InsertNode(LinkNode *head,LinkNode* ptr,int val){
  LinkNode * newNode = (LinkNode*)malloc(sizeof(LinkNode));
  LinkNode * pre = (LinkNode*)malloc(sizeof(LinkNode));
  newNode->data = val;
  newNode->next = NULL;

  if(ptr==head){
     newNode->next=head;
     return newNode;
  }
  
  pre = head;
  while(pre->next!=ptr)
    pre=pre->next;
  
  pre->next = newNode;
  newNode->next = ptr;
  
  return head;
}

LinkNode * DeleteNode(LinkNode*head,LinkNode*ptr){
  if(ptr==head)return head->next;
  LinkNode* pre = (LinkNode*)malloc(sizeof(LinkNode));
  pre=head;
  while(pre->next!=ptr)
    pre=pre->next;
  pre->next=ptr->next;
  free(ptr);
  return head;
}

void PrintNode(LinkNode*ptr){
  while(ptr!=NULL){
    printf("%d  ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
}


void FreeLinkNode(LinkNode*head){
  LinkNode *ptr;
  while(head!=NULL){
    ptr=head;
    head=head->next;
    free(ptr);
  }
}
int main(){
  int num,val;
  LinkNode *head,*ptr;
  head = CreateNode();
  PrintNode(head);
  printf("=============insert===========\n");
  printf("enter the pos:");
  scanf("%d",&num);
  ptr=FineNode(head,num);
  if(!ptr){
    printf("sorry,the position value not fined\n");
    return 1;
  }
  printf("enter the value:");
  scanf("%d",&val);
  head=InsertNode(head,ptr,val);
  PrintNode(head);
  
  printf("=============delete============\n");
  printf("enter the pos:");
  scanf("%d",&num);
  ptr=FineNode(head,num);
  if(!ptr){
    printf("sorry,the position value not fined\n");
    return 1;
  }
  head = DeleteNode(head,ptr);
  PrintNode(head);
  FreeLinkNode(head);
  return 0;
}
