#include<stdio.h>
#include<stdlib.h>
#define CutOff 4


void Swap(int * A1, int * A2){
    int tmp;
    tmp=*A1; *A1=*A2; *A2=tmp;
}

int Mind3(int A[],int left, int right){ //重点理解 为什么这么设计
    int center = (left + right)/2;
    if(A[left] > A[center])
        Swap(&A[left],&A[center]);
    if(A[left] > A[right])
        Swap(&A[left],&A[right]);
    if(A[center] > A[right])
        Swap(&A[center],&A[right]);

    Swap(&A[center],&A[right-1]);

    return A[right-1];
}


void Insertion_Sort(int A[],int N){
    int tmp;
    int i,j;
    for(i=1; i<N; i++){//from small to big
        tmp=A[i];
        for(j=i; (j>0)&&(tmp<A[j-1]); j--){
            A[j]=A[j-1];
        }
        A[j]=tmp;
    }
}

void Quick_Sort(int A[],int left, int right){
    int pivot,i,j;
    if(right-left>=CutOff){
        pivot=Mind3(A,left,right);
        i=left; j=right-1;
        for( ; ; ){
            while(A[++i]<pivot);
            while(A[--j]>pivot);
            if(j < i)
                break;
            Swap(&A[i],&A[j]);
        }
        Swap(&A[i],&A[right-1]);
        Quick_Sort(A,left,i-1);
        Quick_Sort(A,i+1,right);
    }else{
        Insertion_Sort(A+left,right-left+1);  ///重点理解
    }
}

int main(){
    int A[]={2,1,48,5,0,3,25,78,24};
    Quick_Sort(A,0,8);

    for(int i=0; i<9; i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    return 0;
}


/*
//a simple 

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void Swap(int A[],int a,int b){
    int tmp;
    tmp=A[a]; A[a]=A[b]; A[b]=tmp;
}

void QuickSort(int A[],int p, int r){
    int tmp,i,j;
    if( p-r > 4 ){
        tmp=A[p];
        i=p+1; j=r;
        while(i<j){
            for(;A[i]<=tmp;i++);
            for(;A[j]>tmp;j--);
            Swap(A,i,j);
            i++; j--;
        }
        Swap(A,p,j);
        QuickSort(A,p,j-1);
        QuickSort(A,j+1,r);
    }else{
        for(i=1;i<=r-p;i++){
            tmp=A[p+i];
            for(j=p+i-1;(j>=p)&&(A[j]>tmp);j--)
                A[j+1]=A[j];
            A[j+1]=tmp;
        }
    }
}

int main(){
    int N,i;
    int A[MAX];

    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);

    QuickSort(A,0,N-1);

    printf("%d",A[0]);
    for(i=1;i<N;i++)
        printf(" %d",A[i]);
    printf("\n");

    return 0;
}

*/