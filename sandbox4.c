#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;


int main(){
	string high[13]={"0","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	string low[13]={"tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

	int a;
	string b;
	cin >> a;

	int num,lowN,higN;
	string lowC, higC;
	for(int i=0; i<a; i++){
		getline(cin,b);
		if('0'<=b[0]&&b[0]<='9'){
			string::size_type sz;
			num = stoi(b,&sz);

			higN = num/13;
			lowN = num%13;

			cout << high[higN] << ' ' <<low[lowN] << '\n';
		}else{
			num = b.find(' ');
			if(num != -1){
				higC = b.substr(0,num);
				lowC = b.substr(num+1,b.length());
				for(int k=0;k<13;k++){
					if(high[k]==higC) higN=k;
				}
				for(int k=0;k<13;k++){
					if(low[k]==lowC) lowN=k;
				}
				cout << higN << lowN << '\n';
			}else{
				for(int k=0;k<13;k++){
					if(low[k]==b) lowN=k;
				}
				cout << lowN << '\n';
			}
		}
	}
	return 0;
}