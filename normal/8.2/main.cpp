#include <stdio.h>
#include <stdlib.h>

void get(char *&p)
{
    p = (char*)malloc(100);
    fgets(p,100,stdin);
}

int main() {
    char *p;
    get(p);
    printf("%s",p);
    free(p);
    return 0;
}
