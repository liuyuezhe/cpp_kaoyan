#include <stdio.h>
#define MaxSize 50
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

bool ListInsert(SqList &L,ElemType e){
    int i = 2;
    for(int j=L.length;j>=i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
};

void PrintList(SqList L){
    for(int i=0;i<L.length;i++){
        printf("  %d",L.data[i]);
//        if(i<L.length-1){
//            printf("  ");
//        }
    }
    printf("\n");
};

bool ListDelete(SqList &L,int i){
    if(i<1 || i>L.length){
        return false;
    }
    for (int j=i;j<L.length;j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
};

int main() {
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    bool ret;
    int in;
    int out;
    scanf("%d",&in);
    ListInsert(L,in);
    PrintList(L);
    scanf("%d",&out);
    ret = ListDelete(L,out);
    if(ret){
        PrintList(L);
    }else{
        printf("false");
    };
    return 0;
}
