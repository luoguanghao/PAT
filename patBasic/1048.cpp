#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	string ra(a.rbegin(),a.rend());
	string rb(b.rbegin(),b.rend());
	int out[105];
	int i;
	for(i=0;i<ra.length()&&i<rb.length();i++){
		if((i+1)%2){
			out[i]=(ra[i]-'0'+rb[i]-'0')%13;
			
		}else{
			out[i]=(rb[i]-'0')-(ra[i]-'0');
			if(out[i]<0) out[i]+=10;
		}
	}
	for(;i<rb.length();i++){
		out[i]=rb[i]-'0';
	}
	for(;i<ra.length();i++){
		if((i+1)%2){
			out[i]=ra[i]-'0';
		}else{
			out[i]=10-(ra[i]-'0');
		}
	}
	
	
	for(int j=i-1;j>=0;j--){
		if(out[j]<10){
			cout << out[j];
		}else if(out[j]==10){
			cout << 'J';
		}else if(out[j]==11){
			cout << 'Q';
		}else if(out[j]==12){
			cout << 'K';
		}
	}

	return 0;
}