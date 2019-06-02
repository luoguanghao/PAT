#include <cmath>
#include <cstdio>
const double PI = acos(-1.0);
const double eps = 1e-5;
double r;

double f(double R, double h){
	double alpha = 2acos( (R-h)/R );
	double S1 = (R-h) * sqrt(R*R - (R-h)*(R-h));
	double Swater = (alpha*R*R)/2 - S1;
	double semiCircle = PI * R*R / 2;
	return Swater / semiCircle;
}

double solve(double R, double h, double r){
	double left=0.0, right=R, mid;
	while(right - left > eps){
		mid = (right+left)/2;
		if(f(R,mid)<r){ //思考 啥时取等
			left=mid;
		}else{
			right=mid;
		}
	}
	return mid;
}

int main(){
	double R, h, r;
	scanf("%f %f %f",&R, &h, &r);
	double answer = solve(R,h,r);
	printf("%d",answer);

	return 0;
}