#include<stdlib.h>
#include<stdio.h>

#define MAX 1001

typedef struct ENode{
    int Adjv;
    struct ENode * Next;
}EdgeNode;

typedef struct VNode{
    int Element;
    int InDegree;
    EdgeNode * FirstEdge;
}VertexNode;

typedef VertexNode AdjList[MAX];
typedef struct{
     AdjList adjlist;
     int GSize;
}ALGraph;

typedef struct HashTbl{
    int Element[MAX];
    int TblSzie;
}HashTable;

void InitializeG(HashTable * H, ALGraph * G){
    G->GSize=H->TblSzie;
    int i;
    for(i=0;i<G->GSize;i++){
        G->adjlist[i].Element = H->Element[i];
        G->adjlist[i].InDegree = 0;
        G->adjlist[i].FirstEdge = NULL;
    }
}

void HashToGraph(HashTable * H,ALGraph * G){
    int i;
    int N = H->TblSzie;
    int Pos;
    EdgeNode * edge;

    InitializeG(H,G);
    for(i=0; i<N&&H->Element[i]!=-1; i++){   //?
        if(H->Element[i]%N==i)
            continue;
        else{
            Pos = H->Element[i] % N;
            while(Pos != i){
                edge = malloc(sizeof(EdgeNode));
                edge->Adjv = i;
                edge->Next = G->adjlist[Pos].FirstEdge;
                G->adjlist[Pos].FirstEdge = edge;
                ++(G->adjlist[i].InDegree);

                Pos++;
                if(Pos >= N) Pos -= N;
            }
        }
    }
/*
    for(i=0;i<G->GSize;i++){
        printf("%2d %2d*",G->adjlist[i].Element,G->adjlist[i].InDegree);
        for(edge=G->adjlist[i].FirstEdge;edge;edge=edge->Next)
            printf(" %d",G->adjlist[edge->Adjv].Element);
        printf("\n");
    }
*/
}


void TopSort(ALGraph * G){
    int i,j;
    int v, cnt=0;
    int ValidNum=0;
    for(i=0; i<G->GSize; i++){
        if(G->adjlist[i].Element!=-1)
            ValidNum++;
    }
    //printf("ValidNum= %d\n",ValidNum);
    int SortSeq[G->GSize];
    int beg,end;
    int tmp;
    for(i=0; i<G->GSize; i++)
        SortSeq[i]=-1;
    beg=end=0;

    for(i=0; i<G->GSize; i++){
        if(G->adjlist[i].Element != -1 && G->adjlist[i].InDegree==0){
            tmp=i;
            for(j=end; j>beg&&
            G->adjlist[SortSeq[j-1]].Element>G->adjlist[tmp].Element; j--){
                SortSeq[j]=SortSeq[j-1];
            }
            SortSeq[j] = tmp;
            end++;
        }
    }
/*    i=0;
    while(SortSeq[i]!=-1){
        printf("%d ",G->adjlist[SortSeq[i]].Element);
        i++;
    }
    printf("\n");
*/
    EdgeNode * edge;
    while(end-beg>0){
        v=SortSeq[beg];
        cnt++;
        beg++;

        if(cnt<ValidNum)
            printf("%d ",G->adjlist[v].Element);
        else
            printf("%d",G->adjlist[v].Element);


        for(edge=G->adjlist[v].FirstEdge; edge; edge=edge->Next){
            --(G->adjlist[edge->Adjv].InDegree);

            if(G->adjlist[edge->Adjv].InDegree == 0){
                tmp=edge->Adjv;
                for(j=end;j>beg&&
                G->adjlist[SortSeq[j-1]].Element>G->adjlist[tmp].Element;j--){
                    SortSeq[j]=SortSeq[j-1];
                }
                SortSeq[j] = tmp;
                end++;
            }
        }
    }
}

int main(){
    int i;
    HashTable * H = malloc(sizeof(HashTable)); //a pointer

    scanf("%d",&H->TblSzie);
    for(i=0; i<H->TblSzie; i++)
        scanf("%d",&H->Element[i]);
    
    ALGraph * G = malloc(sizeof(ALGraph));
    HashToGraph(H,G);

    TopSort(G);

    return 0;
}