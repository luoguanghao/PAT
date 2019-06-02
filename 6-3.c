#include<stdlib.h>
#include<stdio.h>
#define MAXV 1001
#define SIX 6

typedef unsigned long int VertexType;
typedef struct ENode{
    VertexType adjV;
    struct ENode * Next;
}EdgeNode;

typedef struct VNode{
    char Visited;
    EdgeNode * FirstEdge;
}VertexNode;

typedef VertexNode AdjList[MAXV];
typedef struct{
    AdjList adjlist;
    unsigned long int n,e;
}ALGraph;

typedef struct QNode{
    VertexType Data;
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

void AddQ(LinkQueue * PtrQ, VertexType item){
    QueueNode * new =(QueueNode * )malloc(sizeof(QueueNode));

    new->Data = item;
    new->Next = NULL;
    if(IsEmpty(PtrQ))
        PtrQ->front = PtrQ->rear = new;
    else{
        PtrQ->rear->Next = new;
        PtrQ->rear = new;
    }
}

VertexType DeleteQ(LinkQueue * PtrQ){
    QueueNode * FrontCell;
    VertexType  FrontElem;

    if(IsEmpty(PtrQ)){
        printf("EMPTY QUEUE");
        exit(0);
    }   
    FrontCell = PtrQ->front;
    FrontElem = FrontCell->Data;
    if(PtrQ->front == PtrQ->rear)
        PtrQ->front = PtrQ->rear = NULL;
    else
        PtrQ->front = PtrQ->front->Next;
    
    free(FrontCell);

    return FrontElem;
}

void DestoryQ(LinkQueue * PtrQ){
    QueueNode * cell;
    while(cell == PtrQ->front){
        PtrQ->front = PtrQ->front->Next; 
        free(cell);
    }
}

void CreateGraph(ALGraph * G){
    unsigned long int i,v1,v2;
    EdgeNode * edge;

    scanf("%ld %ld",&G->n,&G->e);

    for(i=1; i<=G->n; i++){
        G->adjlist[i].Visited=0;
        G->adjlist[i].FirstEdge=NULL;
    }

    for(i=1; i<=G->e; i++){
        scanf("%ld %ld",&v1,&v2);

        edge = (EdgeNode * )malloc(sizeof(EdgeNode));
        edge->adjV = v2;
        edge->Next = G->adjlist[v1].FirstEdge;
        G->adjlist[v1].FirstEdge = edge;

        edge = (EdgeNode * )malloc(sizeof(EdgeNode));
        edge->adjV = v1;
        edge->Next = G->adjlist[v2].FirstEdge;
        G->adjlist[v2].FirstEdge = edge;

    }
}

void SixDegree_BFS(ALGraph * G,VertexType start){
    int i;
    int level=0,count=1;
    VertexType V,last,trail;
    LinkQueue Q;
    EdgeNode * edge;

    InitializeQ(&Q);

    G->adjlist[start].Visited=1;
    AddQ(&Q,start);
    last=start;
    while(!IsEmpty(&Q)){
        V=DeleteQ(&Q);
        for(edge = G->adjlist[V].FirstEdge; edge; edge = edge->Next){
            if(!G->adjlist[edge->adjV].Visited){
                G->adjlist[edge->adjV].Visited=1;
                AddQ(&Q,edge->adjV);
                trail = edge->adjV;
                count++;
            }
        }
        if(last == V){
            level++;
            last = trail;
        }
        if(level == SIX){
            break;
        }
    }
    printf("%ld: %.2f%%\n",start,100*(double)count/(double)G->n);
}

int main(){
    unsigned long int i,j;
    ALGraph * G = malloc(sizeof(ALGraph));
    CreateGraph(G);
    for(i=1; i<=G->n; i++){
        SixDegree_BFS(G,i);
        for(j=1; j<=G->n; j++)
            G->adjlist[j].Visited=0;
    }
    return 0;
}