#include<stdio.h>
#define MAX 10002

int main(){
    int N,i,flag=0;
    int p,r,sum;
    int Maxp,Maxr,MaxSum;
    int A[MAX];
    p=r=sum=0;
    Maxp=Maxr=MaxSum=0;

    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    while(r<N){
        sum += A[r];
        if(A[r]>=0) flag=1;
        //printf("*%d %d*\n",sum,MaxSum);
        if(sum>MaxSum){
            MaxSum=sum;
            Maxp=p; Maxr=r;
        }
        r++;
        if(sum<0){
            sum=0;
            p=r;    
        }
    }
    if(MaxSum==0){
        if(flag==0){
            printf("0 %d %d\n",A[0],A[N-1]);
        }else{
            printf("0 0 0\n");
        }
    }else{
        printf("%d %d %d\n",MaxSum,A[Maxp],A[Maxr]);
    }

   

    return 0;

}