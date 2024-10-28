#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p;
    char c;
    int n;

    scanf("%d",&n);
    p=malloc(n);

    scanf("%c",&c);//注意在scanf和gets中间使用scanf("%c",&c),去除换行
    fgets(p,n,stdin);
    puts(p);

    free(p);

    return 0;
}
