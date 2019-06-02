#include<stdio.h>
#include<stdlib.h>

int main(){
    char In[101];
    char ch[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

    scanf("%s",In);
    int i=0;
    int sum=0;
    while(In[i]!='\0'){
        sum += In[i]-'0';  //这是一种字符转整型的方法
        i++;
    }

    //printf("%d\n",sum);

    int num[3];
    int divi=100;
    i=0;
    while(divi >= 1){
        num[i] = sum/divi;
        sum %= divi;
        divi /= 10;
        i++;
    }

    //printf("%d",num[2]);

    for(i=0;i<2;i++){  
        if(num[i])
            printf("%s ",ch[num[i]]);
    }

    printf("%s",ch[num[2]]);

    return 0;

}