#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define NumMax 11
#define PasswordMax 17

typedef struct{
    char QQNum[NumMax];
    char Password[PasswordMax];
    char info;
}UserType;

struct HashTbl{
    UserType * User;
    int Size;
};
typedef struct HashTbl * HashTable;

int NextPrime(int N){
    int i;
    N *= 2;
    if(!(N%2)) N++;
    for(;;N+=2){
        for(i=sqrt(N); i>2; i--)
            if(!(N%i)) break;
        if(i==2) break; /////////????????///
    }
    return N;
}

HashTable InitializeHash(int N){
    int i;
    HashTable H = malloc(sizeof(struct HashTbl));
    H->Size = NextPrime(N);
    H->User = malloc(sizeof(UserType) * H->Size);
    for(i=0; i<H->Size; i++)
        H->User[i].info = '0';

    return H;
}

int HashFind(HashTable H, char *QQNum){
    int CurPos,FinPos,ColTim;
    ColTim = 0;
    FinPos = CurPos = atoi(QQNum+6)%H->Size;////
    
    while(H->User[FinPos].info == '1'){ ///
        if(strcmp(H->User[FinPos].QQNum,QQNum)==0) return FinPos;

        ColTim++;
        if(ColTim%2){ //odd time
            FinPos = (CurPos + pow((ColTim+1)/2 , 2));
            while(FinPos>=H->Size)
                FinPos -= H->Size;
        }else{
            FinPos = (CurPos - pow(ColTim/2 , 2));
            while(FinPos<0)
                FinPos += H->Size;
        }
    }
    return FinPos;
}

void New(HashTable H, char *QQNum, char *Password){
    int Pos;
    Pos = HashFind(H,QQNum);
    if(strcmp(H->User[Pos].QQNum,QQNum)==0){
        printf("ERROR: Exist\n");
        return;
    }
    else{
        strcpy(H->User[Pos].QQNum, QQNum);
        strcpy(H->User[Pos].Password, Password);
        H->User[Pos].info = '1';
        printf("New: OK\n");
        return;
    }
    
}

void Login(HashTable H, char *QQNum, char *Password){
    int Pos;
    Pos = HashFind(H,QQNum);
    if(strcmp(H->User[Pos].QQNum,QQNum)==0){
        if(strcmp(H->User[Pos].Password,Password)==0)
            printf("Login: OK\n");
        else
            printf("ERROR: Wrong PW\n");
    }else
        printf("ERROR: Not Exist\n");
}


int main(){ ////////??????????/
    int N,p;
    char c[2],QQNum[NumMax],Password[PasswordMax];
    HashTable H;

    scanf("%d",&N);
    H = InitializeHash(N);
    p=N;
    while(p){
        
        scanf("%s",c);//////此处
        scanf("%s",QQNum);
        scanf("%s",Password);
        if(!strcmp(c,"L"))
            Login(H,QQNum,Password);
        else
            New(H,QQNum,Password);

        p--;
    }

    return 0;
}