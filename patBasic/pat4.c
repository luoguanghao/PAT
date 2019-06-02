#include<stdio.h>
#include<string.h>

typedef struct{
    char Name[100];
    char No[100];
    int Grade;
}StuType;

int main(){
    int N,i,j;
    StuType tmp,max,min;
    max.Grade=0; min.Grade=100;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s %s %d",tmp.Name,tmp.No,&tmp.Grade);
        if(tmp.Grade>max.Grade) max=tmp;
        if(tmp.Grade<min.Grade) min=tmp;
    }

    printf("%s %s\n",max.Name,max.No);
    printf("%s %s",min.Name,min.No);

    return 0;
}