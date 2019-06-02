#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX  1001
int GetLeftLength(int n){
    int lastLayLeft;
    int layerb = log(n)/log(2);
    int NumLayb = pow(2,layerb)-1;
    int lastLay = n-NumLayb;
    int lastLayVol = pow(2,layerb);
    if(lastLay<=(lastLayVol/2))
        lastLayLeft=lastLay;
    else
        lastLayLeft=lastLayVol/2;

    return ( (NumLayb-1)/2+lastLayLeft );
}

void Solve(int a[],int b[],int aLeft,int aRight,int TRoot){
    int L,n;

    n = aRight-aLeft+1;
    if(n==0) return;

    L=GetLeftLength(n);
    b[TRoot]=a[aLeft+L];

    Solve(a,b,aLeft,aLeft+L-1,TRoot*2+1);// 递归左子树
    Solve(a,b,aLeft+L+1,aRight,TRoot*2+2);//递归右子树

}

int compare(const void * a, const void * b)  
 {  
     return *(int *)a - *(int *)b;  
 }  

int main(){
    int N;
    int a[MAX],b[MAX];
    int i;

    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);

    qsort(a,N,sizeof(int),compare);
    Solve(a,b,0,N-1,0);

    printf("%d",b[0]);
    for(i=1;i<N;i++)
        printf(" %d",b[i]);

    return 0;
}