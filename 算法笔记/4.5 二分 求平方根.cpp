#include <cmath>
#include <cstdio>
const double PI = acos(-1.0);
const double eps = 1e-5;
double r;

double f(double x){
    return x*x;
}

double solve(double n){
    double left = 1, right = 2;
    while(right - left < eps){
        mid = left + (right-left)/2;
        if(f(mid)<n){ //此处 < / <= 无所谓
            left = mid;
        }else{
            right = mid;
        }
    }
    return mid;
}

int main(){
    double n;
    scanf("%f",&n);
    printf("%f",solve(n));

    return 0;
}