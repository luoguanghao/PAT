#include <iostream>
#include <cmath>
using namespace std;
int data[1001][1001];
int tmpData[1001][1001];
int n;

int Solve(int i,int j){
	if(i==n){
		tmpData[i][j]=data[i][j];
		return tmpData[i][j];
	}
	tmpData[i][j]=max(Solve(i+1, j),Solve(i+1, j+1))+data[i][j];
	return tmpData[i][j];
}

int main(int argc, char *argv[]) {
	fill(data[0],data[0]+1000*1000,0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin >> data[i][j];
		}
	}
	Solve(1, 1);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			printf("%d ",tmpData[i][j]);
		}
		printf("\n");
	}
	//printf("%d",Solve(1,1));
	
}

/*
5
5
8 3
12 7 16
4 10 11 6
9 5 3 9 4
*/