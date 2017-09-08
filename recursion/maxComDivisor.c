#include <stdio.h>

int Gcd(int a,int b){
  if(b==0)return a;
  return Gcd(b,a%b);
}


int main(){
  int a,b;
  printf("enter a:");
  scanf("%d",&a);
  printf("enter b:");
  scanf("%d",&b);

  printf("Maxmum commond divisor is %d\n",Gcd(a,b)); 
}
