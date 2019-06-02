#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

struct Msg{
	string data;
	int P;
};
struct cmp{ //从small到big
	bool operator () (const Msg& a,const Msg& b) const{
		return a.P<b.P;
	}
};




int main(){
	int n;
	set<Msg,cmp> MsgBox;
	cin >> n;
	char cmd[3];
	Msg tmpMsg;
	for(int i=0; i<n; i++){
		scanf("%s",cmd);
		if(cmd[0]=='P'){
			cin >> tmpMsg.data >> tmpMsg.P;
			MsgBox.insert(tmpMsg);
		}else{
			if(MsgBox.size()==0){
				printf("EMPTY QUEUE!");
			}else{
				set<Msg>::iterator it=MsgBox.begin();
				cout << it->data << '\n';
				MsgBox.erase(it);
			}
		}
	}
}
/*
9
PUT msg1 5
PUT msg2 4
GET
PUT msg3 2
PUT msg4 4
GET
GET
GET
GET
*/