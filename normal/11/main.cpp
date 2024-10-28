#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//定义链表类
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//头插法创建链表
LinkList list_head_insert(LinkList &L)
{
    LNode *s;//LinkList s
    int x;

    L = (LinkList)malloc(sizeof(LNode));//为头节点申请空间，大小为一个LNode类的大小
    L->next = NULL;//将头节点的next域默认值设置为空
    scanf("%d",&x);//读取要插入的数据

    while(x<9999)//读取数据大小需小于9999
    {
        //s为临时节点，用于存放新加的节点，每个循环需申请空间是因为要为每个新加进的节点申请空间，链表的每个节点（除头节点）是没有名字的，他们仅靠nest指针相互链接在一起
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;//将读取的数据存放在新加节点s的data域中
        s->next = L->next;//将头节点的next域赋给新加节点的next域，也就是将s->next链接到原来的链表第一个元素处（或NULL）
        L->next = s;//将s链接到头节点上，成为新的第一号元素
        scanf("%d",&x);//读取新的插入的数据
    }
    return L;
}

//尾插法创建链表
LinkList list_tail_insert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));//为头节点申请空间，大小为一个LNode类的大小
    LNode *s;//用于存放新加节点
    LNode *r=L;//用于时刻指向尾部节点，默认值为L
    int x;
    L->next = NULL;
    scanf("%d",&x);

    while(x<9999)
    {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

//输出L
void PrintList(LinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%d",L->data);//打印当前结点数据
        L=L->next;//指向下一个结点
        if(L!=NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}


int main() {
    LinkList L1,L2;
    list_head_insert(L1);
    list_tail_insert(L2);
    PrintList(L1);
    PrintList(L2);
    return 0;
}
