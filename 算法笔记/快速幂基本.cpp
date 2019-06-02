#include <cmath>
#include <cstdio>
const double PI = acos(-1.0);
const double eps = 1e-5;
double r;

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int ans=1, base=a;
	while(b!=0){
		if(b&1!=0){
			ans*=base;
		}
		base*=base;
		b>>=1;
	}
	printf("%d",ans);
	
	return 0;
}