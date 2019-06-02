#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 999999;
const int maxn = 1030;
struct GasStationType{
	int flag;
	int id;
	int minD;
	float AvgDis;
}Station[12];
int Graph[maxn][maxn];
int visited[maxn];
int minDis[maxn];
int n,m,k,ds;

bool cmp(GasStationType a,GasStationType b){
	if(a.minD==b.minD) return a.AvgDis<b.AvgDis;
	else if(a.minD==b.minD&&a.AvgDis==b.AvgDis) return a.id<b.id;
	return a.minD>b.minD;
}

int GetID(string str){
	int ID=0, i=0;
	while(i<str.length()){
		if(str[i]!='G'){
			ID=ID*10+(str[i]-'0');
		}
		i++;
	}
	if(str[0]=='G') return ID+n;
	return ID;
}

void Dijkstra(int s){
	fill(visited,visited+maxn,0);
	fill(minDis,minDis+maxn,inf);
	minDis[s]=0;
	
	for(int i=1;i<=n+m;i++){
		int minD=inf, minV=-1;
		for(int v=1;v<=n+m;v++){
			if(minD>minDis[v]&&visited[v]==0){
				minD=minDis[v]; minV=v;
			}
		}
		if(minV==-1) break;
		visited[minV]=1;
		for(int u=1;u<=n+m;u++){
			if(visited[u]==0){
				if(minDis[u]>minDis[minV]+Graph[minV][u]){
					minDis[u]=minDis[minV]+Graph[minV][u];
				}
			}
		}
	}/*
	for(int i=1;i<=n+m;i++){
		if(minDis[i]!=inf) printf("%d ",minDis[i]);
	}printf("\n");*/
}

void inti(){
	for(int i=1;i<=m;i++){
		Station[i].flag=1;
	}
}

int main(int argc, char *argv[]) {
	
	fill(Graph[0],Graph[0]+maxn*maxn,inf);
	cin >> n >> m >> k >> ds;
	string a, b; int value;
	for(int i=0;i<k;i++){
		cin >> a >> b >> value;
		int v1=GetID(a);
		int v2=GetID(b);		
		Graph[v2][v1]=Graph[v1][v2]=value;
	}
	/*
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			if(Graph[i][j]==inf){
				printf(" x");
			}else
				printf("%2d",Graph[i][j]);
		}
		printf("\n");
	}
	*/
	inti();
	for(int Gs=n+1;Gs<=n+m;Gs++){
		Dijkstra(Gs);
		int min=inf, sum=0;
		for(int j=1;j<=n;j++){
			
			if(minDis[j]>ds) Station[Gs-n].flag=false;
			sum+=minDis[j];
			if(minDis[j]<min) min=minDis[j];
		}
		Station[Gs-n].id=Gs-n;
		Station[Gs-n].minD=min;
		Station[Gs-n].AvgDis=((sum+0.0)/n)+0.05;
		
	}
	//printf("G1 %d %.1f\n",Station[1].minD,Station[1].AvgDis);
	sort(Station+1,Station+m+1,cmp);
	int index;
	for(index=1;!Station[index].flag;index++);
	if(index<=m)	
		printf("G%d\n%.1f %.1f\n",Station[index].id,Station[index].minD+0.0,Station[index].AvgDis);
	else
		printf("No Solution");
		
	return 0;
}