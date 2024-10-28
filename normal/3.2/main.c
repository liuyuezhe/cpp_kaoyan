#include <stdio.h>

int main() {
    int i;
    char j;
    float k;
    float num;
    scanf("%d %c%f",&i,&j,&k);
    num = i+j+k;
    printf("%0.2f\n",num);
    return 0;
}
