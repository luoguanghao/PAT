//未编译
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAXN 100000
#define MAXS 10

typedef struct Message{
    char Msg[MAXS+1];
    int p;
}ElementType;

typedef struct HeapStruct *MinHeap;
typedef struct HeapStruct{
    ElementType *Element;
    int size;
};

MinHeap CreateHeap(int MaxSize){
    MinHeap H=(MinHeap*)malloc(sizeof(MinHeap));
    H->size=0;
    H->Element=(ElementType)malloc(sizeof(ElementType)*(MaxSize+1));
    H->Element[0].p=-1;;

    return H;
}

void Insert(MinHeap H,ElementType X){

    for(i=++H->size; H->Element[i/2].p>X.p; i=i/2){
        H->Element[i].p = H->Element[i/2].p;
        strcpy(H->Element[i].Msg,H->Element[i].Msg);
    }
    H->Element[i].p=X.p;
    strcpy(H->Element[i].Msg , X.Msg);
}

ElementType DeleteMin(MinHeap H){
    int Parent,Child;
    ElementType MinX,tmp;

    if(!H->size){
        MinX.p=-1
        return MinX;
    }

    MinX.p=H->Element[1].p;
    strcpy(MinX.Msg,H->Element[1].Msg);
    
    tmp.p=H->Element[size].p;
    strcpy(tmp.Msg,H->Element[size].Msg);
    for(Parent=1; Parent*2<=H->size; Parent=Child){ //?
        Child=Parent*2;
        if(H->Element[Child+1] && H->Element[Child+1]<H->Element[Child])
            Child++;
        if(tmp.p <= H->Element[Child].p) break;
        else{
            H->Element[Parent].p=H->Element[Child].p;
            strcpy(H->Element[Parent].Msg=H->Element[Child].Msg);
        }
    }
    H->Element[Parent].p=tmp.p;
    strcpy(H->Element[Parent].Msg=tmp.Msg);

    return MinX;
}

int main(){
    int N,i;
    char cmd[4];
    MinHeap H;
    ElementType X;

    scanf("%d",&N);
    H=CreateHeap(N);
    for(i=0;i<N;i++){
        scanf("%s",&cmd);
        if(cmd[0]=='P'){
            scanf("%s %d",&X.Msg,&X.p);
            Insert(H,X);
        }else{
            X=DeleteMin(H);
            if(X.p==-1) printf("ERROR\n");
            else printf("%s\n",X.Msg);
        }
    }

    return 0;
}