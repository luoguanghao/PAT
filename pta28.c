#include<stdio.h>
#include<stdlib.h>

#define MAXUSER 10001
#define MAXPROBM 6

typedef struct{
    int No;
    int total;
    int S[MAXPROBM];
    int rank;
    int Prefectly;
}UserType;

UserType Users[MAXUSER];
int SortLink[MAXUSER];
int FullMark[MAXPROBM];

void Initialize(int N,int K){
    int i,j;
    for(i=1;i<=N;i++){
        for(j=1;j<=K;j++)
            Users[i].S[j] = -2;
        Users[i].No = i;
        Users[i].Prefectly = 0;
        Users[i].rank=0;
        Users[i].total=0;
        SortLink[i]=i;
    }
}

void QuickSort(int p,int r){
    int i,j;
    UserType tmp;
    /*if(r=p>4){

    }else{*/
        for(i=1;p+i<=r;i++){
            tmp=Users[SortLink[p+i]];
            for(j=p+i-1; j>=p; j--){
                if(Users[SortLink[j]].total<tmp.total)
                    SortLink[j+1]=SortLink[j];
                else if(Users[SortLink[j]].total==tmp.total&&
                    Users[SortLink[j]].Prefectly<tmp.Prefectly)
                    SortLink[j+1]=SortLink[j];
                else if(Users[SortLink[j]].total==tmp.total&&
                    Users[SortLink[j]].Prefectly==tmp.Prefectly&&
                    Users[SortLink[j]].No>tmp.No)
                    SortLink[j+1]=SortLink[j];
                else break;
            }
            SortLink[j+1]=tmp.No;
        }
    //}

}

int main(){
    int N,K,M,i,j;
    int UserNo,QuestNo,Score;

    scanf("%d %d %d",&N,&K,&M);
    Initialize(N,K);
    for(i=1; i<=K;i++){
        scanf("%d",&FullMark[i]);
    }
    for(i=1;i<=M;i++){
        scanf("%d %d %d",&UserNo,&QuestNo,&Score);
        if(Users[UserNo].S[QuestNo]<Score)
            Users[UserNo].S[QuestNo]=Score;
        if(Users[UserNo].S[QuestNo]==-1)
            Users[UserNo].S[QuestNo]=0;
    }

    for(i=1;i<=N;i++){
        for(j=1;j<=K;j++){
            if(Users[i].S[j]>0)
                Users[i].total += Users[i].S[j];
        }
    }

    for(i=1;i<=N;i++){
        for(j=1;j<=K;j++){
            if(Users[i].S[j]==FullMark[j])
                Users[i].Prefectly++;
        }
    }

    ///QuickSort
    QuickSort(1,N);
    ////////////
    int rank=1;
    int tmptol=Users[SortLink[1]].total;
    Users[SortLink[1]].rank=1;
    for(i=2;i<=N;i++){
        if(Users[SortLink[i]].total==tmptol)
            Users[SortLink[i]].rank=rank;
        else{
            rank=i;
            Users[SortLink[i]].rank=rank;
            tmptol=Users[SortLink[i]].total;
        }
    }

    for(i=1; i<=N&&Users[SortLink[i]].total>0; i++){
        printf("%d %05d %d",Users[SortLink[i]].rank,
            Users[SortLink[i]].No,Users[SortLink[i]].total);

        for(j=1;j<=K;j++){
            if(Users[SortLink[i]].S[j]>=-1)
                printf(" %d",Users[SortLink[i]].S[j]);
            else
                printf(" -");
        }
        printf("\n");
    }

    return 0;
}