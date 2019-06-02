#include<cstdio>
#include<algorithm>
#include<vector>
const int inf 999999;
using namespace std;

vector<int> pre[510];
vector<int> path,tempath;
int n,m,s,d;
int dis[510], dismap[510][510], costmap[510][510];
int visited[510];
int minCost = inf;
void dfs(int v){
    int i,j,post,front;
    tempath.push_back(v);
    if(v==s){
        int cost=inf;
        for(i=tempath.size()-1;i>0;i--){
            front=tempath[i]; rear=tempath[i-1]; 
            cost += costmap[front][rear];
        }
        if(cost<minCost){
            minCost=cost;
            path=tempath;
        }
        tempath.pop_back();
        return;
    }
    for(i=0;i<pre[v].size();i++){
        dfs(pre[v][i]);
    }
    tempath.pop_back;
}

void dijkstra(){
    int i,j;
    int minD,minV;

    pre[s].push_back(s);
    dis[s]=0;
    for(i=0;i<n;i++){
        minD=inf;
        for(j=0;j<n;j++){
            if(dis[j]<minD && !visited[j]){
                minD=dis[j]; minV=j;
            }
        }
        if(minD==inf) break;
        visited[minV]=1;

        for(j=0;j<n;j++){
            if(dis[j]>dis[minV]+dismap[minV][j] && !visited[j]){
                pre[j].clear();
                pre[j].push_back(minV);
                dis[j]=dis[minV]+dismap[minV][j];
            }else if(dis[j]==dis[minV]+dismap[minV][j] && !visited[j]){
                pre[j].push_back(minV);
            }
        }
    }
}

int main(){
    int i,j;
    scanf("%d %d %d %d",&n,&m,&s,&d);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dismap[i][j]=inf;
            costmap[i][j]=inf;
        }
        dis[i]=inf;
        visited[i]=0;
    }
    int v1,v2,d,c;
    for(i=0;i<m;i++){
        scanf("%d %d %d",&v1,&v2,&d,&c);
        dismap[v1][v2]=dismap[v2][v1]=d;
        costmap[v1][v2]=costmap[v2][v1]=c;
    }

    dijkstra();

    dfs(d);
    for(i=path.size()-1;i>0;i--){
        printf("%d",path[i]);
    }
    printf("%d %d",dis[d],minCost);

    return 0;
}
