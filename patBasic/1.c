#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i;
    scanf("%d",&n);
    i=0;
    while(n!=1){
        if(!(n%2))
            n /=2;
        else
            n=(3*n+1)/2;
        i++;
    }
    printf("%d\n",i);

    return 0;
}