//Prim算法
#include<stdlib.h>
#include<stdio.h>

#define MAXN 1001
#define Inf 9999

typedef struct{
    int Cost[MAXN][MAXN];
    int MinCost[MAXN];
    int VertexN,EdgeN;
}Graph;

void ReadG(Graph *G){
    int i,j,v1,v2,w;
    //Initialize
    scanf("%d %d",&G->VertexN,&G->EdgeN);
    for(i=1; i<=G->VertexN; i++){
        for(j=1; j<=G->VertexN; j++){
            //if(i==j)
            //    G->Cost[i][j]=0;
            //else
                G->Cost[i][j]=Inf;
        }
        G->MinCost[i]=Inf;//MinCost标记结点是否在集合内
    }

    //Input
    for(i=1; i<=G->EdgeN; i++){
        scanf("%d %d %d",&v1,&v2,&w);
        G->Cost[v1][v2]=G->Cost[v2][v1]=w;
    }
}

void Prim(Graph *G,int S){
    int i,j,minc,mini;
    int sum=0;

    //MinCost的初始化
    for(i=1; i<=G->VertexN; i++){
        G->MinCost[i]=G->Cost[S][i];
    }
    G->MinCost[S]=0;//S点收入集合

    for(i=1; i<G->VertexN; i++){//deep think
    //找的是没有收入集合的最小结点，故能保证不形成回路；那么一共有N-1条边
        minc=Inf;
        for(j=1; j<=G->VertexN; j++){
            if(G->MinCost[j]!=0 && G->MinCost[j] < minc){ //没收入集合的最小  Question:如果有多个最小的，怎么办？
                minc=G->MinCost[j];
                mini=j;
            }
        }
             
        if(minc==Inf){//找不到这样的结点 图不联通
            sum=-1;
            break;
        }
        G->MinCost[mini]=0; //标记收入集合
        //printf("%d ",minc);
        sum=sum+minc;
        for(j=1; j<=G->VertexN; j++){
        if(G->MinCost[j]!=0){
            if(G->MinCost[j] > G->Cost[mini][j])//收入集合的结点，MinCost=0，不影响
                G->MinCost[j] = G->Cost[mini][j];
        }
        }    
    }  
    
    printf("%d\n",sum);
}

int main(){

    Graph * G = malloc(sizeof(Graph));
    ReadG(G);
/*////
    for(int i=1; i<=G->VertexN; i++){
        for(int j=1; j<=G->VertexN; j++){
            printf("%5d",G->Cost[i][j]);
        }
        printf("\n");
    }
////*/

    Prim(G,1);
    
    return 0;
}