#include<stdlib.h>
#include<stdio.h>
#define MAXUSERS 10002
#define MAXPROBM 6

typedef struct{
    int index;
    int total;
    int S[MAXPROBM];
    int rank;
    int Prefect;
}UserType;

UserType Users[MAXUSERS];
int FullMark[MAXPROBM];
int SortLink[MAXUSERS];

void Initialize(int N,int K){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            Users[i].S[j]=-1;
        }
        Users[i].total=0;
        Users[i].rank=0;
        Users[i].Prefect=0;
        Users[i].index=i;
        SortLink[i]=i;
    }
}

void Swap(int i,int j){
    int tmp=SortLink[j];
    SortLink[j]=SortLink[i];
    SortLink[i]=tmp;
}

int Mid(int p,int r){
    int mid=(p+r)/2;
    if(Users[SortLink[p]].total<Users[SortLink[mid]].total)
        Swap(p,mid);
    if(Users[SortLink[p]].total<Users[SortLink[r]].total)
        Swap(p,r);
    if(Users[SortLink[mid]].total<Users[SortLink[r]].total)
        Swap(mid,r);
    Swap(mid,r-1);

    return SortLink[r-1];
}

void QuickSort(int p,int r){
    int tmp,i,j;
    if(r-p>4){
        tmp=Mid(p,r);
        for(;;){
            for(i=p+1;Users[SortLink[i]].total>Users[tmp].total;i++);
            for(j=r-2;Users[SortLink[j]].total<Users[tmp].total;j--);
            if(j<i) break;
            Swap(i,j);
        }
        Swap(i,r-1);
        QuickSort(p,i-1);
        QuickSort(i+1,r);

    }else{
        for(i=1;p+i<=r;i++){
            tmp=SortLink[p+i];
            for(j=p+i-1;j>=p;j--){
                if(Users[tmp].total>Users[SortLink[j]].total)
                    SortLink[j+1]=SortLink[j];
                /*else if(Users[tmp].total==Users[SortLink[j]].total &&
                    Users[tmp].Prefect>Users[SortLink[j]].Prefect)
                    SortLink[j+1]=SortLink[j];
                else if(Users[tmp].total==Users[SortLink[j]].total &&
                    Users[tmp].Prefect==Users[SortLink[j]].Prefect &&
                    Users[tmp].index<Users[SortLink[j]].index)
                    SortLink[j+1]=SortLink[j];*/
                else break;
            }
            SortLink[j+1]=tmp;
        }
    }
    
}

int main(){
    int N,K,M,i,j;
    int index,prob,score;

    scanf("%d %d %d",&N,&K,&M);
    Initialize(N,K);
    for(i=1;i<=K;i++)
        scanf("%d",&FullMark[i]);
    for(i=1;i<=M;i++){
        scanf("%d %d %d",&index,&prob,&score);
        if(score==-1) score=0;
        if(Users[index].S[prob]<score)
            Users[index].S[prob] = score;
    }

    for(i=1;i<=N;i++){
        for(j=1;j<=K;j++){
            if(Users[i].S[j]>0)
                Users[i].total += Users[i].S[j];
            if(Users[i].S[j]==FullMark[j])
                Users[i].Prefect++;
        }
    }

    for(i=1;i<=N;i++){
        printf("    %d %d\n",Users[i].index,Users[i].total);
    }

    QuickSort(1,N);

    for(i=1;i<=N;i++){
        printf("%d %d\n",SortLink[i],Users[SortLink[i]].total);
    }

    return 0;
}