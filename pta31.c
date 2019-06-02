//循环控制 原理

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

enum EntryType { Legitimate,Empty };

struct HashEntry{
    int data;
    enum EntryType Info;
};

struct HashTbl{
    int TblSize;
    struct HashEntry * Cells;
};

typedef struct HashTbl * HashTable;

int NextPrime(int n){
    int i;
    if(!(n%2)) n++; //要奇数
    for(;; n += 2){
        for(i=(int)sqrt(n);i>2;i--){
            if(!(n%i)){
                break;
            }
        }
        if(i==2) break;
    }
    return n;
}

HashTable InitializeHash(int M){
    int i;
    HashTable H;

    H = malloc(sizeof(struct HashTbl));
    H->TblSize = NextPrime(M);
    H->Cells = malloc(sizeof(struct HashEntry) * H->TblSize);
    for(i=0;i<H->TblSize;i++)
        H->Cells[i].Info=Empty;

    return H;
}

int HashFind(HashTable H,int Key){
    int CurPosi, FinalPosi, ColliTime=0;
    CurPosi = FinalPosi = Key % H->TblSize;
    while(H->Cells[FinalPosi].Info != Empty && ColliTime < H->TblSize){
        if(++ColliTime%2){
            FinalPosi = CurPosi + pow((ColliTime+1)/2,2);
            while(FinalPosi >= H->TblSize)
                FinalPosi -= H->TblSize;
        }else{
            FinalPosi = CurPosi - pow(ColliTime/2,2);
            while(FinalPosi < 0)
                FinalPosi += H->TblSize;
        }
    }
    if(ColliTime == H->TblSize)
        return -1;
    
    return FinalPosi;
}

void InsertAndPrint(HashTable H,int Key){
    int FinalPosi = HashFind(H,Key);

    if(FinalPosi == -1){
        printf("-");
        return;
    }

    if(H->Cells[FinalPosi].Info == Empty){
        H->Cells[FinalPosi].data = Key;
        H->Cells[FinalPosi].Info = Legitimate;
    }

    printf("%d",FinalPosi);
}

int main(){
    int M,N,i,Key;
    HashTable H;

    scanf("%d %d",&M,&N);
    H = InitializeHash(M);

    scanf("%d",&Key);
    InsertAndPrint(H,Key);
    for(i=1;i<N;i++){
        scanf("%d",&Key);
        printf(" ");
        InsertAndPrint(H,Key);
    }
    

    return 0;
}