#include <stdio.h>

int main() {
    int num,ans=1;
    scanf("%d",&num);

    for (int i=1;i<=num;i++)
    {
        ans = ans*i;
    }
    printf("%d",ans);
    return 0;
}
