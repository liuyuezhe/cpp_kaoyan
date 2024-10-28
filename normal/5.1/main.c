#include <stdio.h>

int main() {
    int a[100];
    int n;
    int times = 0;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i] == 2)
        {
            times++;
        }
    }
    printf("%d",times);
    return 0;
}
