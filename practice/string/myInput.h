#ifndef myInput_H
#define myInput_H
#define CR          "\n"
#define CS_INT      "%d"
#define CS_FLO      "%f"
#define CS_DOU      "%lf"
#define CS_CHA      "%c"
#define CS_STR      "%s"

#define INPUT(t,x,s)    \
    (printf(s),scanf(CS_##t,x))

#define PRINTI(x)       \
    (printf("%d", x))

#define PRINTI_ARR(x,l)             \
    do{                             \
        int i;                      \
        for(i = 0; i < (l); i++)    \
            printf("%d", *((x)+i));   \
    }while(0)

#endif 

