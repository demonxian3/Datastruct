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
  int i,val;
  ST->elem = (ElemType *)malloc(n *sizeof(ElemType));
  ST->length = n;
  for(i=1;i<=n;i++){
    printf("[%d]input value: ",i);
    scanf("%d",&val);
    ST->elem[i].key = val;
  }

  //output and debug
  for(i=1;i<=n;i++)
    printf("[%d] %d\n",i,ST->elem[i].key);
}

int search_bin(Stable ST,KeyType key){
  
  int count = 0; //statistics
  int low = 1;
  int len = ST.length;
  int high = len;
  
  while(low<=high){               //include '=',because match boundary element.
    count++;
    int mid = (low+high)/2;
    if(key == ST.elem[mid].key){   //found it
      printf("[count]:%3d  ",count);
      return mid;
    }
    else if(key < ST.elem[mid].key)  //before area
      high = mid-1;
    else
      low = mid+1;
  }
  
  printf("[count]:%3d  ",count);
  return 0;
}

int main(){
  int n,r,k;
  Stable ST;

  printf("Enter the number of key: ");
  scanf("%d",&n);
  createTestData(&ST,n);

  while(1){
    printf("Enter the key value for search: ");
    scanf("%d",&k);

    if(!(r = search_bin(ST,k)))
      printf("Sorry,the key is not found\n");
    else
      printf("Found it,the key's index is:%d\n",r);
  }
  return 0;
}

/*
Enter the number of key: 8
[1]input value: 7  
[2]input value: 14
[3]input value: 17
[4]input value: 22
[5]input value: 28
[6]input value: 31
[7]input value: 34
[8]input value: 44
[1] 7
[2] 14
[3] 17
[4] 22
[5] 28
[6] 31
[7] 34
[8] 44
Enter the key value for search: 5
[count]:  3  Sorry,the key is not found
Enter the key value for search: 7
[count]:  3  Found it,the key's index is:1
Enter the key value for search: 13
[count]:  3  Sorry,the key is not found
Enter the key value for search: 14
[count]:  2  Found it,the key's index is:2
Enter the key value for search: 17
[count]:  3  Found it,the key's index is:3
Enter the key value for search: 22
[count]:  1  Found it,the key's index is:4
Enter the key value for search: 24
[count]:  3  Sorry,the key is not found
Enter the key value for search: 28
[count]:  3  Found it,the key's index is:5
Enter the key value for search: 31
[count]:  2  Found it,the key's index is:6
Enter the key value for search: 34
[count]:  3  Found it,the key's index is:7
Enter the key value for search: 44
[count]:  4  Found it,the key's index is:8
Enter the key value for search: 49
[count]:  4  Sorry,the key is not found
  34 / 12 = 2.8
*/
