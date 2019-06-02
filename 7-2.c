#include <stdlib.h>
#include <stdio.h>
#define MAXV 10
//从1开始存
void InsertionSort(int A[], int N){
    int temp,i,j;

    for(i=2; i<=N; i++){
        temp=A[i];
        for(j=i; j>1 && A[j-1]<temp; j--)
            A[j]=A[j-1];
        A[j]=temp;
    }
}

void MinHeap(int A[], int i, int N){//N M   
/* 此种调堆方法，只能用于，只有头一个是错序，其余都正确的情况。
    乱堆需要从N/2开始调 */
    int child,parent,temp;

    temp=A[i];
    for(parent=i; parent*2<=N; parent=child){
        child=parent*2;
        if(child+1<=N && A[child+1]<A[child])
            child++;
        if(temp>A[child]){
            A[parent]=A[child];
        }else{
            break;
        }
    }
    A[parent]=temp;
}

void HeapSort(int A[],int M){
    //堆排序
    int temp;
    for(int i=M; i>1; i--){//i的范围??
        temp=A[i];
        A[i]=A[1];
        A[1]=temp;
        MinHeap(A,1,i-1); 
    }
}

int main(){
    int N,M,i,temp;
    int A[MAXV+1];

    scanf("%d %d",&N,&M);
    if(N>MAXV){ //
        for(i=1; i<=M; i++){
            scanf("%d",&A[i]);
        }
        for(i=M/2; i>0; i--){
            MinHeap(A,i,M);
        }
        for(i=M+1; i<=N; i++){ //获得了最大M个元素的一个最小堆
            scanf("%d",&temp);
            if(temp>A[1]){
                A[1]=temp;
                MinHeap(A,1,M);
            }
        }
        //堆排序
        HeapSort(A,M);

    }else{ //如果比较短 直接插入排序
        for(i=1; i<=N; i++){
            scanf("%d",&A[i]);
            InsertionSort(A,N);
        }
    }

    if(N<M) M=N;
    printf("%d",A[1]);
    for(i=2; i<=M; i++){
        printf(" %d",A[i]);
    }
    printf("\n");

    return 0;
}
