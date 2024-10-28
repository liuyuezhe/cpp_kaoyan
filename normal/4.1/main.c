#include <stdio.h>

int main() {
    int a,num,tmp = 0;
    scanf("%d",&a);
    num = a;

    while (num)
    {
        tmp = tmp*10;
        tmp = tmp+num%10;
        num = num/10;
    }

    if(tmp == a)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

    return 0;
}
