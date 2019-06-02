#include<stdio.h>
#include<stdlib.h>

#define MAXV 1000

typedef int DisjSet[MAXV+1];

struct EdgeType{
    int v1,v2;
    int w;
};

DisjSet VSet;
struct EdgeType *ESet;

//并查集
void InitializeVSet(int N){
    for(int i=1; i<=N; i++){
        VSet[i]=-1;
    }
}

void SetUnion(int Root1,int Root2){
    if(VSet[Root1]<=VSet[Root2]){
        VSet[Root1]+=VSet[Root2];
        VSet[Root2]=Root1;      
    }else{
        VSet[Root2]+=VSet[Root1];
        VSet[Root1]=Root2;        
    }
}

int Find(int v){

    int Root,trail,lead;
    for(Root=v; VSet[Root]>0; Root=VSet[Root]) //find the root

    for(trail=v; trail!=Root; trail=lead){
        lead=VSet[trail];
        VSet[trail]=Root;
    }

    return Root;
}

//最小堆
void MinHeap(int P,int M){
    int Parent,Child;
    struct EdgeType X = ESet[P];

    for(Parent=P; Parent*2<=M; Parent=Child){
        Child=Parent*2;
        if((Child+1<=M) && (ESet[Child+1].w<ESet[Child].w)) //易错
            Child++;
        if(X.w <= ESet[Child].w)
            break;
        else{
            ESet[Parent]=ESet[Child];
        }
    }
    ESet[Parent]=X;
}

void InitializeESet(int M){ ////?????
    for(int i=M/2; i>0; i--){
        MinHeap(i,M);
    }
}

int GetEdge(int CurrentSize){
    struct EdgeType X;

    X=ESet[1];
    ESet[1]=ESet[CurrentSize];
    ESet[CurrentSize]=X;
    MinHeap(1,CurrentSize-1);

    return CurrentSize-1;
}

void Kruskal(int N,int M){
    int NextEdge=M;
    int count=0;
    int ecount=0;
    int Root1,Root2;

    InitializeESet(M);
    InitializeVSet(N);

   while(ecount<N-1){
        printf("*%d\n",NextEdge);
        if(NextEdge<=0){
          break;
        }
       
        NextEdge=GetEdge(NextEdge);
        Root1=Find(ESet[NextEdge+1].v1);
        Root2=Find(ESet[NextEdge+1].v2);
        
        if(!(Root1==Root2)){
            SetUnion(Root1,Root2);
            count += ESet[NextEdge+1].w;
            ecount++;
        }
       
    }
    if(ecount < N-1) count=-1;

    printf("%d\n",count);
}

int main(){
    int N,M,i,out=0;
    scanf("%d %d",&N,&M);
        if(M < N-1)
            printf("*\n");
        else{
            ESet=malloc(sizeof(struct EdgeType) * M);
            for(i=1; i<=M; i++)
                scanf("%d %d %d",&ESet[i].v1,&ESet[i].v2,&ESet[i].w);
            
            Kruskal(N,M);
            
        }
    return 0;
}