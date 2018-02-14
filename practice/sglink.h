#define TRUE 1
#define FALSE 0
#define OK 0
#define ERROR 1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

typedef struct Node{
  ElemType data;
  struct Node * next;
} Node, *Link;		// typedef struct Node * Link;

//初始化链表
//输入：*L	链表指针地址 
//输出：执行状态
//说明：无
Status initLink(Link *L){

  (*L) = (Link)malloc(sizeof(Node));	//Head Node
  (*L)->data = 0;
  (*L)->next = NULL;
  return OK;
}

//头插法生成节点
//输入：L 	指针地址
//	num 	新生成节点个数
//	isRand	是否随机填值 1是 0否
//输出：执行状态
//说明：使用头插法生成num个新节点到链表中，存在头结点Head
//	若不使用随机填值，需要用户标准输入每个节点的值
Status createNode_HI(Link L, int num, int isRand){
  int i;
  Link new;

  if(num <= 0 || !L) return ERROR;		//参数不合法

  if(isRand){					//非0启用随机填值
    srand(time(0));				//设置随机种子
    for(i = 0; i < num; i++ ){
      new = (Link)malloc(sizeof(Node));
      new->data = rand() % 100 + 1;		//1-100内的随机值
      new->next = L->next;			//头插
      L->next = new;
    }
  }else{
    for(i = 0; i < num; i++){
      new = (Link)malloc(sizeof(Node));
      printf("Enter Node-%d: ",i);		//用户填值
      scanf("%d",&new->data);
      new->next = L->next;			//头插
      L->next = new;
    }
  }

  return OK;
}

//尾插法生成节点
//输入：L 	指针地址
//	num 	新生成节点个数
//	isRand	是否随机填值 1是 0否
//输出：执行状态
//说明：使用尾插法生成num个新节点到链表中，存在头结点Head
//	若不使用随机填值，需要用户标准输入每个节点的值
Status createNode_TI(Link L, int num, int isRand){
  int i;
  Link new = NULL;
  Link tail = L;

  if(num <= 0 || !L) return ERROR;		//参数不合法

  while( tail->next ) tail = tail->next;	//寻找尾巴


  if(isRand){					//非0启用随机填值
    srand(time(0));				//设置随机种子
    for(i = 0; i < num; i++ ){
      new = (Link)malloc(sizeof(Node));
      new->data = rand() % 100 + 1;		//1-100内的随机值
      new->next = tail->next;			//尾插
      tail->next = new;
      tail = tail->next;
    }
  }else{
    for(i = 0; i < num; i++){
      new = (Link)malloc(sizeof(Node));
      printf("Enter Node-%d: ",i+1);		//用户填值
      scanf("%d",&new->data);
      new->next = tail->next;			//尾插
      tail->next = new;
      tail = tail->next;
    }
  }

  return OK; 
}

//向链表里插入一个节点
//输入：L	链表指针
//	i	插入位置，从1开始算
//	e	插入值
//输出：执行状态
//说明：链表插入必需要找到前驱节点的指针
//	寻找插入位置的思路是:指针每向后
//	移一个节点就让i减少一，当i减少到0时
//	就是要插入的位置，而当i为1时，就是插入
//	位置的前驱节点。

Status insertNode(Link L, int i, ElemType e){
  if(!L || i<=0) return ERROR;		//从1开始算,参数错误退出函数
  
  Link p = L;
  Link new = NULL;

  while(p){
    if((i--) == 1) break;		//寻找插入位置的前驱节点
    p = p->next;
  }

  if(i>=1) return OVERFLOW;		//插入的位置超出链表长度,不合法

  new = (Link)malloc(sizeof(Node));
  new->data = e;
  new->next = p->next;
  p->next = new;
  
  return OK;
}

