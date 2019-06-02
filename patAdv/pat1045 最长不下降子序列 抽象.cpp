// 抽象成 最长不下降子序列
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 1005;

int main(){
	int book[maxn];
	fill(book,book+maxn,-1);
	int d[maxn];
	int n,m;
	scanf("%d %d",&n,&m);
	int tmp;
	for(int i=0;i<m;i++){
		scanf("%d",&tmp);
		book[tmp]=i;
	}
	
	int l;scanf("%d",&l);
	vector<int> v;
	for(int i=0;i<l;i++){
		scanf("%d",&tmp);
		if(book[tmp]>-1) v.push_back(book[tmp]);
	}
	int max=0;
	for(int i=0;i<v.size();i++){
		d[i]=1;
		for(int j=0;j<i;j++){
			if(v[j]<=v[i] && d[j]+1>d[i]){
				d[i]=d[j]+1;
			}
		}
		if(d[i]>max) max=d[i];
	}
	printf("%d",max);
}
/*
CBPATOTAPCB
*/