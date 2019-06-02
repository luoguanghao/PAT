#include <iostream>
#include <queue>
using namespace std;
int m,n,l,t;
int movM[6]={1,-1,0,0,0,0};
int movN[6]={0,0,1,-1,0,0};
int movL[6]={0,0,0,0,1,-1};
//int nowX,nowY,nowZ;
int Graph[1300][130][65];
int visited[1300][130][65]={0};

int cnt=0, tmpcnt=0;

int isValid(int indxM,int indxN,int indxL){
	if(0<=indxM&&indxM<m
		&& 0<=indxN&&indxN<n
		&& 0<=indxL&&indxL<l)
		return 1;
		
	return 0;
}

void DFS(int indxM,int indxN,int indxL){
	
	if(!isValid(indxM, indxN, indxL)) return;
	if(!visited[indxM][indxN][indxL]&&Graph[indxM][indxN][indxL]){
		printf("** %d %d %d\n",indxM, indxN, indxL);
		tmpcnt++;
		visited[indxM][indxN][indxL]=1;
	}else{
		return;
	}
	for(int i=0;i<6;i++){
		int nowM = indxM+movM[i];
		int nowN = indxN+movN[i];
		int nowL = indxL+movL[i];
		DFS(nowM, nowN, nowL);
	}
}

int main(int argc, char *argv[]) {
	
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(int indxL=0;indxL<l;indxL++){
		for(int indxM=0;indxM<m;indxM++){
			for(int indxN=0;indxN<n;indxN++){
				scanf("%d",&Graph[indxM][indxN][indxL]);
			}
		}
	}
	
	for(int indxL=0;indxL<l;indxL++){
		for(int indxM=0;indxM<m;indxM++){
			for(int indxN=0;indxN<n;indxN++){
				tmpcnt=0;
				DFS(indxM,indxN,indxL);
				printf("....&&%d\n",tmpcnt);
				if(tmpcnt>=t) cnt+=tmpcnt;
			}
		}
	}
	
	printf("%d",cnt);
	
}
/*
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
*/