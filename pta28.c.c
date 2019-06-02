#include<stdio.h>
#include<stdlib.h>

#define MAXUSER 10001
#define MAXPROBM 5

typedef struct{
    int No;
    int rank;
    int total;
    int Score[MAXPROBM];
    int Prefectly;
}UserType;

    UserType Users[MAXUSER];
    int SortLink[MAXUSER];

void InitializeU(UserType U[],int N){
    for(int i=1; i<=N; i++){
        for(int j=1;j<=MAXPROBM;j++){
            U[i].Score[j]=-1;
        }
        U[i].total=0;
        U[i].rank=0;
        U[i].No=i;
        U[i].Prefectly=0;
        SortLink[i]=i;
    }
}

void QuickSort(int N,int K,int p,int r){
    int i,j;
    UserType temp;
    /*if(r-p>4){

    }else{*/
        for(i=1;p+i<=r;i++){
            temp=Users[SortLink[p+i]];
            for(j=p+i-1;j>=p;j--){
                if(Users[SortLink[j]].total<temp.total)
                    SortLink[j+1]=SortLink[j];
            }
            SortLink[j+1]=SortLink[p+i];
        }
}

int main(){
    int N,K,M,i,j;
    int FullMark[MAXPROBM];
    

    scanf("%d %d %d",&N,&K,&M);
    InitializeU(Users,N);
    for(i=1; i<=K; i++)
        scanf("%d",&FullMark[i]);
    
    int no, questoin, score;
    for(i=0; i<M; i++){
        scanf("%d %d %d",&no,&questoin,&score);
        if(Users[no].Score[questoin]<score)
            Users[no].Score[questoin]=score;
    }

    for(i=1;i<=N;i++){
        for(j=1;j<=K;j++){
            if(Users[i].Score[j]>0)
                Users[i].total+=Users[i].Score[j];
            if(Users[i].Score[j]==FullMark[j])
                Users[i].Prefectly++;
        }
    }

//Quick Sort///

    QuickSort(N,K,1,N);


/////    
    for(i=1;i<=N;i++){
        printf("%05d %2d prefect=%d ",Users[i].No,Users[i].total,Users[i].Prefectly);
        for(j=1;j<=MAXPROBM;j++){
            printf("%2d ",Users[i].Score[j]);
        }
        printf("\n");
    }
////
/*
    for(i=1;i<=N;i++){
        printf("%05d %2d prefect=%d \n",Users[SortLink[i]].No,Users[SortLink[i]].total,Users[SortLink[i]].Prefectly);
    }*/
    for(i=1;i<=N;i++)
        printf("*%d ",SortLink[i]);



    return 0;
}