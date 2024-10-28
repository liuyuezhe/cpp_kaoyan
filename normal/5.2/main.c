#include <stdio.h>
#include <string.h>

int main() {

    char c[100];
    char d[100];
    int length=0;

    gets(c);
    length = strlen(c);

    for(int i = 0;i<=length;i++)
    {
        d[i] = c[length-1-i];
    }


    int result = strcmp(c, d);

    if (result < 0)

    {

        printf("%d\n",-1);

    }

    else if (result > 0)

    {

        printf("%d\n", 1);

    }

    else {

        printf("%d\n", 0);

    }
    return 0;
}
