#include <cmath>
#include <cstdio>
const double PI = acos(-1.0);
const double eps = 1e-5;
double r;

int solve(int a, int b){
	if(b==0){
		return 1;
	}else if(b%2==1){
		return a*solve(a, b-1);
	}else{
		return solve(a,b/2) * solve(a,b/2);
	}
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	
	int ans=solve(a,b);
	printf("%d",ans);
	return 0;
}