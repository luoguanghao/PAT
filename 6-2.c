#include<stdlib.h>
#include<stdio.h>

#define ERROR -1
#define MAX 1000

typedef struct ENode{
    int AdjV;
    struct VNode *Next;
}EdgeNode;

typedef struct VNode{
    char Visited;
    EdgeNode *FirstEdge;
}VertexNode;

typedef struct{
    VertexNode adjlist[MAX];
    int n,e;
}ALGraph;

typedef struct{
    int Data[MAX];
    int Top;
}Stack;

void Initialize(Stack *PtrS){
    PtrS->Top=-1;
}

int IsEmpty(Stack *PtrS){
    return PtrS->Top<0;
}

void Push(Stack *PtrS, int item){
    if(PtrS->Top==MAX-1){
        printf("Full Stack");
        return;
    }
    else{
        PtrS->Data[++(PtrS->Top)]=item;
        return;
    }
}

int Pop(Stack *PtrS){
    if(PtrS->Top<0){
        printf("Empty Stack");
        return ERROR;
    }
    else
        return(PtrS->Data[(PtrS->Top)--]);
}

int Top(Stack *PtrS){
    if(PtrS->Top<0){
        printf("Empty Stack");
        return ERROR;
    }
    else
        return(PtrS->Data[(PtrS->Top)]);
}

int CreateGraph(ALGraph *G){
    int n,e,s,v1,v2;
    int i;
    EdgeNode *edge,*p,*q;

    scanf("%d %d %d",&G->n,&G->e,&s);
    //Initialize the AdjList
    for(i=1;i<=G->n;i++){
        G->adjlist[i].Visited=0;
        G->adjlist[i].FirstEdge=NULL;
    }

    for(i=1;i<=G->e;i++){
        scanf("%d %d",&v1,&v2);

        //v1
        edge=(EdgeNode*)malloc(sizeof(EdgeNode));
        edge->AdjV=v2;
        edge->Next=NULL;
        if(G->adjlist[v1].FirstEdge==NULL)
            G->adjlist[v1].FirstEdge=edge;
        else{
            p=G->adjlist[v1].FirstEdge; q=p->Next;
            while(q && q->AdjV<v2){
                p=q; q=q->Next;
            }
            p->Next=edge; edge->Next=q;
        }

        //v2
        edge=(EdgeNode*)malloc(sizeof(EdgeNode));
        edge->AdjV=v1;
        edge->Next=NULL;
        if(G->adjlist[v2].FirstEdge==NULL)
            G->adjlist[v2].FirstEdge=edge;
        else{
            p=G->adjlist[v2].FirstEdge; q=p->Next;
            while(q && q->AdjV<v1){
                p=q; q=q->Next;
            }
            p->Next=edge; edge->Next=q;
        }
    }
    return s;
}

void DFS(ALGraph *G, int V){
    EdgeNode *edge;
    Stack s;
    Initialize(&s);
    G->adjlist[V].Visited=1;
    printf("%d",V);
    Push(&s,V);

    while(!IsEmpty(&s)){
        V=Top(&s);
        for(edge=G->adjlist[V].FirstEdge; edge; edge=edge->Next){
            if(!G->adjlist[edge->AdjV].Visited){
                G->adjlist[edge->AdjV].Visited=1;
                Push(&s,edge->AdjV);
                printf("%d",edge->AdjV);
                break;
            }
        }
        if(!edge){           
            V=Pop(&s);
            if(!IsEmpty(&s))
                printf("%d",Top(&s));
        }
    }
}

int main(){
    int i,s;
    char co;
    ALGraph *G=(ALGraph*)malloc(sizeof(ALGraph));

    s=CreateGraph(G);
    DFS(G,s);
    
    for(i=1;i<=G->n;i++)
        if(!G->adjlist[i].Visited)  break;
    if(i<=G->n)
        printf("0\n");
    else printf("*\n");

    for(i=1; i<=G->n; i++){
        co=G->adjlist[i].Visited;
        printf("%c",co);
    }

    return 0;

}

/*
test data
luoguanghaodeMacBook-Pro:bianyi luoguanghao$ ./a.out
6 8 1
1 2
2 3
3 4
4 5
5 6
6 4
3 6
1 5
12345654321*
luoguanghaodeMacBook-Pro:bianyi luoguanghao$ ./a.out
6 6 6
1 2
1 3
2 3
5 4
6 5
6 4
654560
luoguanghaodeMacBook-Pro:bianyi luoguanghao$ 
*/