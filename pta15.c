#include<stdio.h>
#include<stdlib.h>
#define MAX 15

typedef struct ENode{
    int data;
    struct ENode * Next;
}EdgeNode;

typedef struct VNode{
    char Visited;
    EdgeNode * FirstEdge;
}VertexNode;

typedef VertexNode AdjList[MAX];
typedef struct{
    int n,e;
    AdjList adjlist;
}ALGraph;

typedef struct{
    int Data[MAX];
    int Top;
}Stack;

void Initialize(ALGraph * G){
    int i;
    for(i=0;i<G->n;i++){
        G->adjlist[i].Visited=0;
        G->adjlist[i].FirstEdge=NULL;
    }
}

///stack function
void InitializeS(Stack * S){
    S->Top = -1;
}

void Push(Stack * S, int item){
    S->Data[++S->Top] = item;
}

int Top(Stack * S){
    return S->Data[S->Top];
}

void Pop(Stack * S){
    (S->Top)--;
}
///////

void DFS(ALGraph * G,int V){
    EdgeNode * edge;
    Stack S;
    int array[MAX];
    int i=0,j;
    
    InitializeS(&S);

    G->adjlist[V].Visited=1;
    array[++i]=V;
    Push(&S,V);
    while(S.Top!=-1){
        V=Top(&S);
        for(edge=G->adjlist[V].FirstEdge; edge; edge=edge->Next){
            if(!G->adjlist[edge->data].Visited){
                G->adjlist[edge->data].Visited=1;
                array[++i]=edge->data;
                Push(&S,edge->data);
                break;
            }
        }
        if(!edge)
            Pop(&S);
    }
    printf("{ ");
    for(j=1;i>=j;j++)
        printf("%d ",array[j]);
    printf("}\n");
}

///Queue function
typedef struct{
    int data[MAX];
    int front,rear;
}Queue;

void InitializeQ(Queue * Q){
    Q->front=Q->rear=-1;
}

void AddQ(Queue * Q, int item){
    if(Q->rear==-1){
        Q->front=Q->rear=0;
        Q->data[Q->rear]=item;
    }else
        Q->data[++Q->rear]=item;
}

int DeleteQ(Queue * Q){
    int tmp;
    if(Q->rear==Q->front){
        tmp=Q->front;
        Q->rear=Q->front=-1;
        return Q->data[tmp];
    }else
        return Q->data[Q->front++];
}
///

void BFS(ALGraph * G,int V){
    EdgeNode * edge;
    Queue Q;
    int array[MAX];
    int i=0,j;

    InitializeQ(&Q);

    G->adjlist[V].Visited=1;
    array[++i]=V;
    AddQ(&Q,V);
    while(Q.rear!=-1){
        V=DeleteQ(&Q);
        for(edge=G->adjlist[V].FirstEdge; edge; edge=edge->Next){
            if(!G->adjlist[edge->data].Visited){
                G->adjlist[edge->data].Visited=1;
                array[++i]=edge->data;
                AddQ(&Q,edge->data);
            }
        }
    }
    printf("{ ");
    for(j=1;j<=i;j++){
        printf("%d ",array[j]);
    }
    printf("}\n");

}

int main(){
    int i,v1,v2;
    EdgeNode * edge;
    EdgeNode * frontEdge;
    EdgeNode * rearEdge;
    ALGraph *G = malloc(sizeof(ALGraph));

    scanf("%d %d",&G->n,&G->e);
    Initialize(G);

    for(i=0;i<G->e;i++){
        scanf("%d %d",&v1,&v2);

        edge = malloc(sizeof(EdgeNode));
        edge->data = v2;
        if(G->adjlist[v1].FirstEdge==NULL ||
            G->adjlist[v1].FirstEdge->data>v2){
            edge->Next=G->adjlist[v1].FirstEdge;
            G->adjlist[v1].FirstEdge = edge;
        }else{
            frontEdge=G->adjlist[v1].FirstEdge;rearEdge=frontEdge->Next;
            while(rearEdge && rearEdge->data < v2){
                frontEdge=rearEdge;
                rearEdge=rearEdge->Next;
            }
            frontEdge->Next=edge;
            edge->Next=rearEdge;
        }
        

        edge = malloc(sizeof(EdgeNode));
        edge->data = v1;
        if(G->adjlist[v2].FirstEdge==NULL ||
            G->adjlist[v2].FirstEdge->data>v1){
            edge->Next=G->adjlist[v2].FirstEdge;
            G->adjlist[v2].FirstEdge = edge;
        }else{
            frontEdge=G->adjlist[v2].FirstEdge;rearEdge=frontEdge->Next;
            while(rearEdge && rearEdge->data<v2){
                frontEdge=rearEdge;
                rearEdge=rearEdge->Next;
            }
            frontEdge->Next=edge;
            edge->Next=rearEdge;
        }
        
    }

    for(i=0;i<G->n;i++)
        if(!G->adjlist[i].Visited)
            DFS(G,i);

    for(i=0;i<G->n;i++)
        G->adjlist[i].Visited=0;

    for(i=0;i<G->n;i++)
        if(!G->adjlist[i].Visited)
            BFS(G,i);

    return 0;
}