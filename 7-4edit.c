#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAXP 1000
#define MAXL 100
#define MAXC 81

struct PageType{
    char cont[MAXL][MAXC];
    int Next;
}Page[MAXP];


void Read(int Pn, int Ln){
    getchar();
    for(int i=0; i<Pn; i++){
        for(int j=0; j<Ln; j++){
            gets(Page[i].cont[j]);
        }
        Page[i].Next = -2;
    }
}

void Initialize(int T[],int Pn){
    T[0]=0;
    for(int i=1; i<Pn; i++)
        T[i]=T[i-1]+1;
}

void Sort(int T[],int Pn, int Line){
    int i,j,tmp;
    
    Initialize(T,Pn);
    for(i=1;i<Pn;i++){
        tmp=T[i];
        for(j=i; (j>0)&&(strcmp(Page[T[j-1]].cont[Line],Page[tmp].cont[Line])>0); j--){
            T[j]=T[j-1];
        }
        T[j]=tmp;
    }
}

int main(){
    int Pn,Ln,i,j;
    scanf("%d %d",&Pn,&Ln);
    Read(Pn,Ln);

    int Thead[Pn];
    int Ttail[Pn];

    Sort(Thead,Pn,0);
    Sort(Ttail,Pn,Ln-1);

    for(i=0; i<Pn; i++){
        for(j=0; j<Ln; j++)
            printf("%s      %s\n",Page[Thead[i]].cont[j],Page[Ttail[i]].cont[j]);
        printf("-----------\n");
    }

    return 0;
}