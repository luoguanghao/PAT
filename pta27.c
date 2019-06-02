#include<stdio.h>
#define MaxProblem 5
#define MaxUsers 10001

typedef struct{
    int rank;
    int total;
    int S[MaxProblem];
    int Solved;
}UserType;


void Initialize(UserType Users[],int N,int K){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            Users[i].S[j] = -1;
        }
    }
}

void Swap(int A[],int a,int b){

}

void QuickSort(UserType Users[],int SortLink[],int p,int r){
    int temp,tmpN,i,j;
    
    if(p-r>4){
        temp=Users[SortLink[p]].total;
        i=p+1; j=r;
        while(i<j){
            for(;Users[SortLink[i]].total<temp;i++);
            for(;Users[SortLink[j]].total>temp;j--);
            Swap(SortLink,i,j);
        }
        Swap(SortLink,p,j);
        QuickSort(Users,SortLink,p,j-1);
        QuickSort(Users,SortLink,j+1,r);
    }else{
        for(i=1;i<=r-p;i++){
            temp=Users[SortLink[p+i]].total;
            tmpN=SortLink[p+i];
            for(j=p+i-1;j>=p && Users[SortLink[j]].total>temp;j--)
                SortLink[j+1]=SortLink[j];
            SortLink[j+1]=tmpN;
        }
    }
}

int main(){
    int N,K,M;
    int i,j,q,p;
    int UserNo,QuestNo,score;
    int FullMark[MaxProblem];
    int SortLink[MaxUsers];
    UserType Users[MaxUsers];

    scanf("%d %d %d",&N,&K,&M);
    
    Initialize(Users,N,K);

    for(i=1;i<=K;i++)
        scanf("%d",&FullMark[i]);

    for(i=0;i<M;i++){
        scanf("%d %d %d",&UserNo,&QuestNo,&score);
        if(Users[UserNo].S[QuestNo] < score)
            Users[UserNo].S[QuestNo] = score;

    }


    for(i=1;i<=N;i++){
        for(j=1;j<=K;j++)
            if(Users[i].S[j]>0)
                Users[i].total += Users[i].S[j];
    }


///QuickSort
    for(i=1;i<=N;i++)
        SortLink[i]=i;
    QuickSort(Users,SortLink,1,N);

///set the rank
    p=q=1;
    Users[SortLink[N]].rank=1;
    for(i=N-1;i>=1;i--){
        if(Users[SortLink[i]].total==Users[SortLink[i+1]].total){
            Users[SortLink[i]].rank=q;
            p++;
        }else{
            q=++p;
            Users[SortLink[i]].rank=q;

        }
    }
///
        
    
    for(i=N;i>=1 && Users[SortLink[i]].total;i--){
        printf("%d %05d %d",Users[SortLink[i]].rank,SortLink[i],Users[SortLink[i]].total);
        for(j=1;j<=K;j++){
            if(Users[SortLink[i]].S[j] != -1)
                printf(" %d",Users[SortLink[i]].S[j]);
            else printf(" -");
        }
        printf("\n");
        q++;
    }

    return 0;
}