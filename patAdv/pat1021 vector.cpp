#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn=10001;
vector<int> martix[maxn];
set<int> a;
int visited[maxn];
int maxDepth;
void dfs(int v,int depth,int type){
	
	visited[v]=1;
	int i;
	for(i=0;i<martix[v].size();i++){
		if(visited[martix[v][i]]==0){
			dfs(martix[v][i],depth+1,type);
		}
	}
	if(type && i==martix[v].size()){
		if(depth>maxDepth){
			a.clear();
			a.insert(v);
			maxDepth=depth;
		}else if(depth==maxDepth){
			a.insert(v);
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int v1,v2;
	for(int i=0;i<n-1;i++){
		cin >> v1 >> v2;
		martix[v1].push_back(v2);
		martix[v2].push_back(v1);
	}
	int cnt=0;
	fill(visited,visited+maxn,0);
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			dfs(i,1,0);
			cnt++;
		}
	}
	if(cnt>1){
		printf("Error: %d components",cnt);
		return 0;
	}
	
	maxDepth=0;
	for(int i=1;i<=n;i++){		
		fill(visited,visited+maxn,0);
		dfs(i,1,1);
	}
	for(set<int>::iterator it=a.begin();it!=a.end();it++){
		printf("%d\n",*it);
	}
	
	return 0;
}