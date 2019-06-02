#include<stdio.h>
#define MAX 101

void Swap(int * A1,int * A2){ /////<<
    int temp = *A1;
    *A1 = *A2; *A2 = temp;
}

int JudgeHeapSort(int A[],int change[],int N){
    for(int i=1; i<=N; i++)
        if(A[i]!=change[i]) return 0;
    return 1;
}

void MaxHeap(int A[],int start,int size){  //边界条件
    int i,parent,child;
    int X = A[start];
    for(parent=start; parent*2<=size; parent=child){  ///此处parent*2<=size or parent*2<size
        child=parent*2;
        if(child+1<=size && A[child]<A[child+1])
            child++;
        if(A[child]>X)
            A[parent]=A[child];
        else
            break;
    }
    A[parent]=X;
}

void HeapSort(int A[],int change[],int N){
    int i,j;
    int flag=0;
    int size = N;

    for(i=N/2; i>=1; i--){
        MaxHeap(A,i,N);
    }
    for(i=N; i>1; i--){
    /*
        for(j=1;j<=N;j++)
            printf("%d ",A[j]);
        printf("\n");
    */
        if(JudgeHeapSort(A,change,N)){
            flag=1;
        }

        Swap(&A[1],&A[size--]);
        MaxHeap(A,1,size);
        if(flag) break;
    }
    printf("%d",A[1]);
    for(i=2;i<=N;i++)
        printf(" %d",A[i]);
}

void InsertionSort(int A[],int N,int i){
    int temp = A[i+1];
    for(; i>0 && A[i]>temp;i--)
        A[i+1]=A[i];
    A[i+1]=temp;
}

int main(){
    int N,i,j,flag,p;
    int origin[MAX],change[MAX];
    
    scanf("%d",&N);
    for(i=1; i<=N; i++)
        scanf("%d",&origin[i]);
    for(i=1; i<=N; i++)
        scanf("%d",&change[i]);

    for(i=1;i<=N && (change[i]<=change[i+1]);i++);
    j = i+1;
    for(; j<=N && (origin[j]==change[j]); j++);
    //printf("%d %d\n",i,j);
    flag = (j==N+1);
    if(flag){
        InsertionSort(change,N,i);
        printf("Insertion Sort\n");

        printf("%d",change[1]);
        for(p=2;p<=N;p++)
            printf(" %d",change[p]);
    }else{
        printf("Heap Sort\n");
        HeapSort(origin,change,N);
    }

    return 0;
}