#include<stdio.h>
#include<stdlib.h>
#define MAX 101
#define INFINITY 65535

typedef struct{
    int Data[MAX];
    int rear,front;
}Queue;

int G[MAX][MAX];
int earliest[MAX];
int latest[MAX];
int Indegree[MAX], Outdegree[MAX];

///Queue Function
void InitializeQ(Queue * Q){
    Q->front=Q->rear= -1;
} 

void AddQ(Queue * Q, int item){
    if(Q->front==-1){
        Q->front=Q->rear=0;
        Q->Data[Q->rear] = item;
    }else{
        Q->Data[++Q->rear] = item;
    }
}

int DeleteQ(Queue * Q){
    int FrontItem;
    if(Q->front==Q->rear){
        FrontItem=Q->Data[Q->front];
        Q->front=Q->rear= -1;
    }else{
        FrontItem=Q->Data[Q->front++];
    }
    return FrontItem;
}
//////////
void InitializeG(int n){
    int i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            G[i][j] = -1;
        earliest[i] = 0;
        latest[i] = INFINITY;
        Indegree[i]=Outdegree[i]=0;
    }
}

int FindEarliest(int n){
    int i,v,cnt;
    int ReData;
    Queue Q;
    InitializeQ(&Q);

    for(i=1; i<=n; i++){
        if(Indegree[i]==0)
            AddQ(&Q,i);
    }

    while(Q.front != -1){
        v=DeleteQ(&Q);
        cnt++;
        for(i=1; i<=n; i++){
            if(G[v][i]>=0){
                Indegree[i]--;
                if(Indegree[i]==0)
                    AddQ(&Q,i);
                if(earliest[i] < G[v][i]+earliest[v])
                    earliest[i] = G[v][i]+earliest[v];
            }
        }
    }

    if(cnt<n)
        ReData = -1;
    else{
        ReData = earliest[0];
        for(i=1; i<=n; i++){
            if(ReData<earliest[i])
                ReData=earliest[i];
        }
    }

    return ReData;
}

void FindLatest(int n,int earlTime){
    int i,v;
    Queue Q;
    InitializeQ(&Q);

    for(i=1; i<=n; i++){
        if(Outdegree[i]==0){
            AddQ(&Q,i);
            latest[i]=earlTime;
        }
    }
    
    while(Q.front != -1){
        v=DeleteQ(&Q);
        for(i=1; i<=n; i++){
            if(G[i][v] >= 0){
                Outdegree[i]--;
                if(Outdegree[i]==0)
                    AddQ(&Q,i);
                if(latest[i]>latest[v]-G[i][v])
                    latest[i]=latest[v]-G[i][v];
            }
        }
    }

}

int main(){
    int i,j,n,m;
    int v1,v2,t;
    scanf("%d %d",&n,&m);
    InitializeG(n);
    for(i=0; i<m; i++){
        scanf("%d %d %d",&v1,&v2,&t);
        Indegree[v2]++;
        Outdegree[v1]++;
        G[v1][v2]=t;
    }

    int earlTime=FindEarliest(n);
    //printf("%d",earlTime);
    if(earlTime == -1){
        printf("0\n");
    }else{
        printf("%d\n",earlTime);
        FindLatest(n,earlTime);
        
        for(int i=1;i<=n;i++){
            if(earliest[i]!=latest[i])
                continue;
            for(int j=n;j>=1;j--){
                if(G[i][j]>=0 && latest[j]==earliest[j]
                    && (latest[j]-earliest[i]==G[i][j]))
                    printf("%d->%d\n",i,j);
            }
        }
    }
    
   
   return 0;
}