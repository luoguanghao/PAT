#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 999999;
int cmax,n,sp,m;
int minNeed=inf, minBack=inf;
int mapdis[510][510], dis[510], weight[510], visited[510];
vector<int> pre[510];
vector<int> path, temppath;

void Dfs(int v){
    int id,i;
    temppath.push_back(v);
    if(v==0){
        int need=0, back=0;
        for(i=temppath.size()-1; i>=0; i--){
            id=temppath[i];
            if(weight[id]>0){
                back+=weight[id];
            }else{
                if(back-(0-weight[id])>0){
                    back+=weight[id]-need;
                    need=0;
                ///体会此处为何不用need=0
                }else{
                    need+=((0-weight[id])-back);
                    back=0;
                }
            }
        }
        if(need<minNeed){
            minNeed=need;
            minBack=back;
            path=temppath;
        }else if(need==minNeed && back<minBack){
            minBack=back;
            path=temppath;
        }
        temppath.pop_back();
        return;
    }
    for(i=0; i<pre[v].size(); i++)
        Dfs(pre[v][i]);
    temppath.pop_back();
}

void Dijkstra(){
    int i,j;
    
    for(i=0;i<=n;i++){
        visited[i]=0;
    }
    dis[0]=0;

    int minD,minV;
    for(i=0;i<n;i++){
        minD=inf;
        for(j=0;j<=n;j++){
            if(dis[j]<minD && !visited[j]){
                minD=dis[j]; minV=j;
            }
        }
        if(minD==inf) break;
        visited[minV]=1;

        for(j=0;j<=n;j++){
            if(dis[j]>dis[minV]+mapdis[minV][j] && !visited[j]){
                dis[j]=dis[minV]+mapdis[minV][j];
                pre[j].clear();
                pre[j].push_back(minV);
            }else if(dis[j]==dis[minV]+mapdis[minV][j] && !visited[j]){
                pre[j].push_back(minV);
            }
        }
    }
}

int main(){
    int i,j;
    scanf("%d %d %d %d",&cmax,&n,&sp,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&weight[i]);
        weight[i]=weight[i]-cmax/2;
    }
    int v1,v2,w;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
            mapdis[i][j]=inf;
        dis[i]=inf;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        mapdis[v1][v2]=mapdis[v2][v1]=w;
    }

    Dijkstra();

    Dfs(sp);

    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    

    return 0;
}