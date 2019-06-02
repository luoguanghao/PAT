#include<stdio.h>
#define MAX 1001

int size=0;

void MinHeap(){

}

void Insert(int a[],int x){
    int i;
    for(i=++size; a[i/2]>x; i/=2)
        a[i]=a[i/2];
    a[i]=x;
}

void Print(int a[],int x){
    printf("%d",a[x]);
    for(int i=x/2;i>=1;i/=2)
        printf(" %d",a[i]);
    printf("\n");
}

int main(){
    int n,m,x;
    int i;
    int a[MAX];
    a[0]=-99999;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        Insert(a,x);
    }

    for(i=1;i<=m;i++){
        scanf("%d",&x);
        Print(a,x);
    }

    return 0;
}