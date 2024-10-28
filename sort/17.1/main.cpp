#include <stdio.h>
#include <stdlib.h>

typedef int elem_type;
typedef struct
{
    elem_type *elem;
    int table_len;
}ss_table;

//对elem初始化
void st_init(ss_table &st,int len)
{
    st.table_len = len;
    st.elem = (elem_type*)malloc(sizeof(elem_type)*st.table_len);
    for(int i=0;i<st.table_len;i++)
    {
        scanf("%d",&st.elem[i]);
    }
}

void st_copy(ss_table &st1,ss_table &st2)
{
    st2.elem = (elem_type*)malloc(sizeof(elem_type)*st1.table_len);
    st2.table_len = st1.table_len;
    for(int i=0;i<st1.table_len;i++)
    {
        st2.elem[i] = st1.elem[i];
    }
}

//打印数组
void st_print(ss_table st)
{
    for(int i=0;i<st.table_len;i++)
    {
        printf("%3d",st.elem[i]);
    }
    printf("\n");
}

//交换元素
void swap(elem_type &a,elem_type &b)
{
    elem_type tmp;
    tmp = a;
    a = b;
    b = tmp;
}

//选择排序
void select_sort(elem_type a[],int n)
{
    int i,j,min;
    for (i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min = j;
        }
        swap(a[i],a[min]);
    }
}

//堆排序
void adjust_down(elem_type a[],int k,int len)
{
    int dad,son;
    dad = k;
    son = 2*dad+1;
    while(son<len)
    {
        if(son+1<len && a[son]<a[son+1])
        {
            son++;
        }
        if(a[dad]<a[son])
        {
            swap(a[dad],a[son]);
            dad = son;
            son = 2*dad+1;
        }else{
            break;
        }
    }
}

void HeapSort1(elem_type a[], int len)
{
    int i;
    for(i=(len/2-1);i>=0;i--)//先把树，变成大根堆
    {
        adjust_down(a,i,len);
    }
    swap(a[0],a[len-1]);//此时a[len-1]就是最大的树
    for(i=len-1;i>1;i--)
    {
        adjust_down(a,0,i);
        swap(a[0],a[i-1]);
    }
}

int main()
{
    ss_table st0,st1;
    st_init(st0,10);
    st_copy(st0,st1);
    select_sort(st0.elem,st0.table_len);
    st_print(st0);
    HeapSort1(st1.elem,st1.table_len);
    st_print(st1);
    return 0;
}