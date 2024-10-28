#include <stdio.h>

typedef struct student
{
    int num;
    char name[20];
    char sex;
}stu,*pstu;

int main() {
    stu s1;
    scanf("%d %s %c",&s1.num,s1.name,&s1.sex);
    printf("%d %s %c\n",s1.num,s1.name,s1.sex);
    return 0;
}
