#include<stdlib.h>
#include<stdio.h>

#define MAXN 30000

typedef int DisjSet[MAXN+1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S,int N){
    for(int i=1;i<=N;i++){
        S[i]=-1;
    }
}

int SetUnoin(DisjSet S, SetType Root1, SetType Root2){
    if(S[Root1]<=S[Root2]){
        S[Root1]+=S[Root2];
        S[Root2]=Root1;

        return Root1;
    }else{
        S[Root2]+=S[Root1];
        S[Root1]=Root2;

        return Root2;
    }
}

SetType Find(DisjSet S, ElementType X){
    if(S[X]<0)
        return X;
    else
        return S[X]=Find(S,S[X]);////!!!!
}

void Input_Connection(DisjSet S){
    ElementType u,v;
    int m;
    SetType Root1,Root2;

    scanf("%d %d",&m,&u);
    Root1=Find(S,u);
    for(i=0;i<m;i++){
        scanf("%d",&v);
        Root2=Find(S,v);
        if(Root1!=Root2)
            Root1=SetUnoin(S,Root1,Root2);
    }
}

void Check_Max_Friend(DisjSet S, int N){
    int max
    for(int i=1;i<=N;i++){
        if((S[i]<0) && (max<-S[i]))
            max=-S[i];
    }
    printf("%d\n",max);
}

int main(){

    DisjSet S;
    int N,M,i;

    scanf("%d %d",&N,&M);
    Initialize(S,N);
    for(i=0;i<M;i++){
        Input_Connection(S);
    }
    Check_Max_Friend(S,N);

    return 0;
}