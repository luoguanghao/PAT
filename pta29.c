#include<stdio.h>
#define MAX 10001

void Swap(int A[],int a,int b){
    int tmp=A[a];
    A[a]=A[b]; A[b]=tmp;
}

int main(){
    int N,tmp,anx,cnt,i,j;
    int A[MAX];

    cnt=0; anx=0;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&tmp);
        A[tmp]=i;
        if(tmp!=i && tmp!=0) cnt++;
    }

    int index=1;
    while(cnt>0){
        if(A[0]==0){
            /*while(index<N){
                if(A[index]!=index){
                    Swap(A,0,index);
                    anx++;
                    break;
                }
                index++;
                }*/
            
            for(; index<N; index++){
                if(A[index]!=index){
                    Swap(A,0,index);
                    anx++;
                    break;
                    //printf("%d",index);
                }
            }
        }

        while(A[0]!=0){
            Swap(A,0,A[0]);
            cnt--;
            anx++;
        }
    }

    printf("%d",anx);

    return 0;
}