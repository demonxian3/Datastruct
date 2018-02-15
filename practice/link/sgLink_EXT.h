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
    srand(time(NULL));			//设置随机种子
    for(i = 0; i < num; i++ ){
      new = (Link)malloc(sizeof(Node));
      new->data = rand() % 100 + 1;		//1-100内的随机值
      new->next = L->next;			//头插
      L->next = new;
    }
  }else{
    for(i = 0; i < num; i++){
      new = (Link)malloc(sizeof(Node));
      printf("Enter Node-%d: ",i+1);		//用户填值
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
    srand(time(NULL));			//设置随机种子
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
    printf("[%2d] ",p->data);
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

//全翻转链表
//输入：*L	链表指针地址
//输出：状态
//说明：对整个链表进行翻转，不会生成副本。
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

//链表部分翻转
//输入: *L	链表指针地址
//	m	开始翻转的位置
//	n	结束翻转的位置
//输出：状态
//说明：将链表的第m个节点到第n个节点进行翻转
//	该函数将翻转后的结果直接覆盖源链表，不会生成副本
Status reverseLink_partly(Link *L, int m, int n){
  if(m <= 0 || n <= 0 || m >= n || n > getLength_Link(*L)) return ERROR;

  Link Head,p,q,f;
  p = *L;
  
  n = n - m; 			 //计算需要翻转的次数

  while(m-- > 1)     		 //找到开始翻转节点的前驱节点，作为头，使用头插法完成翻转
    p = p->next;
  
  Head = p;          		 //Head 为链表中部分节点的相对头
  f = Head->next;		 //记录相对第一个元素，方便翻转完后链接链表剩下的未翻转节点。
  p = f->next;			 //从相对第二个元素开始向第一个元素前面插入

  while(n-- > 0 && p){   	 //开始翻转
    q = p;          		 //多使用一个指针完成翻转操作，否则会丢失原生的next指针
    p = p->next;
    q->next = Head->next; 	 //头插法
    Head->next = q;
  }

  f->next = p;		 	 //当初的首元素在翻转后成为尾元素，链接链表剩下的未翻转部分
  return OK;
}

//链表快速排序
//输入：*L	链表指针地址
//输出：状态
//说明：使用快速排序对链表做递增排序，排序结果直接覆盖，不生成副本
Status sortLink(Link *L){
  if(!(*L) || !((*L)->next)) return ERROR;

  Link q = NULL;		
  Link pivot = (*L)->next;	//第一个元素作为中心节点
  Link p = pivot->next;		//从第二个元素开始分队
  pivot->next = NULL;		//让中心节点脱离链表

  Link big = (Link)malloc(sizeof(Node));
  Link sml = (Link)malloc(sizeof(Node));
  sml->next = big->next = NULL;

  while(p){
    q = p->next;		//记录链表下一个节点，避免丢失链表指针
    if(p->data < pivot->data){	//比中心值大，去大队
      p->next = sml->next;	//直接从链表里摘下放到大队伍里
      sml->next = p;
    }else{			//比中心值小，去小队
      p->next = big->next;	//直接从链表里摘下放到小队伍里
      big->next = p;
    }
    p = q;			//处理链表下一个元素
  }

  sortLink(&sml);		//递归排序小队
  sortLink(&big);		//递归排序大队
  
  p = sml;

  while(p->next)		//寻找小队的尾部
    p = p->next;
  
  p->next = pivot;		//连接小队和中心节点;
  pivot->next = big->next;	//连接中心节点和大队;
  
  *L = sml;			//赋值给链表参数 
}

//链表去重
//输入：L	链表指针
//输出：状态
//说明：对已经排序的链表进行去重
//	直接改变链表，不生成副本
Status delDuplicate(Link L){
  if(!L)return ERROR;
  Link q = NULL;
  Link t = NULL;
  Link p = L->next;
 
  while(p){
    q = p->next;
    while(q && q->data == p->data){	//如果连续相等尽量后移
       t = q;
       q = q->next;
       free(t);
    }
    p->next = q;
    p = q;
  }

  return OK;
}


//寻找两个链表相同的值
//输入：A	第一个链表指针
//	B	第二个链表指针
//返回：link	存储相同值的链表
//说明：对两个链表排序，排完后两个链表的指针依次从前向后比较值
//	如果相同记录，不同则移动较小值的指针，反复如此，直到其
//	中一个链表为空，比较的次数为O(m+n),排序时间复杂度为O(n*logN)
//	总的时间复制度就是排序的时间复杂度
Link getSameValue(Link A, Link B){
  if(!A || !B) return NULL;

  sortLink(&A);			//对A B链表快速排序，时间复杂度 0(NlogN)
  sortLink(&B);

  Link p = A->next;
  Link q = B->next;

  Link r;
  initLink(&r);

  while(p && q){
    if(p->data == q->data) {			//相等相等则加入链表中
      Link n = malloc(sizeof(Node));
      n->data = p->data;
      n->next = r->next;
      r->next = n;				//头插法存储相同值

      p = p->next;
      q = q->next;
    }
    else if(p->data < q->data) p = p->next;	//谁小谁往前移动    
    else q = q->next;
  }

  return r;
}
