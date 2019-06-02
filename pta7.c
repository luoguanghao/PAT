/*
几个问题
    1.用scanf() %c %s 时候注意
    2.变量，数组记得初始化
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 12
#define Null -1

typedef struct{
    int Visited;
    int left,right;
}TreeNode;
///////////Stack////////
typedef struct{
    int data[MAX];
    int rear,front;
}Queue;

void AddQ(Queue * Q,int item){
    if(Q->rear==-1){
        Q->rear=Q->front=0;
        Q->data[0]=item;
    }else{
        Q->data[++Q->rear] = item;
    }
}

int DeleQ(Queue * Q){
    int frontitem;
    if(Q->rear==Q->front){
        frontitem=Q->data[Q->front];
        Q->front=Q->rear=-1;
    }else{
        frontitem=Q->data[Q->front++];
    }
    return frontitem;
}

/////////////////////////

void FindtheLeave(TreeNode *T,int root){
    int v,i,j=0;
    int Out[MAX];
    Queue Q;
    Q.front=Q.rear=-1;

    AddQ(&Q,root);
    T[root].Visited=1;
    while(Q.rear != -1){
        v=DeleQ(&Q);
        //printf("Dele: %d\n",v);
        if(T[v].left!=Null && !T[T[v].left].Visited){
            AddQ(&Q,T[v].left);
            //printf("Add: %d\n",T[v].left);
            T[T[v].left].Visited=1;
        }
        if(T[v].right!=Null && !T[T[v].right].Visited){
            AddQ(&Q,T[v].right);
            //printf("Add: %d\n",T[v].right);
            T[T[v].right].Visited=1;
        }
        if(T[v].right==Null && T[v].left==Null){
            Out[++j]=v;
            //printf("%d ",v);
        }
    }
    
    for(i=1;i<j;i++)
        printf("%d ",Out[i]);
    printf("%d",Out[j]);
}

int main(){
    int N,i;
    char cl[2],cr[2];
    TreeNode Tree[MAX];
    int check[MAX];

    scanf("%d",&N);
    for(i=0;i<N;i++) check[i]=0;

    for(i=0;i<N;i++){
        scanf("%s %s",cl,cr);
        if(cl[0]!='-'){
            Tree[i].left=cl[0]-'0';
            check[Tree[i].left]=1;
        }else
            Tree[i].left=Null;

        if(cr[0]!='-'){
            Tree[i].right=cr[0]-'0';
            check[Tree[i].right]=1;
        }else
            Tree[i].right=Null;

        Tree[i].Visited=0;
    }

    for(i=0;i<N;i++){
        if(!check[i])
            break;
    }
    int root=i;
    
    /*for(i=0;i<N;i++){
        if(Tree[i].left==Null&&Tree[i].right==Null)
            printf("%d ",i);
    }*/
    
    FindtheLeave(Tree,root);

    return 0;
}