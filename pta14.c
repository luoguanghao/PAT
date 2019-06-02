#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 64


typedef struct EType{
    char word;
    int frequency;

    struct EType * Right, * Left;
}ElementType;
typedef ElementType * HuffManTree;

typedef struct HeapStruct * MinHeap;
struct HeapStruct{
    ElementType data[MAX];
    int Size;
};

void Heap(MinHeap H,int start){
    int parent,child;
    ElementType Tmp;
    Tmp.frequency = H->data[start].frequency;
    Tmp.word=H->data[start].word;

    for(parent=start; parent*2<=H->Size; parent=child){ ///???
        child = parent*2;
        if(child+1<=H->Size && 
            H->data[child+1].frequency<H->data[child].frequency)
            child++;
        
        if(H->data[child].frequency < Tmp.frequency){
            H->data[parent].frequency = H->data[child].frequency;
            H->data[parent].word=H->data[child].word;
        }else break;

    }
    H->data[parent].frequency = Tmp.frequency;
    H->data[parent].word=Tmp.word;

}

void CreateMinHeap(MinHeap H){
    int i;
    for(i=H->Size/2; i>0;i--){
        Heap(H,i);
    }
}

ElementType DeleteHeap(MinHeap H){
    int i;
    ElementType Element;
    Element.frequency=H->data[1].frequency;
    Element.word=H->data[1].word;

    H->data[1].frequency=H->data[H->Size].frequency;
    H->data[1].word=H->data[H->Size].word;
    H->Size--;
    Heap(H,1);

    return Element;
}

void Insert(MinHeap H,HuffManTree HT){
    int i = ++H->Size;

    for(;H->data[i/2].frequency > HT->frequency; i=i/2){
        H->data[i].frequency=H->data[i/2].frequency;
        H->data[i].word=H->data[i/2].word;
    }
    H->data[i] = *HT;
}

HuffManTree CreateHuffmanTree(MinHeap H){
    int N,i,j;
    N=H->Size;
    HuffManTree HT = malloc(sizeof(ElementType));
    for(i=1; i<N; i++){ ///???
        * HT->Left=DeleteHeap(H);
        * HT->Right=DeleteHeap(H);
        HT->frequency=HT->Left->frequency + HT->Right->frequency;
        Insert(H,HT);
    }
    *HT = DeleteHeap(H);
    return HT;
}

int main(){
    int N,i;
    
    MinHeap H = malloc(sizeof(struct HeapStruct));
    scanf("%d",&N);
    H->Size = N;
    H->data[0].frequency = 0;
    for(i=1; i<=H->Size; i++){
        scanf("%s %d",&H->data[i].word,&H->data[i].frequency);
    }

    CreateMinHeap(H);
    ElementType element;
    /*for(i=1; i<=N; i++){
        element=DeleteHeap(H);
        printf("%d ",element.frequency);
    }*/
    
    HuffManTree HT = CreateHuffmanTree(H);

    return 0;
}