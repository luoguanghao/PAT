//Floyd算法

#include<stdlib.h>
#include<stdio.h>

#define MAXN 101
#define Inf 65535

typedef struct{
    int EdgeN,VertexN;
    int G[MAXN][MAXN];
}Graph;

void InitializeG(Graph *G){
    int i,j;
    for(i=1; i<=G->VertexN; i++){
        for(j=1; j<=G->VertexN; j++){
            if(i==j) G->G[i][j]=0;
            else     G->G[i][j]=Inf;
        }
    }
}

void CreateGraph(Graph *G){
    int i,v1,v2,w;
    for(i=1; i<=G->EdgeN; i++){
        scanf("%d %d %d",&v1,&v2,&w);
        G->G[v1][v2]=G->G[v2][v1]=w;
    }
}

void Floyd(Graph *G, int D[][MAXN]){
    int k,i,j;

    for(i=1; i<=G->VertexN; i++){
        for(j=1; j<=G->VertexN; j++){
            D[i][j]=G->G[i][j];
        }
    }

  

    for(k=1; k<=G->VertexN; k++){
        for(i=1; i<=G->VertexN; i++){
            for(j=1; j<=G->VertexN; j++){
                if(D[i][j] > D[i][k] + D[k][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
}

void FindAnimal(Graph *G){
    int i,j,mini;
    int MinX, MaxY;
    int D[MAXN][MAXN];

    Floyd(G,D);

    MinX=Inf;
    for(i=1; i<G->VertexN; i++){
        MaxY=0;
        for(j=1; j<G->VertexN; j++){
            if(D[j][i] > MaxY)
                MaxY=D[j][i];
        }
        if(MaxY==Inf){
            printf("0\n");
            return;
        }
        if(MaxY < MinX){
            MinX=MaxY;
            mini=i;
        }
    }

    printf("%d %d\n",mini,MinX);
}

int main(){
    Graph *G = malloc(sizeof(Graph));

    scanf("%d %d",&G->VertexN,&G->EdgeN);
    InitializeG(G);
    CreateGraph(G);
    
    FindAnimal(G);

    return 0;
}