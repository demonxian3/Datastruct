#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXNUM 20

typedef int KeyType;
typedef struct {
  KeyType key;
}ElemType;

void createTestData(ElemType *data,int n){
  int i;
  for(i=1;i<=n;i++){
    printf("[%d]Enter the value: ",i);
    scanf("%d",&data[i].key);
  }
}

int search_bin(ElemType *data,KeyType key,int n){
  int count = 0; //statistics
  int low,high,mid;

  low = 1;
  high = n;
  mid = (low+high)/2;
  
  while(data[mid].key!=key){
    count++;
    if(key<data[mid].key)
      high = mid - 1;
    else
      low = mid + 1;

    mid = (low+high)/2;
    if(high<low){          /*
                            * can't use the "low<=mid||high<=low",
                            * because it exclude the boundary element;
                            */
                                          
      printf("[count]: %d  ",count);
      return 0;
    }
  }
  
  if(count==0)count++;
  printf("[count]: %d  ",count);
  return mid;
}

int main(){
  int i,n,key,res;
  ElemType data[MAXNUM];
  printf("Enter the number of key: ");
  scanf("%d",&n);
  
  createTestData(data,n);

  for(i=1;i<=n;i++)
    printf("[%d]: %d \n",i,data[i].key);

  while(1){
    printf("Enter the key value: ");
    scanf("%d",&key);
    
    res = search_bin(data,key,n);
    if(!res)
      printf("Sorry, the key was not found\n");
    else
      printf("Found it,the key's index is:%d\n",res);
  }
}

/* [Test Data]
Enter the number of key: 8
[1]Enter the value: 7
[2]Enter the value: 14
[3]Enter the value: 17
[4]Enter the value: 22
[5]Enter the value: 28
[6]Enter the value: 31
[7]Enter the value: 34
[8]Enter the value: 44
[1]: 7 
[2]: 14 
[3]: 17 
[4]: 22 
[5]: 28 
[6]: 31 
[7]: 34 
[8]: 44 
Enter the key value: 5
[count]: 3  Sorry, the key was not found
Enter the key value: 7
[count]: 2  Found it,the key's index is:1
Enter the key value: 13
[count]: 3  Sorry, the key was not found
Enter the key value: 14
[count]: 1  Found it,the key's index is:2
Enter the key value: 17
[count]: 2  Found it,the key's index is:3
Enter the key value: 22
[count]: 1  Found it,the key's index is:4
Enter the key value: 24
[count]: 3  Sorry, the key was not found
Enter the key value: 28
[count]: 2  Found it,the key's index is:5
Enter the key value: 31
[count]: 1  Found it,the key's index is:6
Enter the key value: 34
[count]: 2  Found it,the key's index is:7
Enter the key value: 44
[count]: 3  Found it,the key's index is:8
Enter the key value: 49
[count]: 4  Sorry, the key was not found

  25/12 = 2

*/

