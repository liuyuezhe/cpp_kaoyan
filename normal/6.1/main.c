#include <stdio.h>

int change(int* i)
{
    int res;
    res = *i / 2;
    return res;
}

int main() {
    int i;
    int *i_pointer;

    scanf("%d",&i);
    i_pointer = &i;
    printf("%d",change(i_pointer));

    return 0;
}
