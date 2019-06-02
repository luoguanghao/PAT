//舍去数据


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct manType{
	string name;
	int age,money;	
};
struct quryType{
	int quryNum,quryDown,quryUp;	
};


bool cmp(manType a,manType b){
	if(a.money!=b.money) return a.money>b.money;
	else if(a.age!=b.age) return a.age<b.age;
	else return a.name<b.name;
}

int main(){
	vector<manType> a;
	int n,k;
	cin >> n>>k;
	manType tmp;
	for(int i=0;i<n;i++){
		cin>>tmp.name>>tmp.age>>tmp.money;
		a.push_back(tmp);
	}
	
	sort(a.begin(),a.end(),cmp);
	
	vector<manType> b;
	vector<int> book(205,0);
	for(int i=0;i<n;i++){
		if(book[a[i].age]<=100){
			b.push_back(a[i]);
			book[a[i].age]++;
		}
	}
	
	
	vector<quryType> q;
	quryType tmpQ;
	for(int i=0;i<k;i++){
		cin >> tmpQ.quryNum>>tmpQ.quryDown>>tmpQ.quryUp;
		q.push_back(tmpQ);
	}
	
	for(int i=0;i<q.size();i++){
		printf("Case #%d:\n",i+1);
		int cnt=0;
		for(int j=0;j<b.size()&&cnt<q[i].quryNum;j++){
			if(q[i].quryDown<=b[j].age&&b[j].age<=q[i].quryUp){
				cout<<b[j].name<<" "<<b[j].age<<" "<<b[j].money<<endl;
				cnt++;
			}
		}
		if(cnt==0) printf("None\n");
	}
	
}