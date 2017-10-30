/*****************************************
 *             Tower of Hanoi           *
 *****************************************
 *                                       *
 *        _|_        |         |         *
 *      _|___|_      |         |         *
 *    _|_______|_    |         |         *
 *   |           |   |         |         *
 * --------|---------|---------|-------  *
 *         A         B         C         *
 *                                       *
 *****************************************/

#include <stdio.h>

void Hanoi(int n,char a,char b,char c){
   if(n == 1){
     printf("%c -> %c\n",a,c);
     return;
   }

   //通用情况：
   Hanoi(n-1,a,c,b);   //将前n-1移动到B
   Hanoi(1,a,b,c);     //将第n个移动到C
   Hanoi(n-1,b,a,c);   //将前n-1移动到C
}

int main(){

    printf("***************************************** \n");
    printf("*             Tower of Hanoi            * \n");
    printf("***************************************** \n");
    printf("*                                       * \n");
    printf("*        _|_        |         |         * \n");
    printf("*      _|___|_      |         |         * \n");
    printf("*    _|_______|_    |         |         * \n");
    printf("*   |           |   |         |         * \n");
    printf("* --------|---------|---------|-------  * \n");
    printf("*         A         B         C         * \n");
    printf("*                                       * \n");
    printf("***************************************** \n");

   char a = 'a';
   char b = 'b';
   char c = 'c';
   int N;
   printf("Enter the number of disk: ");
   scanf("%d",&N);
   Hanoi(N,a,b,c);
   return 0;
}
