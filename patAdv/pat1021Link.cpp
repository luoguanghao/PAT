#include <iostream>
#include <set>
using namespace std;
const int maxn = 10001;
int maxDepth;
set<int> a;
struct Edge{
	int data;
	Edge *Next;	
};
struct Node{
	Edge *FirstEdge;
}node[maxn];
int Visited[maxn];

void dfs(int v,int depth,int type){
	Visited[v]=1;
	Edge *edge;
	for(edge=node[v].FirstEdge;edge;edge=edge->Next){
		if(Visited[edge->data]==0){
			dfs(edge->data,depth+1,type);
		}
	}
	if(type && edge==NULL){
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
	Edge *edge=NULL;
	for(int i=0;i<n-1;i++){
		cin >> v1 >> v2;
		edge=(Edge*)malloc(sizeof(Edge));
		edge->data=v2; edge->Next=node[v1].FirstEdge;
		node[v1].FirstEdge=edge;
		
		edge=(Edge*)malloc(sizeof(Edge));
		edge->data=v1; edge->Next=node[v2].FirstEdge;
		node[v2].FirstEdge=edge;
	}
	int cnt=0;
	fill(Visited,Visited+maxn,0);
	for(int i=1;i<=n;i++){
		if(Visited[i]==0){
			dfs(i,1,0);
			cnt++;
		}
	}
	if(cnt>1){
		printf("Error: %d components",cnt);
	}
	maxDepth=0;
	for(int i=1;i<=n;i++){
		fill(Visited,Visited+maxn,0);
		dfs(i,1,1);
	}
	for(set<int>::iterator it=a.begin();it!=a.end();it++){
		printf("%d\n",*it);
	}
	return 0;
}