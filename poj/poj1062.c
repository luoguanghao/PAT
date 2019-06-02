/*
https://blog.csdn.net/liuqiyao_01/article/details/8882783
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXN 105
#define inf 999999

typedef struct {
    int p,l,x;
    int t[MAXN],v[MAXN];
}GoodType;
GoodType Goods[MAXN];
int M,N,P,L,X,T,V;
int costmap[MAXN][MAXN];

int Dijkstra(int x){
    int cost[MAXN],visited[MAXN];
    int level=Goods[x].l;
    int i,j;
    for(i=0;i<=N;i++){  ///???0 的level??
        cost[i]=inf;
        visited[i]=0;
        if(Goods[i].l-level<=M && Goods[i].l>=level)
            cost[i]=costmap[0][i];
    }

    visited[0]=1;
    for(i=0;i<N;i++){
        int min=inf; int minv;
        for(j=1;j<=N;j++){
            if(!visited[j] && cost[j]<min){
                min=cost[j]; minv=j;
            }        
        }
        if(min==inf) break;
        visited[minv]=1;

        for(j=0;j<=N;j++){
            if(Goods[j].l-level<=M && Goods[j].l>=level
                &&cost[j]>cost[minv]+costmap[minv][j])
                cost[j]=cost[minv]+costmap[minv][j];
        }
    }
    return cost[1];
}

int main(){
    int i,j;

    scanf("%d %d",&M,&N);
    for(i=1;i<=N;i++){
        scanf("%d %d %d",&Goods[i].p,&Goods[i].l,&Goods[i].x);
        for(j=1;j<=Goods[i].x;j++){
            scanf("%d %d",&Goods[i].t[j],&Goods[i].v[j]);
        }
    }

    for(i=0;i<=N;i++){
        for(j=0;j<=N;j++)
            costmap[i][j]=inf;
    }

    int level=Goods[1].l;
    for(i=1;i<=N;i++){      
        for(j=1;j<=Goods[i].x;j++){
            if(abs(Goods[Goods[i].t[j]].l-Goods[i].l)<=M &&
                costmap[Goods[i].t[j]][i]>Goods[i].v[j]){
                costmap[Goods[i].t[j]][i]=Goods[i].v[j];
            }
        }
        if(Goods[i].l-level<=M)
            costmap[0][i]=Goods[i].p;
    }

    int min=inf;
    int tmp;
    for(i=1;i<=N;i++){
        tmp=Dijkstra(i);
        if(tmp<min) min=tmp;
    }
    printf("%d\n",min);

    return 0;

}