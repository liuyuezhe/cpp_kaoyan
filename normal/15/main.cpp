#include <stdio.h>
#include <stdlib.h>

typedef int key_type;
typedef struct bst_node
{
    key_type key;
    struct bst_node *lchild,*rchild;
}bst_node,*bi_tree;

//向树中插入节点
int bst_insert(bi_tree &t,key_type k)
{
    if(t==NULL)//树为空，即插入第一个节点
    {
        t = (bi_tree)malloc(sizeof (bst_node));
        t->key = k;
        t->rchild = t->lchild = NULL;
        return 1;
    }
    bi_tree p = t,parent;
    while (p)//找该插入的节点的位置
    {
        parent = p;
        if(k==p->key)
        {
            return 0;
        }
        else if(k<p->key)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    //插入节点
    bi_tree pnew = (bi_tree) malloc(sizeof (bst_node));
    pnew->key = k;
    pnew->rchild = pnew->lchild = NULL;
    if(k > parent->key)
    {
        parent->rchild = pnew;
    }
    else
    {
        parent->lchild = pnew;
    }
    return 1;
}

//创建树,并插入节点
void creat_bst(bi_tree &t,key_type lst[],int n)
{
    t = NULL;
    int i = 0;
    while(i<n)
    {
        bst_insert(t,lst[i]);
        i++;
    }
}

//中序遍历
int elem_pos = 0;
void in_order(bi_tree t,key_type *arr)
{
    if(t!=NULL)
    {
        in_order(t->lchild,arr);
        printf("%3d",t->key);
        arr[elem_pos] = t->key;
        elem_pos++;
        in_order(t->rchild,arr);
    }
}

int binary_search(key_type *arr,key_type key)
{
    int len = 10;
    int low = 0;
    int high = len-1;
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid]>key)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int main() {
    bi_tree t;
    key_type lst[10];
    key_type arr[10];
    for(int i;i<10;i++)
    {
        scanf("%d",&lst[i]);
    }
    creat_bst(t,lst,10);
    in_order(t,arr);
    printf("\n");
    printf("%d", binary_search(arr,21));
    return 0;
}
