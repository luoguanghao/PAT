标准语句

#Queue#////////////////////////

typedef struct{
    int Data[MAX];
    int rear,front;
}Queue;

void InitializeQ(Queue * Q){
    Q->front=Q->rear= -1;
} 

void AddQ(Queue * Q, int item){
    if(Q->front==-1){
        Q->front=Q->rear=0;
        Q->Data[Q->rear] = item;
    }else{
        Q->Data[++Q->rear] = item;
    }
}

int DeleteQ(Queue * Q){
    int FrontItem;
    if(Q->front==Q->rear){
        FrontItem=Q->Data[Q->front];
        Q->front=Q->rear= -1;
    }else{
        FrontItem=Q->Data[Q->front++];
    }
    return FrontItem;
}
////////////////////////////////////

