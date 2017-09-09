#include <stdio.h>
void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void out(n){
 if(n==1){
   printf("1");
   return;
 }

 int i;
 for(i=1;i<n;i++){
   printf("%d",i);
   out(n-1)
 }
}

int main(){
  out(3);
  return 0;
}
