#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;
const int inf = 999999;
const int maxv = 510;
struct Node{
	int v,dis;
	Node(int _v, int _dis): v(_v), dis(_dis) {};
};

int n,m,st,ed;
int weight[maxv], d[maxv], w[maxv], num[maxv];
vector<Node> AdjV[maxv];
set<int> pre[maxv];

bool inq[maxv];
void spfa(int s){
	int j,k,u,v,dist;
	fill(d, d+maxv, inf);
	memset(w, 0, sizeof(w));
	memset(num, 0, sizeof(num));

	queue<int> Q;
	Q.push(s);
	inq[s]=true;
	
	d[s]=0;
	num[s]=1;
	w[s]=weight[s];
	
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		inq[u]=false;
		for(j=0;j<AdjV[u].size();j++){
			v=AdjV[u][j].v; dist=AdjV[u][j].dis;
			if(d[v]>d[u]+dist){
				d[v]=d[u]+dist;
				w[v]=w[u]+weight[v];
				pre[v].clear();
				pre[v].insert(u);
				num[v]=num[u];
				
				if(!inq[v]){
					Q.push(v);
					inq[v]=true;
				}
			}else if(d[v]==d[u]+dist){
				if(w[v]<w[u]+weight[v])
					w[v]=w[u]+weight[v];
				pre[v].insert(u);
				num[v]=0;
				set<int>::iterator it;
				for(it=pre[v].begin();it!=pre[v].end();it++)
					num[v]+=num[*it];
					
				if(!inq[v]){
					Q.push(v);
					inq[v]=true;
				}
			}
		}
	}
	
}

int main(){
	int i,j,v1,v2,wt;
	scanf("%d %d %d %d",&n,&m,&st,&ed);
	for(i=0;i<n;i++)
		scanf("%d",&weight[i]);

	for(i=0;i<m;i++){
		scanf("%d %d %d",&v1,&v2,&wt);
		AdjV[v1].push_back(Node(v2,wt));
		AdjV[v2].push_back(Node(v1,wt));
	}

	spfa(st);

	printf("%d %d\n",num[ed],w[ed]);
	
	return 0;
}