#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

struct Msg{
	string data;
	int P;
};
struct cmp{ //从大到小
	bool operator () (const Msg& a,const Msg& b) const{
		return a.P>b.P;
	}
};




int main(){
	int n;
	set<Msg> MsgBox;
	cin >> n;
	char cmd[3];
	Msg tmpMsg;
	for(int i=0; i<n; i++){
		scanf("%s",cmd);
		if(cmd[0]=='P'){
			cin >> tmpMsg.data >> tmpMsg.P;
			MsgBox.insert()
		}else{

		}
	}
}