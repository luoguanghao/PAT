#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a,string b){
	return a+b<b+a;
}

int main(){
	int n; cin>>n;
	vector<string> v; string tmpS;
	for(int i=0;i<n;i++){
		cin >> tmpS;
		v.push_back(tmpS);
	}
	sort(v.begin(),v.end(),cmp);
	string outPut;
	for(int i=0;i<v.size();i++){
		outPut+=v[i];
	}
	while(outPut[0]=='0'){
		outPut.erase(outPut.begin());
	}
	if(outPut.length()==0) outPut="0";
	cout << outPut;
}