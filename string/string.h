int readLine(char [], int);
int countChar(const char [], char );

size_t myStrlen(const char *);

char *myStrcpy(char [], const char []);
char *myStrcat(char [], const char []);

char *myStrncpy(char [], const char [], int);
char *myStrncat(char [], const char [], int);






int readLine(char str[], int n){
    int i = 0;
    while( i<n && (*str = getchar()) != '\n' && *str++ != EOF) i++;
    *str = '\0';
    return i;
}

size_t myStrlen(const char *str){
    const char *p = str;
    while(*p) p++;          // while(*p != 0)  // 0 == '\0'
    return p - str;
}

int countChar(const char str[], char c){
    int n = 0;
    while(*str != 0)
        if(*str++ == c)
          n++;
    return n;
}

char *myStrcpy(char *s1, const char *s2){
    char *p = s1;
    while(*s2)
        *p++ = *s2++;
    *p = '\0';
    return s1;  
}

char *myStrncpy(char *s1, const char *s2, int n){
    char *p = s1;
    while(*s2 && n--)
        *p++ = *s2++;
    *p = '\0';
    return s1;  
}

char *myStrcat(char *s1, const char *s2){
    char *p = s1;
    while(*s1) s1++;
    while(*s1++ = *s2++);
    *s1 = '\0';
    return p;
}

char *myStrncat(char *s1, const char *s2, int n){
    char *p = s1;
    while(*s1) s1++;
    while(n && (*s1++ = *s2++) )n--;
    *s1 = '\0';
    return p;
}

