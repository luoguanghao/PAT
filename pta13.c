#include<stdio.h>
#include<stdlib.h>
#define MAX 10001

void Initialize(int a[],int N){
    for(int i=1;i<=N;i++){
        a[i] = -1;
    }
}

int Find(int a[],int c){ //找根 记得路径压缩
    /*int i = c;
    while(a[i] > 0){
        i = a[i]
    }
    return i;*/
    if (a[c] < 0)
        return c;
    
    return a[c]=Find(a,a[c]);
}

void SetUnion(int a[],int Root1,int Root2){
    if(-a[Root1] > -a[Root2]){
        a[Root1] += a[Root2];
        a[Root2]=Root1;       
    }else{
        a[Root2] += a[Root1];
        a[Root1]=Root2; 
    }
}

void Check(int a[]){
    int c1,c2;
    scanf("%d %d",&c1,&c2);
    if(Find(a,c1)==Find(a,c2))
        printf("yes\n");
    else
        printf("no\n");   
}

void Input(int a[]){
    int c1,c2,Root1,Root2;

    scanf("%d %d",&c1,&c2);
    Root1=Find(a,c1);
    Root2=Find(a,c2);
    if(Root1 != Root2)
        SetUnion(a,Root1,Root2);

}

void CheckNetWork(int a[],int N){
    int count=0;
    int i;
    
    for(i=1;i<=N;i++){
        if(a[i]<0) count++;
    }
    if(count==1)
        printf("The network is connected.");
    else
        printf("There are %d components.",count);
}

int main(){
    int N;
    int a[MAX];
    int i;
    char in;

    scanf("%d",&N);
    Initialize(a,N);

    do{
        scanf("%c",&in);
        switch(in){
            case'C': Check(a); break;
            case'I': Input(a); break;
            case'S': CheckNetWork(a,N); break; 
        }
    }while(in != 'S');
/*
    for(i=1;i<=N;i++){
        printf("%d ",a[i]); 
    }
*/
    return 0;
}