#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//冒泡排序
void bubble_sort(ss_table &st)
{
    int i,j;
    for(i=0;i<st.table_len;i++)
    {
        for(j=st.table_len-1;j>i;j--)
        {
            if(st.elem[j-1]>st.elem[j])
                swap(st.elem[j-1],st.elem[j]);
        }
    }
    st_print(st);
}

//快速排序
int partition(elem_type a[],int low,int high)
{
    elem_type pivot = a[low];
    while (low<high)
    {
        while (low<high && a[high]>pivot)
            high--;
        a[low] = a[high];
        while (low<high && a[low]<pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quick_sort(elem_type a[],int low,int high)
{
    if(low<high)
    {
        int pivot_pos = partition(a,low,high);
        quick_sort(a,low,pivot_pos-1);
        quick_sort(a,pivot_pos+1,high);
    }
}

//插入排序
void insert_sort(elem_type a[],int n)
{
    int i,j,insert_val;
    for(i=1;i<n;i++)
    {
        insert_val = a[i];
        for(j=i-1;j>=0 && insert_val<a[j];j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = insert_val;
    }
}

int main() {
    ss_table st0,st1,st2;
    st_init(st0,10);
    st_copy(st0,st1);
    st_copy(st0,st2);
    bubble_sort(st0);
    quick_sort(st1.elem,0,st1.table_len-1);
    st_print(st1);
    insert_sort(st2.elem,st2.table_len);
    st_print(st2);
    return 0;
}
