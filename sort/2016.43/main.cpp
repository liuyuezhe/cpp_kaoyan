#include <stdio.h>
#include <stdlib.h>

int set_partition(int a[],int n)
{
    int pivotkey,low=0,high=n-1,low0=0,high0=n-1,flag=1,k=n/2,i;
    int s1=0,s2=0;

    while(flag)
    {
        pivotkey = a[low];
        while (low<high)
        {
            while (low<high && a[high]>pivotkey)
                high--;
            if(low!=high) a[low] = a[high];
            while (low<high && a[low]<pivotkey)
                low++;
            if(low!=high) a[high] = a[low];
        }
        a[low] = pivotkey;

        if(low==k-1) flag=0;
        else
        {
            if(low<k-1)
            {
                low++;
                low0 = low;
                high = high0;
            }
            else if(low>k-1)
            {
                high = low-1;
                high0 = low-1;
                low = low0;
            }
        }
    }
    for(i=0;i<k;i++) s1 = s1+a[i];
    for(i=k;i<n;i++) s2 = s2+a[i];
    for(int j=0;j<n;j++)
    {
        printf("%3d",a[j]);
    }
    printf("\n");
    return s2-s1;
}

int main() {
    int a[10] = {4,1,12,18,7,13,18,16,5,15};//1 4 5 7 12 13 15 16 18 18
    int difference;
    difference = set_partition(a,10);
    printf("%d",difference);
    return 0;
}
