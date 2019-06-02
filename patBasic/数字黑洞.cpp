#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	string s;
	cin >> s;
	int i;
	for(i=0;s[i]!='E';i++);
	//printf("%d\n",i);
	string t = s.substr(1,i-1);
	int n = stoi(s.substr(i+1));
	//printf("%d\n",n);
	if(s[0]=='-'){
		cout << '-';
	}
	
	if(n<0){
		cout << "0.";
		
		for(int j=0;j<abs(n)-1;j++){
			cout << '0';
		}
		for(int j=1;j<i;j++){
			if(s[j]!='.')
				cout << s[j];
		}
	}else if(n==0){
		for(int j=1;j<i;j++)
			cout << s[j];
	}else{
		cout << t[0];
		int cnt,j;
		for(j=2,cnt=0;j<t.length()&&cnt<n;j++,cnt++)
			cout << t[j];
		//printf("*%d %ld*\n",j,t.length());
		if(j==t.length()){
			for(int k=0;k<n-cnt;k++) cout << '0';
		}else{
			cout << '.';
			for(int k=j;k<t.length();k++) cout << t[k];
		}
	}
	return 0;
}