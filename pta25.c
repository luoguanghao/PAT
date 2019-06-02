#include<stdio.h>
#include<stdlib.h>
#define MAX 110
//int i,j; // 全局变量

/*int MergeOrInsertion(int origin[], int current[], int N){
    
    for(i=0; origin[i]<origin[i+1]; i++); //i=4
    j = 1+i;
    for(; origin[j]==current[j] && j<N; j++); //j=N
    printf("%d %d\n",i,j);
    return j == N;
}*/
int IsSimilar(int A1[],int A2[],int N){
    for(int i=0;i<N;i++){
        if(A1[i]!=A2[i]) return 0;
    }
    return 1;
}

void Insertion(int current[], int N,int i){
    int p;
    int tmp;
    tmp=current[i+1];
    for(p=i; p>=0 && current[p]>tmp; p--)
        current[p+1]=current[p];
    current[p+1]=tmp;
}

void Merge(int A[],int temp[],int l,int r,int N){
    
    int p1=l,p2=r,p3=l;
    while(p1<=r-1 && p2<=l+N-1){
        if(A[p1]<A[p2])
            temp[p3++]=A[p1++];
        else
            temp[p3++]=A[p2++];
    }
    for(; p1<=r-1; p1++)
        temp[p3++]=A[p1];
    for(; p2<=l+N-1; p2++)
        temp[p3++]=A[p2];

    /*for(int i=0;i<10;i++)
        printf("%d ",temp[i]);
    printf("\n");*/
}

void Merge_Pass(int A[], int temp[], int N, int length){
    int q,t;
    for(q=0; q<=N-2*length; q+=2*length){
        Merge(A,temp,q,q+length,2*length);
    }
    if(q+length<N){
        Merge(A,temp,q,q+length,N-q);
    }else{
        for(t=q; t<N; t++)
            temp[t]=A[t];
    }

}

void MergeSort(int A[],int temp[],int current[],int N){
    int length=1; //length 有序序列长度
    int flag=0;
    while(length<N){
        flag=IsSimilar(A,current,N);
        //printf("*%d\n",flag);
        Merge_Pass(A,temp,N,length);
        if(flag){
            for(int i=0;i<N;i++)
                A[i]=temp[i];
            break;
        }
        length *= 2;

        flag=IsSimilar(temp,current,N);
        //printf("*%d\n",flag);
        Merge_Pass(temp,A,N,length);
        if(flag) break;
        length *= 2;
    }
    
}

int main(){
    int N,p,flag;
    int origin[MAX],current[MAX],temp[MAX];
    int i,j;
    scanf("%d",&N);
    
    for(p=0;p<N;p++){
        scanf("%d",&origin[p]);
    }
    for(p=0;p<N;p++){
        scanf("%d",&current[p]);
    }
    for(i=0;i<N;i++)
        temp[i]=0;
    ///
    for(i=0; current[i]<current[i+1]; i++); //i=4
    
    j=i+1;  /////??????
    //printf("%d %d\n",i,j);
    //printf("%d %d\n",origin[j],current[j]);
    for(; origin[j]==current[j] && j<N; j++); //j=N
    //printf("%d %d\n",i,j);
    flag = (j == N);
    ///
    if(flag){ //insertion
        Insertion(current,N,i);
        printf("Insertion Sort\n");
        printf("%d",current[0]);
        for(p=1;p<N;p++){
            printf(" %d",current[p]);
        }

    }else{ //merge
        MergeSort(origin,temp,current,N);
        printf("Merge Sort\n");
        printf("%d",origin[0]);
        for(p=1;p<N;p++){
            printf(" %d",origin[p]);
        }
    }

    return 0;
}