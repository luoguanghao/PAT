#include<stdlib.h>
#include<stdio.h>

enum EntryType{Legitimate,Empty};
typedef int ElementType;

struct HashEntry{
    ElementType Elem;
    EntryType Info; //标记是否空
};

struct HashTbl{
    int TableSize;
    struct HashEntry *hashcell;
};

typedef struct HashTbl * HashTable;

void Initialize(HashTable H,int TableSize){
    H->TableSize = TableSize;
    H->hashcell = malloc(sizeof(struct HashEntry)*TableSize);
    while(TableSize)
        H->hashcell[--TableSize].Info = Empty;
}

int Hash(int P, ElementType Key){
    return Key%P;
}

int Find(HashTable * H, ElementType Key){
    int Pos = Hash(H->TableSize, Key);
    while(H->hashcell[Pos].Info != Empty
        && H->hashcell[Pos].Elem != Key ){
        Pos++;
        if(Pos == TableSize)
            Pos -= TableSize;

    }
    return Pos;
}

void InsertOrOutput(HashTable H,ElementType Key){
    int Pos=Find(H,Key);
    if(H->hashcell[Pos].Info == Empty){
        H->hashcell[Pos].Elem = Key;
        H->hashcell[Pos].Info = Legitimate;
    }
    printf("%d",Pos);
}

int main(){
    int N,P,Key,i;
    HashTable * H = malloc(sizeof(struct HashTbl));
    scanf("%d %d",&N,&P);
    Initialize(H,P);

    scanf("%d",&Key);
    InsertOrOutput(H,Key);

    for(i=1;i<P;i++){
        printf(" ");
        scanf("%d",&Key);
        InsertOrOutput(H,Key);
    }
    printf("\n");
    
    return 0;
}