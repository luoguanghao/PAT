#include<stdio.h>
#include<stdlib.h>
#define MAX 105

typedef struct ENode{
    int Adjv;
    int weight;
    struct ENode * Next;
}EdgeNode;

typedef struct VNode{
    int Indegree;
    int Earliest;
    EdgeNode * FirstEdge;
}VertexNode;

typedef VertexNode AdjList[MAX];
typedef struct{
    AdjList adjlist;
    int N,M;
}ALGraph;

typedef struct{
    int Data[MAX];
    int rear,front;
}QueueType;

///Queue Function
void InitializeQ(QueueType * Q){
    Q->rear=Q->front=-1;
}

void AddQ(QueueType * Q, int item){
    if(Q->rear==-1){
        Q->rear=Q->front=0;
        Q->Data[0]=item;
    }else{
        Q->Data[++Q->rear]=item;
    }
}

int DeleteQ(QueueType * Q){
    int frontitem;
    if(Q->front==Q->rear){
        frontitem=Q->Data[Q->front];
        Q->front=Q->rear=-1;
    }else{
        frontitem=Q->Data[Q->front];
        Q->front++;
    }

    return frontitem;
}
///////
//Graph Function
void InitializeG(ALGraph * G){
    int i;
    for(i=0; i<G->N; i++){
        G->adjlist[i].FirstEdge=NULL;
        G->adjlist[i].Indegree=0;
        G->adjlist[i].Earliest=0;
    }
}

void InsertG(ALGraph * G, int v1, int v2, int weight){
    EdgeNode * edge = malloc(sizeof(EdgeNode));
    edge->Adjv = v2;
    edge->weight = weight;
    edge->Next = G->adjlist[v1].FirstEdge;
    G->adjlist[v1].FirstEdge = edge;
}

void PrintG(ALGraph * G){
    for(int i=0; i<G->N; i++){
        printf("%d *",i);
        for(EdgeNode *edge = G->adjlist[i].FirstEdge;
            edge; edge=edge->Next)
            printf(" v2=%d w=%2d",edge->Adjv,edge->weight);
        printf("\n");
    }
}
//////////
///Central Algorithms
int TopSort(ALGraph * G){
    int cnt,v,i;
    EdgeNode * edge;
    QueueType Q;

    InitializeQ(&Q);

    //Indegree
    for(i=0; i<G->N; i++){
        for(edge=G->adjlist[i].FirstEdge;edge;edge=edge->Next){
            (G->adjlist[edge->Adjv].Indegree)++;
        }
    }

    //Find the 0 Indegree & AddQ
    for(i=0; i<G->N; i++){
        if(G->adjlist[i].Indegree==0){
            AddQ(&Q,i); 
        }
    }

    //torpo
    cnt=0;
    while(Q.rear != -1){
        v=DeleteQ(&Q);
        //printf("v=%d\n",v); //
        cnt++;
        for(edge=G->adjlist[v].FirstEdge;edge;edge=edge->Next){
            --(G->adjlist[edge->Adjv].Indegree);
            if(G->adjlist[edge->Adjv].Indegree==0){
                AddQ(&Q,edge->Adjv);
                G->adjlist[edge->Adjv].Earliest=G->adjlist[v].Earliest+edge->weight;
            }
        }
    }
    //printf("cnt = %d\n",cnt);
    return (cnt==G->N);
}


int main(){
    int i,v1,v2,weight;
    ALGraph * G = malloc(sizeof(ALGraph));

    scanf("%d %d",&G->N,&G->M);
    InitializeG(G);
    for(i=0; i<G->M; i++){
        scanf("%d %d %d",&v1,&v2,&weight);
        InsertG(G,v1,v2,weight);
    }
    //PrintG(G);
    int re=TopSort(G);
    if(re==0)
        printf("Impossible\n");
    else{
        int time=G->adjlist[i].Earliest;
        for(i=1;i<G->N;i++){
            if(G->adjlist[i].Earliest>time)
                time=G->adjlist[i].Earliest;
        }
        printf("%d",time);
    }

    return 0;
}