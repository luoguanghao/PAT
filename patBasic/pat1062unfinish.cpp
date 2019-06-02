#include <iostream>
#include <cmath>
using namespace std;

bool OK(int a, int b){
	if(a==1&&b==1) return false;
	for(int i=a;i>=2;i--){
		if(b%i==0&&a%i==0) return false;
	}
	return true;
}
int main(){
	int n1,m1,n2,m2,k,l;
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
	if(n1*m2>n2*m1){
		l=n1; n1=n2; n2=l;
		l=m1; m1=m2; m2=l; 
	}
	//printf("%d %d %d",n1,k,m1);
	int front=int(ceil((n1+0.0)*(k/(m1+0.0)))); //printf("%.2f ",front);
	int rear=int(floor((n2+0.0)*(k/(m2+0.0)))); //printf("%.2f",rear);
	//printf("%d %d",front,rear);
	int cnt=0;
	for(int i=front;i<=rear;i++){
		if(OK(i,k)){
			if(cnt) printf(" ");
			cnt++;
			printf("%d/%d",i,k);
		}
	}
}