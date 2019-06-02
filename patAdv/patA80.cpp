#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct manType{
	int id;
	int rank;
	int GE,GI;
	double tG;
	vector<int> choice;
};

bool cmp(manType a, manType b){
	if(a.tG!=b.tG) return a.tG>b.tG;
	return a.GE>b.GE;
}

int main(){
	int n,m,k;
	vector<int> quota, passList[105];
	vector<manType> manList;
	
	cin>>n>>m>>k;
	int tmp;
	for(int i=0;i<m;i++){
		cin>>tmp;
		quota.push_back(tmp);
	}
	
	for(int i=0;i<n;i++){
		manType tmpMan;
		tmpMan.id=i;
		scanf("%d %d",&tmpMan.GE,&tmpMan.GI);
		tmpMan.tG=(tmpMan.GE+tmpMan.GI)/2;
		int tmpChoice;
		for(int j=0;j<k;j++){
			scanf("%d",&tmpChoice);
			tmpMan.choice.push_back(tmpChoice);
		}
		manList.push_back(tmpMan);
	}
	/*////
	for(int i=0;i<manList.size();i++){
		printf("\n");
		for(int j=0;j<manList[i].choice.size();j++){
			printf("%d ",manList[i].choice[j]);
		}
	}
	*////
	sort(manList.begin(),manList.end(),cmp);
	int r=1;
	for(int i=0;i<manList.size();i++){
		if(i>0&&(manList[i].GE!=manList[i-1].GE||manList[i].tG!=manList[i-1].tG))
			r=i+1;
		manList[i].rank=r;
	}

	/*
	for(int i=0;i<manList.size();i++)
		printf("id=%d %d %d rank=%d\n",manList[i].id,manList[i].GE,manList[i].GI,manList[i].rank);
	*/
	for(int i=0;i<manList.size();i++){
		//printf("\n");
		int c;
		for(c=0;c<manList[i].choice.size();c++){
			int choice=manList[i].choice[c]; //printf("%d ",choice);
			if(passList[choice].size()<quota[choice]||manList[passList[choice][passList[choice].size()-1]].rank==manList[i].rank){
				passList[choice].push_back(manList[i].id);
				break;
			}/*else if(manList[passList[choice][passList[choice].size()-1]].rank==manList[i].rank){
				passList[choice].push_back(manList[i].id);
				break;
			}*/
		}
	}
	for(int i=0;i<m;i++){
		sort(passList[i].begin(),passList[i].end());
		for(int j=0;j<passList[i].size();j++){
			if(j!=0)printf(" ");
			printf("%d",passList[i][j]);
		}
		if(i!=m-1) printf("\n");
	}
	return 0;
}