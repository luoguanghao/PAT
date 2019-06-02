#include<stdlib.h>
#include<stdio.h>
#define MAXN 10000
#define MAXS 30

typedef struct TNode{
    char Name[MAXS];
    int count;
    struct TNode *left;
    struct TNode *right;
};
typedef struct TNode *BinTree;

BinTree Insert(BinTree T,char name){ //char

    if(!T){
        T=(BinTree*)malloc(sizeof(BinTree));
        strcpy(T->Name,name);
        T->count=1;
        T->left=T->right=NULL;
    }else{

        cmp=strcmp(name,T->Name);//？
        if(cmp<0){
            T=Insert(T->left,name);
        }
        else if(cmp>0){
            T=Insert(T->right,name);
        }else{
            T->count++;
        }
    }
        return T;
}

void Out_Print(BinTree T,int N){
    if(!T) return;
    Out_Print(T->left,N);
    printf("%s %.41f%c",T->Name,(double)((T->count)/N)*100.0,'%');
    Out_Print(T->right,N);
}

int main(){
    int N,i;
    char name[MAXS];
    BinTree T=NULL;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        get(name);
        T=Insert(T,name);
    }
    Out_Print(T);

    return 0;
}