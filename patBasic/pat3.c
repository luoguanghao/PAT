#include<stdio.h>
#include<string.h>

int main(){
    int N,i;
    char ch[100];
    int a,b,c;
    char *p;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s",ch);
        printf("**%d**\n",i);
        if(!strcmp("PAT",ch)) printf("YES\n");
        else{
            a=b=c=0;
            p=ch;
            while(*p=='A'){p++;a++;}
            if(*p=='P'){p++;}
            while(*p=='A'){p++;b++;}
            if(*p=='T'){p++;}
            while(*p=='A'){p++;c++;}
            if(*p=='\0'&& b>0 &&c==a*b) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}