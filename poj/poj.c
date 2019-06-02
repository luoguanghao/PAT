#include<stdio.h>
#include<stdlib.h>
#define maxe 2500*2+200+10
#define maxn 510
#define inf 999999
typedef struct{
    int s,e;
    int t;
}EdgeType;

EdgeType edge[maxe];
int dest[maxn];
int n,m,w;

int bellman_ford(){
    int i,j;
    for(i=1;i<=n;i++){
        dest[i]=inf;
    }
    dest[1]=0;

    for(i=1;i<n;i++){
        int flag=1;
        for(j=0;j<m;j++){
            if(dest[edge[j].s]+edge[j].t<dest[edge[j].e]){
                dest[edge[j].e]=dest[edge[j].s]+edge[j].t;
                flag=0;
            }
        }
        if(flag) return 0;
    }

    for(j=0;j<m;j++){
        if(dest[edge[j].s]+edge[j].t<dest[edge[j].e])
            return 1;
    }
    return 0;
}

int main(){
    int T,i;
    int s,e,t;
    scanf("%d",&T);
    
    while(T--){
        int c=0;
        scanf("%d %d %d",&n,&m,&w);

        for(i=0;i<m;i++){
            scanf("%d %d %d",&s,&e,&t);
            edge[c].s=s; edge[c].e=e; edge[c++].t=t;
            edge[c].e=s; edge[c].s=e; edge[c++].t=t;//双向
        }

        for(i=0;i<w;i++){
            scanf("%d %d %d",&s,&e,&t);
            edge[c].s=s; edge[c].e=e; edge[c++].t=-t;
        }

        int flag=bellman_ford();
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        
    }

    
    
    return 0;
}