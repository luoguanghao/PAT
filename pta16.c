#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 101
#define null -1

typedef struct{
    int x,y;
    char Visited;
}CrocodileType;

CrocodileType Crocodile[MAXSIZE];
double DistTabl[MAXSIZE][MAXSIZE];
/////stack///////
typedef struct{
    int data[MAXSIZE];
    int top;
}Stack;

void Push(Stack * S,int item){
    S->data[++(S->top)]=item;
}

int Pop(Stack * S){
    return S->data[S->top--];
}

int Top(Stack * S){
    return S->data[S->top];
}
//////////////
int IsSafe(CrocodileType c,int D){
    if((50-abs(c.x))<=D || (50-abs(c.y))<=D)
        return 1;
    else
        return 0;
}

void DFS(int N, int D){
    Stack S;
    S.top=-1;
    //////////
    int v,i,j;
    Crocodile[0].Visited=1;
    Push(&S,0);
    while(S.top!=-1){
        v=Top(&S);
        for(i=1;i<=N;i++){
            if(DistTabl[v][i]!=null && !Crocodile[i].Visited){
                Push(&S,i);
                Crocodile[i].Visited=1;
                if(IsSafe(Crocodile[i],D)){
                    printf("Yes\n"); return;
                }
                break;
            }
        }
        if(i>N)
            Pop(&S);
    }
    printf("No\n");
}

int main(){
    int x,y,N,D,i,j;
    
    for(i=0;i<MAXSIZE;i++){
        for(j=0;j<MAXSIZE;j++){
            DistTabl[i][j]=null;
        }
    }

    scanf("%d %d",&N,&D);
    if(D>=50){
        printf("Yes\n");
        return 0;
    }
    for(i=1; i<=N; i++){
        //printf("i=%d\n",i);
        scanf("%d %d",&Crocodile[i].x,&Crocodile[i].y);
        Crocodile[i].Visited=0;
    }

    int x2_x1, y2_y1, Distance;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            if(i!=j){
                x2_x1=pow(Crocodile[i].x-Crocodile[j].x,2);
                y2_y1=pow(Crocodile[i].y-Crocodile[j].y,2);
                Distance = sqrt( x2_x1 + y2_y1 );
                if(Distance<=D) DistTabl[i][j]=DistTabl[j][i]=Distance;
            }
        }

        Distance=sqrt(pow(Crocodile[i].x,2)+pow(Crocodile[i].x,2))-15;
        if(Distance<=D) DistTabl[i][0]=DistTabl[0][i]=Distance;
    }
/*
    for(i=0;i<=N;i++){
        for(j=0;j<=N;j++){
            printf("%4.1f ",DistTabl[i][j]);
        }
        printf("\n");
    }
*/
    DFS(N,D);

    return 0;
}
