#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int maxn = 2001;
map<string,int> stringToInt;
map<int,string> intToString;
int Graph[maxn][maxn];
int visited[maxn];
int weight[maxn];
int m;

struct GangType{
	string name;
	int size;
};
vector<GangType> g;
int tmpSize, tmpValue, tmpHead, tmpMax;

void dfs(int v){
	cout << intToString[v] << " ";
	visited[v]=1;
	for(int i=1;i<=m;i++){
		if(visited[i]==0&&Graph[v][i])
			dfs(i);
	}
}

void dfs2(int v){
	if(weight[v]>tmpMax){
		tmpMax=weight[v];
		tmpHead=v;
	}
	
	tmpSize++;
	//cout << intToString[v] << " ";
	visited[v]=1;	
	for(int i=1;i<=m;i++){
		if(visited[i]==0&&Graph[v][i]){
			dfs2(i);
		}
		if(Graph[v][i]){
			tmpValue+=Graph[v][i];
		}
	}
}

int main(int argc, char *argv[]) {
	fill(Graph[0],Graph[0]+maxn,0);
	fill(weight,weight+maxn,0);
	int n,k;
	cin >> n >> k;
	string a,b; int value; int index=1;
	for(int i=0;i<n;i++){
		cin >> a >> b >> value;
		if(stringToInt[a]==0){
			stringToInt[a]=index;
			intToString[index]=a;
			index++;
		}
		if(stringToInt[b]==0){
			stringToInt[b]=index;
			intToString[index]=b;
			index++;
		}
		Graph[stringToInt[a]][stringToInt[b]]=value;
		
		weight[stringToInt[a]]+=value;
		weight[stringToInt[b]]+=value;
	}
	m=intToString.size();
	/*for(int i=1;i<=intToString.size();i++){
		cout << intToString[i] << '\n';
	}*/
	/*
	fill(visited,visited+maxn,0);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(visited[i]==0){
			dfs(i);
			cnt++;
			printf("\n");
		}
	}
	printf("%d\n",cnt);
	*/
	
	fill(visited,visited+maxn,0);
	for(int i=1;i<=m;i++){
		tmpSize=0; tmpValue=0, tmpMax=0;
		if(visited[i]==0){
			dfs2(i);
			if(tmpSize>2&&tmpValue>k){
				GangType tmpGang;
                tmpGang.name=intToString[tmpHead];
                tmpGang.size=tmpSize;
                g.push_back(tmpGang);
				//printf("%d %d\n",tmpSize,tmpValue);
				//cout << intToString[tmpHead] << "\n";
			}
		}		
	}
    printf("%ld\n",g.size());
    for(int i=0;i<g.size();i++){
        cout << g[i].name << " " << g[i].size << "\n";
    }
	
	/*////
	printf("...");
	for(int i=1;i<=m;i++) cout<<intToString[i];
	printf("\n"); 
	for(int i=1;i<=m;i++){
		cout << intToString[i];
		for(int j=1;j<=m;j++){
			printf("%3d",Graph[i][j]);
		}
		printf("\n");
	}
	////*/
}