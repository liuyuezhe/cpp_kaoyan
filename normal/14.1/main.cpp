#include "function.h"

//前序遍历
void pre_order(bi_tree tree)
{
    if(tree!=NULL)
    {
        printf("%c",tree->c);
        pre_order(tree->lchild);
        pre_order(tree->rchild);
    }
}

//中序遍历
void in_order(bi_tree tree)
{
    if(tree!=NULL)
    {
        in_order(tree->lchild);
        printf("%c",tree->c);
        in_order(tree->rchild);
    }
}

//后序遍历
void post_order(bi_tree tree)
{
    if(tree!=NULL)
    {
        post_order(tree->lchild);
        post_order(tree->rchild);
        printf("%c",tree->c);
    }
}

void level_order(bi_tree tree)
{
    LinkQueue Q;
    InitQueue(Q);
    bi_tree p;
    EnQueue(Q,tree);
    while(!IsEmpty(Q))
    {
        DeQueue(Q,p);
        printf("%c",p->c);
        if(p->lchild)
        {
            EnQueue(Q,p->lchild);
        }
        if(p->rchild)
        {
            EnQueue(Q,p->rchild);
        }
    }
}

int main() {
    bi_tree pnew;//建立一个指向树结构体的指针，用来存放新建立的节点
    char c;
    bi_tree tree = NULL;//树根节点
    //phead是指向队列头的指针，ptail是指向队列尾的指针
    //pcur指向当前子树的根节点，在当前节点的左右节点满后，pcur会在队列中往前进一个节点，再添加其左右节点，以此类推
    //listpnew是所需队列，用于存放以进入树的节点
    ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur=NULL;

    while(scanf("%c",&c))//读取要放入树的字符
    {
        if(c=='\n')
        {
            break;
        }
        //拿到一个c后，要将其加入到tree中，也要加入到队列中，因此需要申请两个空间
        //tree空间用于存放c本身
        //队列空间用于存放c在树中的那个节点
        pnew = (bi_tree)calloc(1,sizeof(bi_tree_node));//对新加入节点申请空间
        pnew->c = c;
        listpnew = (ptag_t)calloc(1,sizeof(tag_t));//给队列节点申请空间
        listpnew->p = pnew;

        //将节点存放在树中
        if(tree==NULL)//此时树是空的
        {
            tree = pnew;//pnew中存放的是一个地址（由calloc申请，大小为sizeof(bi_tree_node)），将这个地址再放进tree中，即可通过指针访问
            phead = listpnew;//与上同理，存入phead，ptail，pcur的是一个地址，指向一个tag，其中p存放的是pnew的地址，以及一个指向tag类型的指针（参考链表/链队列）
            ptail = listpnew;
            pcur = listpnew;
        }else{//树不为空，则正常存入节点
            if(pcur->p->lchild==NULL)//加入树
            {
                pcur->p->lchild = pnew;
            }
            else if(pcur->p->rchild==NULL)
            {
                pcur->p->rchild = pnew;
                pcur = pcur->pnext;
            }
            //加入队列
            ptail->pnext = listpnew;//将尾节点的指针域指向新加进的
            ptail = listpnew;
        }
    }

    //打印树
//    pre_order(tree);
//    printf("\n");
    in_order(tree);
    printf("\n");
    post_order(tree);
    printf("\n");
    level_order(tree);
    printf("\n");
    return 0;
}
