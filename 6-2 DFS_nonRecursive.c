#include<stdlib.h>
#include<stdio.h>
#define ERROR -1
#define MaxVertex 1001

typedef struct ENode{
    int adjV;
    struct Vnode * Next;
}EdgeNode;

typedef struct VNode{
    char Visited;
    EdgeNode * FirstEdge; 
}VertexNode;

typedef VertexNode AdjList[MaxVertex];
typedef struct{
    AdjList adjlist;
    int n,e;
}Graph;

typedef struct{
    int Data[MaxVertex];
    int Top;
}Stack;

//Stack Function
void InitializeS(Stack * PtrS){
    PtrS->Top=-1;
}

int IsEmpty(Stack * PtrS){
    return PtrS->Top==-1; //??
}

void Push(Stack * PtrS, int item){
    if(PtrS->Top == MaxVertex-1){
        printf("Full Stack");
        return;
    }
    PtrS->Data[++(PtrS->Top)]=item;
    return;
}

int Pop(Stack * PtrS){
    if(PtrS->Top == -1){
        printf("Empty Stack");
        return ERROR;
    }else
        return PtrS->Data[(PtrS->Top)--];
}

int Top(Stack * PtrS){
    return PtrS->Data[PtrS->Top];
}

//Graph Function
int CreateGraph(Graph * G){
    int start,i,v1,v2;    
    EdgeNode *edge,*p,*q;

    scanf("%d %d %d",&G->n,&G->e,&start);
    //Intialize the AdjList
    for(i=1; i<=G->n; i++){
        G->adjlist[i].Visited=0;
        G->adjlist[i].FirstEdge=NULL;
    }

    for(i=1; i<=G->e; i++){
        scanf("%d %d",&v1,&v2);

        edge = (EdgeNode * )malloc(sizeof(EdgeNode));
        edge->adjV = v2;
        if(G->adjlist[v1].FirstEdge==NULL
            || v2 <= G->adjlist[v1].FirstEdge->adjV){
            edge->Next = G->adjlist[v1].FirstEdge;
            G->adjlist[v1].FirstEdge = edge;
        }else{
            p=G->adjlist[v1].FirstEdge; q=p->Next;
            while(q && q->adjV < v2){
                p=q; q=q->Next;
            }
            p->Next=edge;
            edge->Next=q;
        }

        edge = (EdgeNode * )malloc(sizeof(EdgeNode));
        edge->adjV = v1;
        if(G->adjlist[v2].FirstEdge==NULL
            || v1 <= G->adjlist[v2].FirstEdge->adjV){
            edge->Next = G->adjlist[v2].FirstEdge;
            G->adjlist[v2].FirstEdge = edge;
        }else{
            p=G->adjlist[v2].FirstEdge; q=p->Next;
            while(q && q->adjV < v1){
                p=q; q=q->Next;
            }
            p->Next=edge;
            edge->Next=q;
        }
    }

    return start;
}

void DFS(Graph * G, int start){
    int V;
    Stack S;
    EdgeNode *edge;

    InitializeS(&S);

    G->adjlist[start].Visited=1;
    printf("%d",start);
    Push(&S,start);

    while(!IsEmpty(&S)){
        V=Top(&S);
        for(edge=G->adjlist[V].FirstEdge; edge; edge=edge->Next){
            if(!G->adjlist[edge->adjV].Visited){
                G->adjlist[edge->adjV].Visited=1;
                printf(" %d",edge->adjV);
                Push(&S,edge->adjV);
                break;
            }
        }

        if(!edge){
            V=Pop(&S);
            if(!IsEmpty(&S))
                printf(" %d",Top(&S));
        }
    }
}

int main(){
    int i,s;
    Graph * G = malloc(sizeof(Graph));

    s=CreateGraph(G);
    DFS(G,s);

    for(int i=1; i<=G->n; i++){
        if(!G->adjlist[i].Visited) break;
    }
    if(i<=G->n)
        printf("0\n");
    else printf("\n");

    return 0;
}