#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 20
#define FIRST_NAME_LEN 20
#define LAST_NAME_LEN 30 

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} part1 = {528, "Disk drive", 10}, part2;

typedef struct {
  char fname[FIRST_NAME_LEN+1];
  char lname[LAST_NAME_LEN+1];
  struct part part;
} order;

  
void printPart(struct part p){
  printf("name: %s\n", p.name);
  printf("number: %d\n", p.number);
  printf("on_hand: %d\n", p.on_hand); 
}

struct part builtPart(void){
  struct part p = {34, "Printer", 12};
  return p;
}

int main(){

  // test for part
  int part = 3;
  printf("part is digit: %d\n",part);
  struct part part3 = {111, "CPU", 33}, part4;
  part2 = part1;
  part4 = builtPart();
  printPart(part4);
  printf("part3's %s\n", part3.name);
  printf("[type part]size: %d\n", sizeof(part1));

  // test for order
  order o1 = {"li", "zixian", part3};
  printf("%s %s have %s\n", o1.fname, o1.lname, o1.part.name);
  printf("[type order]size: %d\n", sizeof(o1));

  // test for dialing code
  struct dialingCode{
    char *country;
    unsigned int code;
  };

  const struct dialingCode cc[20] = {{"China",  86},
				     {"Japan",  81},
				     {"Korea",  82},
				     {"Italy",  62},
				     {"Poland", 92},};  //allow tail ','
  
  struct dialingCode dd,ee;
  dd = cc[1];				/* legal   */
  //ee = cc; 				/* illegal */

  //scanf("%s", ee.country); 		/* segmentfault */
  //printf("%s\n", ee.country);
  
  const struct dialingCode *kk = cc;

  printf("code: %d\n", (*kk).code);
  kk++;	
  printf("code: %d\n", kk->code);

  printf("debug\n");
  return EXIT_SUCCESS;
}