//删除链表里的一个节点
//输入：L	链表指针
//	i	删除位置，从1开始算
//	e	被删节点的值
//输出：执行状态
//说明：删除操作必须找到前驱节点的指针
//	寻找指针的思路和插入函数是一样的
//	重新链接前驱节点的next指针，并释放
//	删除节点，完成删除操作.
Status deleteNode(Link L, int i, ElemType *e){
  if(!L || i<=0) return ERROR;		//从1开始算
  
  Link p = L;
  Link t = NULL;

  while(p){
    if((i--) == 1) break;		//寻找删除位置的前驱节点
    p = p->next;
  }

  if(i >= 1) return OVERFLOW;		//删除位置不合法，溢出

  t = p->next;				//t为被删除的元素
  *e = t->data;				
  p->next = t->next;			//前驱节点next指针指向被删除元素的下一个元素
  free(t);				//释放t

  return OK;
}

//追加节点
//输入：L	链表指针
//	e	追加的值
//输出：执行状态
Status appendNode(Link L, ElemType e){
  if(!L) return ERROR;
    
  Link p = L->next;
  while(p->next) p = p->next;

  Link q = malloc(sizeof(Node));
  q->data = e;
  q->next = NULL;
  p->next = q;
}

//替换节点
//输入：L	链表指针
//	i	替换节点的索引
//	e	替换的值
//输出：执行状态
Status replaceNode(Link L, int i, ElemType e){
  if(!L || i<=0) return ERROR;

  Link p = L;

  while(p){
    if((i--) == 0) break;
    p = p->next;    
  }

  if(i >= 0) return OVERFLOW;
  
  p->data = e;
  return OK;
}

//销毁链表
//输入：*L	链表指针地址
//输出：执行状态
//说明：无
Status destroyLink(Link *L){
  Link p = NULL;
  
  while(*L){
    p = (*L);
    (*L) = (*L)->next;
    free(p);
  }

  *L = NULL;
  return OK;
}

//打印链表每个元素
//输入：L	链表指针
//输出：执行状态
//说明：如果链表为空，输出语句提示空链表
//	否则从头遍历每个元素，并打印，头结点忽略
Status printLink(Link L){
  if(!L) return ERROR;		//参数错误		
  Link p = L->next;		//头结点不打印

  if(!p){
    printf("link is empty\n"); 
    return OK;
  }

  while(p){
    printf("[%d] ",p->data);
    p = p->next;
  }

  printf("\n");
  return OK;
}

//获取长度
//输入：L	链表指针
//输出：链表长度
int getLength_Link(Link L){

  if(!L){	 		//参数错误
    printf("Link is invalid\n");
    return OVERFLOW;
  }	

  int i = 0;
  Link p = L->next;		//头结点不计算
  while(p){
    i++;
    p = p->next;
  }
  return i;
}


//获取值
//输入：L	链表指针
//	i	索引位置
//输出：节点值
//说明：输入一个索引位置，返回链表中该索引
//	位置对应的节点的值。
int getValue_Link(Link L, int i){
  if(!L || i<=0) {		//参数错误
    printf("Link is Null or index is invalid\n");
    return OVERFLOW;
  }

  Link p = L;
  
  while(p){
    if((i--) == 0) break;
    p = p->next;
  }

  if(i >= 0){ 
    printf("index is overflow\n");
    return OVERFLOW;		//超出链表长度
  }
  
  return p->data;
}

//获取索引
//输入：L	链表指针
//	begin	初始检测位置
//	e	需检测的值
//输出：索引、状态码
//说明：输入链表节点的值，返回第一个匹配中
//	的节点所对应的索引
int getIndex_Link(Link L, int begin, ElemType e){
  if(begin <= 0 ){
    printf("begin parameter is error\n");
    return OVERFLOW;
  }

  int i = begin;
  Link p = L;

  while(p){
    if( (begin--) == 0 ) break;
    p = p->next;
  }

  if(begin >= 0){
    printf("begin is overflow\n");
    return OVERFLOW;
  }
  
  while(p){
    if(p->data == e) break;
    i++;
    p = p->next;; 
  }

  return i;
}

//翻转链表
//输入：*L	链表指针地址
//输出：状态
Status reverseLink(Link *L){
  if(!(*L)) return ERROR;
  Link p = (*L)->next;
  Link q = NULL;
  (*L)->next = NULL;

  while(p){
    q = p;
    p = p->next;
    q->next = (*L)->next;
    (*L)->next = q;
  }
  
  return OK;
}
