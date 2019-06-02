#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Node{
	int i,j;	
};

int m,n,tol;
int martix[1005][1005];
map<int,int> Map;

vector<Node> v;

bool Judge(int i,int j){
	int I[8]={1,1,1,-1,-1,-1,0,0};
	int J[8]={1,0,-1,1,0,-1,-1,1};
	for(int v=0;v<8;v++){
		int newi=i+I[v];
		int newj=j+J[v];
		//printf("%d %d\n",newi,newj);
		if(newi<0||newi>=n||newj<0||newj>=m) continue;
		//printf("%d\n",martix[newi][newj]-martix[i][j]);
		if(abs(martix[newi][newj]-martix[i][j])<=tol) return false;
		if(Map[martix[i][j]]>1) return false;
	}
	return true;
}

int main(){
	
	cin >> m >> n >> tol;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> martix[i][j];
			Map[martix[i][j]]++;
		}
	}
	int cnt=0 ,x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//printf("%d %d\n",i,j);
			if(Judge(i,j)){
				x=j+1; y=i+1;
				cnt++;
				//printf("(%d, %d): %d",j+1,i+1,martix[i][j]);
			}
		}
	}
	if(cnt==1){
		printf("(%d, %d): %d\n",x,y,martix[y-1][x-1]);
	}else if(cnt>1){
		printf("Not Unique\n");
	}else{
		printf("Not Exist\n");
	}
}