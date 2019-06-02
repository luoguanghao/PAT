#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 100000
#define PhoneNum 11

typedef struct HashEntry * List;
struct HashEntry{
    char Phone[PhoneNum];
    int cnt;
    List Next;
};

struct HashTbl{
    int TableSize;
    List TheLists;
};

typedef struct HashTbl * HashTable;

int NextPrime(int n){
    int i;
    if(!(n%2)) n++;
    for(;; n+=2){
        for(i=sqrt(n);i>1;i--)
            if(!(n%i)) break;
        if(n==2) break;
    }

    return n;
}

void InitializeHash(int N,HashTable H){
    int i;
    H=malloc(sizeof(struct HashTbl));
    H->TableSize=NextPrime(N);
    H->TheLists = malloc(sizeof(struct HashEntry) * H->TableSize);
    for(i=0;i<H->TableSize;i++){
        H->TheLists[i].cnt=0;
        H->TheLists[i].Phone[0]='\0';
        H->TheLists[i].Next=NULL;
    }
}

int Hash(int Key,int P){
    return Key % P ;
}

void InsertAndCount(char * Key,HashTable H){
    List front,rear,NewCell;
    int index;
    index = Hash(atoi(Key+6),H->TableSize);
    front = &(H->TheLists[index]);
    rear = front->Next;

    while(rear && strcmp(rear->Phone,Key))
        rear=rear->Next;
    if(rear)
        rear->cnt++;
    else{
        NewCell=malloc(sizeof(struct HashEntry));
        NewCell->cnt++;
        strcpy(NewCell->Phone,Key);
        
        NewCell->Next=front->Next;
        front->Next=NewCell;
    }
}

void Output(HashTable H){
    List Ptr;
    int i,j,MaxCnt,PCnt;
    char MaxPhone[MAX+1];

    PCnt=0;
    MaxCnt=0;
    MaxPhone[0]='\0';

    for(i=0; i<H->TableSize; i++){
        Ptr=H->TheLists[i].Next;
        while(Ptr){
            if(Ptr->cnt > MaxCnt){
                MaxCnt = Ptr->cnt;
                strcpy(MaxPhone,Ptr->Phone);
                PCnt=1;
            }else if(Ptr->cnt == MaxCnt){
                PCnt++;
                if(strcmp(Ptr->Phone,MaxPhone)<0)
                    strcpy(MaxPhone,Ptr->Phone);
            }
            Ptr=Ptr->Next;
        }
    }

    printf("%s %d ",MaxPhone,MaxCnt);
    if(PCnt>1) printf("%d\n",PCnt); 
}

int main(){
    int N,i,j;
    char Key[MAX+1];
    HashTable H;

    scanf("%d",&N);
    InitializeHash(N,H); ///???
    for(i=0;i<N;i++){
        scanf("%s",Key);
        InsertAndCount(Key,H);
        scanf("%s",Key);
        InsertAndCount(Key,H);
    }

    Output(H);

    return 0;
}