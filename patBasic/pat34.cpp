#include <iostream>
#include <>
using namespace std;

struct Num{
    int up,down;
};

int gcd(int a, int b){
    return !b?a:gcd(b,a%b)
}

int main(){
    Num a,b,sum,cha,mul,shang; 

    scanf("%d/%d %d/%d",a.up, a.down, b.up, b.down);
    //+
    sum.up = a.up*b.down + a.down*b.up;
    sum.down = a.down*b.down;
    int g=gcd(sum.up,sum.down);
    sum.up/=g; sum.down/=g;

    //-
    cha.up = a.up*b.down - b.up*a.down;
    cha.down = a.down*b.down;
    int g=gcd(cha.up,cha.down);
    cha.up/=g; cha.down/=g;

    //x
    mul.up = a.up*b.up;
    mul.
}