#include <stdio.h>
#include <stdlib.h>

#define max_size 50
#define max_size2 5
typedef int elem_type;

//栈
//栈结构体
typedef struct{
    elem_type data[max_size];
    int top;
}sq_stack;

//初始化栈
void init_stack(sq_stack &s)
{
    s.top = -1;
}

//判断栈是否为空
bool is_stack_empty(sq_stack s)
{
    if(s.top==-1)
    {
        return true;
    }else{
        return false;
    }
}

//入栈
bool push(sq_stack &s,elem_type x)
{
    if(s.top==max_size-1)
    {
        return false;
    }
    s.top = s.top+1;
    s.data[s.top] = x;
    return true;
}

//出栈
bool pop(sq_stack &s,elem_type &x)
{
    if(s.top==-1)
    {
        return false;
    }
    x = s.data[s.top];
    s.top = s.top-1;
    return true;
}


//循环队列
//循环队列结构体
typedef struct{
    elem_type data[max_size2];
    int front,rear;
}sq_queue;

//初始化队列
void init_queue(sq_queue &q)
{
    q.rear = q.front = 0;
}

//队列判空
bool queue_is_empty(sq_queue &q)
{
    if(q.front==q.rear)
    {
        return true;
    }
    else return false;
}

//入队
bool en_queue(sq_queue &q,elem_type x)
{
    if((q.rear+1)%max_size2==q.front)
    {
        printf("false\n");
        return false;
    }
    q.data[q.rear] = x;
    q.rear = (q.rear+1)%max_size2;
    return true;
}

//出队
bool de_queue(sq_queue &q,elem_type &x)
{
    if (queue_is_empty(q))
        return false;
    x = q.data[q.front];
    q.front = (q.front+1)%max_size2;
    return true;
}
int main() {
    elem_type x[3];
    scanf("%d%d%d",&x[0],&x[1],&x[2]);
    elem_type y[5];
    scanf("%d%d%d%d%d",&y[0],&y[1],&y[2],&y[3],&y[4]);

    //栈操作
    sq_stack s;
    init_stack(s);
    elem_type xout[3];
    push(s,x[0]);
    push(s,x[1]);
    push(s,x[2]);
    pop(s,xout[0]);
    pop(s,xout[1]);
    pop(s,xout[2]);
    printf(" %d %d %d\n",xout[0],xout[1],xout[2]);

    //队操作
    sq_queue q;
    init_queue(q);
    elem_type yout[4];
    en_queue(q,y[0]);
    en_queue(q,y[1]);
    en_queue(q,y[2]);
    en_queue(q,y[3]);
    en_queue(q,y[4]);
    de_queue(q,yout[0]);
    de_queue(q,yout[1]);
    de_queue(q,yout[2]);
    de_queue(q,yout[3]);
    printf(" %d %d %d %d\n",yout[0],yout[1],yout[2],yout[3]);
    return 0;
}
