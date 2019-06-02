#include<time.h>
#include<stdio.h>

int main(){
    long c1,c2;
    int clk=100;
    scanf("%ld %ld",&c1,&c2);
    long mtime = c2-c1;
    mtime = (0.5+(double)mtime/100); /////加上0.5可以保证四舍五入！！！
    //printf("%d\n",mtime);
    int h = (int)(mtime / 3600);
    mtime %= 3600;
    int min = mtime /60;
    int sec = mtime%60;

    printf("%02d:%02d:%02d",h,min,sec);
    return 0;
}