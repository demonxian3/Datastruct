#include <stdio.h>

int Gcd(int a,int b){
  if(b==0)return a;
  return Gcd(b,a%b);
}


int main(){
  int a,b;
  printf("Enter a,b: ");
  scanf("%a,%d",&a,&b);

  printf("Maxmum commond divisor is %d\n",Gcd(a,b)); 
}
