#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 101
#define null -1

typedef struct{
    int x,y;
    char Visited;
    int ancester;
}CrocodileType;

CrocodileType Crocodile[MAXSIZE];
int DistTabl[MAXSIZE][MAXSIZE];
CrocodileType EscapeWay[MAXSIZE];

///////Queue/////////////////////

typedef struct{
    int data[MAXSIZE];
    int front,rear;
}Queue;

void AddQ(Queue * Q,int item){
    if(Q->rear==-1){
        Q->rear=Q->front=0;
        Q->data[0]=item;
    }else{
        Q->data[++Q->rear]=item;
    }
}

int DeleQ(Queue * Q){
    int frontitem;
    frontitem=Q->data[Q->front];
    if(Q->rear==Q->front){
        Q->front=Q->rear=-1;
    }else{
        Q->front++;
    }
    return frontitem;
}
/////////////////////////////
int IsSafe(CrocodileType c,int d){
    return (50-abs(c.x)<=d || 50-abs(c.y)<=d);
}
/////stack///

////////////
void BFS(int n,int d){
    Queue Q;
    Q.rear=Q.front=-1;

    int layer,v,i,j,last;
    int top=0;   
    CrocodileType stack[MAXSIZE]; 

    AddQ(&Q,0);
    Crocodile[0].Visited=1;
    layer=0;
    while(Q.rear!=-1){
        v=DeleQ(&Q);

        for(i=0;i<=n;i++){
            if(!Crocodile[i].Visited && DistTabl[v][i]){
                AddQ(&Q,i);
                Crocodile[i].Visited=1;
                Crocodile[i].ancester=v;
                if(IsSafe(Crocodile[i],d)){
                                              
                    for(j=i;j!=0;j=Crocodile[j].ancester){
                        stack[++top]=Crocodile[j];
                    }
                    printf("%d\n",top+1);
                    while(top!=0){
                        printf("%d %d\n",stack[top].x,stack[top].y);
                        top--;
                    }
                    return;
                }
            }
        }
        
    }
    printf("0\n");
}

int dist(CrocodileType c1,CrocodileType c2){
    return sqrt( pow(c1.x-c2.x,2)+pow(c1.y-c2.y,2) );
}

int main(){
    int n,d,i,j,x,y;
    float firstdist;
    float firstjump[MAXSIZE];

    for(i=0;i<MAXSIZE;i++){
        for(j=0;j<MAXSIZE;j++){
            DistTabl[i][j]=0;
        }
        firstjump[i]=0;
    }

    scanf("%d %d",&n,&d);
    for(i=1;i<=n;i++){
        scanf("%d %d",&Crocodile[i].x,&Crocodile[i].y);
        Crocodile[i].Visited=0;
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dist(Crocodile[i],Crocodile[j])<=d && i!=j)
                DistTabl[i][j]=DistTabl[j][i]=1;           
        }

        firstdist = sqrt(pow(Crocodile[i].x,2)+pow(Crocodile[i].y,2))-7.5;
        if(firstdist <= d){
            DistTabl[i][0]=DistTabl[0][i]=1;
            firstjump[i]=firstdist;
        }
    }
/*
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            printf("%d ",DistTabl[i][j]);
        }
        printf("\n");
    }
*/  
    BFS(n,d);

    return 0;
}