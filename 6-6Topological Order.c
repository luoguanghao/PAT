#include<stdlib.h>
#include<stdio.h>
#define MAXN 101

typedef struct ENode{
    int adjV;
    struct ENode * Next;
}EdgeNode;

typedef struct VNode{
    int Indegree;
    EdgeNode * FirstEdge;
}VertexNode;

typedef VertexNode AdjList[MAXN];
typedef struct{
    AdjList adjlist;
    int n;
}ALGraph;

typedef struct QNode{
    int Data;
    struct QNode * Next;
}QueueNode;

typedef struct{
    QueueNode * rear;
    QueueNode * front;
}LinkQueue;

void InitializeQ(LinkQueue * PtrQ){
    PtrQ->rear = PtrQ->front = NULL;
}

int IsEmpty(LinkQueue * PtrQ){
    return PtrQ->front == NULL;
}

void AddQ(LinkQueue * PtrQ, int item){
    QueueNode * cell = (QueueNode*)malloc(sizeof(QueueNode));
    cell->Data = item;
    cell->Next = NULL;
    if(IsEmpty(PtrQ))
        PtrQ->rear = PtrQ->front = cell;
    else
        PtrQ->rear->Next = cell;
        PtrQ->rear = cell;
}

int DeleteQ(LinkQueue * PtrQ){
    QueueNode * frontcell;
    int frontelem;

    if(IsEmpty(PtrQ))
        exit(0);

    frontcell = PtrQ->front;
    if(PtrQ->rear == PtrQ->front)
        PtrQ->rear = PtrQ->front = NULL;
    else
        PtrQ->front = PtrQ->front->Next;

    frontelem = frontcell->Data;
    free(frontcell);

    return frontelem;
}

void CreateGraph(ALGraph * G){
    int i,j,e,v;
    EdgeNode * edge;
    
    scanf("%d",&G->n);

    for(i=1; i<=G->n; i++){ //Initialize the Vertex List
        G->adjlist[i].Indegree = 0;
        G->adjlist[i].FirstEdge = NULL;
    }

    for(i=1; i<=G->n; i++){ //i是起点
        scanf("%d",&e);
        for(j=1; j<=e; j++){ // 注意这是单向图
            scanf("%d",&v);

            edge = (EdgeNode*)malloc(sizeof(EdgeNode));
            edge->adjV = i;
            edge->Next = G->adjlist[v].FirstEdge;
            G->adjlist[v].FirstEdge = edge;       
        }
        G->adjlist[i].Indegree = e;
    }
}

void TopSort(ALGraph * G){
    int i,V;
    LinkQueue Q;
    EdgeNode * edge;
    int cnt = 0;

    InitializeQ(&Q);

    for(i=1; i<=G->n; i++)
        if(G->adjlist[i].Indegree == 0)
            AddQ(&Q,i);
    printf("%d\n",cnt);
    while(!IsEmpty(&Q)){
        V = DeleteQ(&Q);
        cnt++;
        printf("%d\n",cnt);
        for(edge=G->adjlist[V].FirstEdge; edge; edge=edge->Next){
            if(--G->adjlist[edge->adjV].Indegree == 0)
                AddQ(&Q,edge->adjV);
        }
    }
    if(cnt != G->n)
        printf("Cyclic Graph\n");
    else
        printf("ACyclic Graph\n");

}

int main(){
    ALGraph * G = malloc(sizeof(ALGraph));

    CreateGraph(G);
    TopSort(G);

    return 0;
}
