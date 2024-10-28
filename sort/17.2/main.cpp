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

//归并排序
void merge(elem_type a[],int low,int mid,int high)
{
    static elem_type b[10];
    int i,j,k;
    for(k=low;k<=high;k++)
    {
        b[k] = a[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid && j<=high;k++)
    {
        if(b[i]<b[j])
        {
            a[k] = b[i];
            i++;
        }else{
            a[k] = b[j];
            j++;
        }
    }
    while (i<=mid)
    {
        a[k] = b[i];
        k++;
        i++;
    }
    while (j<=high)
    {
        a[k] = b[j];
        k++;
        j++;
    }
}

void merge_sort(elem_type a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    ss_table st0;
    st_init(st0,10);
    merge_sort(st0.elem,0,st0.table_len-1);
    st_print(st0);
    return 0;
}