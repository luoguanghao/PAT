#include<stdio.h>
#include<stdlib.h>
#define inf 999999
#define MAXN
///////
int teamNum[MAXN];
int MinDist[MAXN];
int mapDist[MAXN][MAXN];
int Visited[MAXN];
int N,M,C1,C2;
//////

void Dijkstra(){
    int i,j;

    for(i=0;i<N;i++){
        Visited[i]=0;
    }

    int num[MAXN],team[MAXN];
    num[C1]=1; team[C1]=teamNum[C1];
    MinDist[C1]=0;

    for(i=0;i<N;i++){
        int minD=inf, minV;
        for(i=0;i<N;i++){
            if(minD>MinDist[i])
                minD=MinDist[i]; minV=i;
        }
        if(minD==inf) break;
        Visited[minV]=1;

        for(i=0;i<N;i++){
            if(MinDist[i]>minD+mapDist[minV][i] &&!Visited[i]){
                MinDist[i]=minD+mapDist[minV][i];
                num[i]=num[minv];
                team[i]=team[minV]+teamNum[i];
            }else if(MinDist[i]=minD+mapDist[minV][i] &&!Visited[i]){
                num[i]+=num[minV];
                if(team[i]<team[minV]+teamNum[i])
                    team[i]=team[minV]+teamNum[i];                  
            }  
        }
         
    }
    printf("%d %d",num[C2],team[C2]);

}

int main(){
    int i,j;

    scanf("%d %d %d %d",&N,&M,&C1,&C2);
    for(i=0;i<N;i++){
        for(j=0;j<=N;j++){
            mapDist[i][j]=inf;
        }    
    }

    for(i=0;i<N;i++)
        scanf("%d",&teamNum[i]);

    int v1,v2,w;
    for(i=0;i<M;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        mapDist[v1][v2]=mapDist[v2][v1]=w;
    }

    Dijkstra();

    return 0;
}