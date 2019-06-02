#include<stdlib.h>
#include<stdio.h>
#define MAXV 500
#define Inf 99999999

typedef struct{
    int Cost[MAXV][MAXV];
    int Dist[MAXV][MAXV];
    int MinDist[MAXV];
    int MinCost[MAXV];
    int Visited[MAXV];
    int EdgeN,VertexN;
}Graph;

void InitializeG(Graph *G){
    int i,j;
    for(i=0;i<MAXV;i++){
        for(j=0;j<MAXV;j++){
            G->Dist[i][j]=G->Cost[i][j]=Inf;
        }
        G->MinCost[i]=G->MinDist[i]=Inf;
        G->Visited[i]=0;
    }
    G->EdgeN=G->VertexN=0;
}

void ReadG(Graph *G, int *S, int *D){
    int i,v1,v2;
    scanf("%d %d %d %d",&G->VertexN,&G->EdgeN,S,D);
    for(i=0; i<G->EdgeN; i++){
        scanf("%d %d",&v1,&v2);
        scanf("%d %d",&G->Dist[v1][v2],&G->Cost[v1][v2]);
        G->Dist[v2][v1]=G->Dist[v1][v2];
        G->Cost[v2][v1]=G->Cost[v1][v2];
    }
}

void Dijkstra(Graph *G,int S){
    int i,j,minD,minv;

    G->Visited[S]=1;
    G->MinCost[S]=G->MinDist[S]=0;
    for(i=0;i<G->VertexN;i++){
        G->MinDist[i]=G->Dist[S][i];
        G->MinCost[i]=G->Cost[S][i];
    }

    for(i=1;i<G->VertexN;i++){
        minD=Inf;

        for(j=0; j<G->VertexN; j++){ //find the min edge
            if(!G->Visited[j] && (G->MinDist[j] <= minD)){
                minD=G->MinDist[j];
                minv=j;
            }
        }

        if(minD==Inf) break;
        else{
            G->Visited[minv]=1;
            for(j=0;j<G->VertexN;j++){
            if(!G->Visited[j]){
                if(G->MinDist[j] > G->MinDist[minv]+G->Dist[minv][j]){
                    G->MinDist[j] = G->MinDist[minv]+G->Dist[minv][j];
                    G->MinCost[j] = G->MinCost[minv]+G->Cost[minv][j];
                }else if(
                    G->MinDist[j] == G->MinDist[minv]+G->Dist[minv][j] &&
                    G->MinCost[j] > G->MinCost[minv]+G->Cost[minv][j]
                ){
                    G->MinCost[j] = G->MinCost[minv]+G->Cost[minv][j];
                }
            }
            }
        }
    }
}

int main(){
    int S,D;
    Graph * G;
    G=(Graph *)malloc(sizeof(Graph));
    InitializeG(G);
    ReadG(G,&S,&D);
    Dijkstra(G,S);
    printf("%d %d\n",G->MinDist[D],G->MinCost[D]);

    return 0;
}