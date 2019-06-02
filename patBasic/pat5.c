#include<stdio.h>
#include<stdlib.h>

int set[101];
int cnt[1000];
int out[1000];

int main(){
    int N,i,j,k,tmp;

    for(i=0;i<101;i++)
        set[i]=0;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&cnt[i]);
        tmp=cnt[i];
        while(tmp!=1){
            if(!(tmp%2))
                tmp=tmp/2;
            else
                tmp=(tmp*3+1)/2;
            if(!set[tmp]&&tmp<101)
                set[tmp]=1;
        }
    }
    j=-1;
    for(i=0;i<N;i++){
        if(!set[cnt[i]]){
            //printf("*%d %d ",j,cnt[i]);
            j++; k=j;
            for(;k>0&&out[k-1]<cnt[i];k--)
                out[k]=out[j-1];
            out[k]=cnt[i];
        }
    }
    //printf("\n%d\n",j);

    for(i=0;i<j;i++)
        printf("%d ",out[i]);
    printf("%d",out[j]);

    return 0;
}