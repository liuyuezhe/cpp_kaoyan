//
// Created by 84478 on 2024/10/21.
//

#ifndef INC_14_1_FUNCTION_H
#define INC_14_1_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>

typedef char bi_elem_type;

typedef struct bi_tree_node{
    bi_elem_type c;
    struct bi_tree_node *lchild;
    struct bi_tree_node *rchild;
}bi_tree_node,*bi_tree;

typedef struct tag{
    bi_tree p;
    struct tag *pnext;
}tag_t,*ptag_t;

//队列的数据结构声明
typedef bi_tree ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;//链表头 链表尾,也可以称为队头，队尾
}LinkQueue;//先进先出
//队列的初始化，使用的是带头结点的链表来实现的
void InitQueue(LinkQueue &Q);
//入队
void EnQueue(LinkQueue &Q,ElemType x);
//出队
bool DeQueue(LinkQueue &Q,ElemType &x);
bool IsEmpty(LinkQueue Q);
#endif //INC_14_1_FUNCTION_H
