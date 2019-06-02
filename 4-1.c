#include<stdlib.h>
#include<stdio.h>

#define MAX 50

typedef struct TNode{
    char Data;
    struct TNode *left;
    struct TNode *right;
}TreeNode;
typedef TreeNode *BinTree;

BinTree CreateBinTree(char *Pre,char *In,int Len){
    int i;
    BinTree T;

    if(!Len) return NULL;

    T=(BinTree*)malloc(sizeof(BinTree));
    T->Data=Pre[0];
    
    for(i=0; i<Len; i++)
        if(Pre[0]==In[i]) break;
    T->left=CreateBinTree(Pre+1, In, i);
    T->right=CreateBinTree(Pre+i+1, In+i+1, Len-i-1);

    return T;
}

int Height(BinTree T){
    int height,h1,h2;

    if(!T){
        height=0;
    }else{
        h1=Height(T->left);
        h2=Height(T->right);
        height=(h1 > h2) ? h1 : h2;
        height++;
    }
    return height;
}

int main(){
    int N;
    char Pre[MAX+1],In[MAX+1];
    BinTree T;

    scanf("%d",&N);
    scanf("%d\n%d",Pre,In);
    T=CreateBinTree(Pre,In,N);
    printf("%d\n",Height(T));

    return 0;
}