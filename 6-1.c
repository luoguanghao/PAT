#include<stdlib.h>
#include<stdio.h>

#define MAXV 1001

typedef struct{
    int Visited[MAXV];
    int Edge[MAXV][MAXV];
    int n,e;
}Graph;

void Initialize(Graph *G){
    int i,j;
    for(i=1;i<=MAXV;i++){
        for(j=1;j<=MAXV;j++){
            G->Edge[i][j]=0;
        }
        G->Visited[i]=0;
    }
    G->n=G->e=0;
}

void Read(Graph *G){
    int i,v1,v2;

    scanf("%d %d",&G->n,&G->e);
    for(i=1;i<=G->e;i++){
        scanf("%d %d",&v1,&v2);
        G->Edge[v1][v2]=G->Edge[v2][v1]=1;
    }
}

//maybe wrong
void DFS(Graph *G, int V){ //recursive
    int i;
    G->Visited[V]=1;
    for(i=1;i<=G->n;i++){
        if(G->Edge[V][i] && !G->Visited[i])
            DFS(G,i);
    }
}

int Check(Graph *G){
    int i,j,count;

    for(i=1;i<=G->n;i++){
        count=0;
        for(j=1;j<=G->n;j++){
            if(G->Edge[i][j]) count++;
        }
        if(count%2) return 0;
    }
    return 1;
}

int main(){

    int i;
    Graph * G = (Graph*)malloc(sizeof(Graph));
    Initialize(G);
    Read(G);
    DFS(G,1);
    if(!Check(G)){ 
        printf("0\n");
    }
    else{
        for(i=1;i<=G->n;i++){
            if(!G->Visited[i]) break;
        }
        if(i<=G->n) printf("0\n");
        else printf("1\n");
    }
    return 0;
}


/* test data
6 10
1 2
2 3
3 1
4 5
5 6
6 4
1 4
1 6
3 4
3 6
*/