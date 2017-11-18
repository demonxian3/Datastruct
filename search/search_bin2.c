#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXNUM 20

typedef int KeyType;
typedef struct {
  KeyType key;
  //other data
}ElemType;

typedef struct {
  ElemType *elem;
  int length;
}Stable;

void createTestData(Stable *ST,int n){
  int i;
  for(i=1;i<=n;i++){

  }
}

int main(){
  int n;
  Stable ST
  printf("Enter the number of key: ");
  scanf("%d",&n);
  Stable ST = createTestData(n);
  return 0;
}
