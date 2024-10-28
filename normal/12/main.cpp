#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

node* linklist_tail_insert(node* &L)//尾插法新建链表
{
    int x;
    L = (node*) malloc(sizeof(node));
    node *s;
    node *r = L;
    scanf("%d",&x);
    while (x<9999)
    {
        s = (node*) malloc(sizeof(node));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

void print_list(node* L)
{
    L = L->next;
    while (L!= NULL)
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}

void find_second_value(node* L)
{
    int i = 2;
    node *p;
    p = L;
    for (int j = 0;j<i;j++)
    {
        if(p->next)
        {
            p = p->next;
        }
        else
        {
            return;
        }
    }
    printf("%d\n",p->data);
}

bool insert99_in_secondplace(node *L)
{
    int i = 2;
    node *p,*s;
    s = (node*) malloc(sizeof(node));
    p = L;

    for(int j=0;j<i-1;j++)
    {
        if(p->next)
        {
            p = p->next;
        }
        else
        {
            return false;
        }
    }
    s->data = 99;
    s->next = p->next;
    p->next = s;
    return true;
}

void delete_forth(node *L)
{
    int i = 4;
    node *p,*s=NULL;
    p = L;

    for (int j = 0;j<i-1;j++)
    {
        if(p->next)
        {
            p = p->next;
        }
        else
        {
            return;
        }
    }
    s = p->next;
    p->next = s->next;
    free(s);
}

int main() {
    node *L;
    linklist_tail_insert(L);
    find_second_value(L);
    insert99_in_secondplace(L);
    print_list(L);
    delete_forth(L);
    print_list(L);
    return 0;
}