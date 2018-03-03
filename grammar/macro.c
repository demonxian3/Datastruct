#include <stdio.h>
#include <stdlib.h>

#define TRUE 		1
#define FALSE 		0

#define MONEY 		int

#define START 		int main()
#define BEGIN 		{
#define END   		}
#define LOOP		for(;;)
#define CCLEAR		getchar();
#define EXIT_		return 0;

#define CHARAT		char
#define STRING 		char*

#define CR		"\n"
#define CS_int		"%d"
#define CS_char		"%c"
#define CS_float	"%f"
#define CS_STRING 	"%s"

#define ADD(x,y) 	((x)+(y))
#define MAX(x,y) 	((x)>(y)?(x):(y))
#define MIN(x,y) 	((x)<(y)?(x):(y))
#define IS_EVEN(x)	((x)%2==0)
#define IS_ODD(x)	((x)%2==1)
#define TOUPPER(c)	('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

#define PRINS(x)	printf(#x);
#define PRINT(t,x)	printf(CS_##t CR, (x))
#define SCANF(t,x)	scanf(CS_##t, &(x))
#define INPUT(t,x)	(printf("[INPUT ("#t")"#x"]: " ),scanf(CS_##t,&(x)))


#define MALLOC(t,l)	malloc(sizeof(t)*(l))
#define PSIZE(x) 	PRINT(int,sizeof(x))

#define GENERIC_PRINTARR(t)		\
void printArr_##t(t *arr, int len){	\
   while(len--)				\
     printf(CS_##t, *arr++);		\
   printf(CR);				\
}					

GENERIC_PRINTARR(int)

int fastLog2(int i){
   float fx = (float)i;
   unsigned long exp,ix =  *((unsigned long*)&fx);
   exp = (ix>>23) & 0xFF;
   return exp-127;
}

#define SHOWBINARY(n)			\
do{					\
	PRINT(int,n);			\
	int *arr = MALLOC(int,100);	\
	int i = fastLog2(n);		\
	int *p = arr + i;		\
	while(n){			\
		*p-- = (n%2);		\
		n /= 2;			\
	}				\
	PRINS("[BINARY]: ");		\
	printArr_int(arr,i+1);		\
}while(0)


START
BEGIN
	MONEY a,b,i;
	CHARAT c;

	LOOP 
	BEGIN
		INPUT(int,a);
		if(IS_EVEN(a)) break;
		//cannot use i, because function is macro.
		SHOWBINARY(a);		
	END
	CCLEAR

	INPUT(char,c);
	PRINT(char,TOUPPER(c));

	PRINS([__DATE__]: );
	PRINT(STRING, __DATE__);	

	PRINS([__LINE__]: );
	PRINT(int, __LINE__);	

	PRINS([__FILE__]: );
	PRINT(STRING, __FILE__);	

	PRINS([__TIME__]: );
	PRINT(STRING, __TIME__);	

	PRINS([__STDC__]: );
	PRINT(int, __STDC__);	

	EXIT_
END
