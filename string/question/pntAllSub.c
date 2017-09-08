#include <stdio.h>
//give your a string like "abcde";
//then,please print next the result:

//a	b	c	d	e
//ab    bc      cd      de
//abc	bcd	cde	
//abcd  bcde
//abcde


int main(){
  int i,j,k;
  char s[255] = "abcde";
 
  for(i=0;i<5;i++){
    for(j=0;j<i+1;j++){
        printf("%c",s[j]);
      }
    printf("\n");
  }

  for(k=0;k<5;k++){ 
    for(i=0;i<5;i++){
      for(j=k;j<i+1;j++){
        printf("%c",s[j]);
      }
      printf("    ");
    }
    printf("\n");
  }

  printf("========================================\n");
  for(i=0;i<5;i++){
    for(k=0;k<5;k++){ 
      for(j=k;j<i+1;j++){
        printf("%c",s[j]);
      }
      printf("\t");
    }
    printf("\n");
  }
  
  printf("========================================\n");
  for(i=0;i<5;i++){
    for(k=0;k<5-i;k++){ 
      for(j=k;j<k+i+1;j++){
        printf("%c",s[j]);
      }
      printf("\t");
    }
    printf("\n");
  }

  return 0;
}
