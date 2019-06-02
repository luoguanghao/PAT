#include <iostream>
#include <cmath>
#include <algorithm>
using namespace	std;
const int maxn = 1005;
struct Node{
	int data;
	Node *left, *right;
};
int n, data[maxn];

Node* BuildTree(int L,int R){
	Node *node = (Node*)malloc(sizeof(Node));
	if(R-L==0){
		node->data = data[L];
		node->left = node->right = NULL;
	}else if(R-L==1){
		Node *node2 = (Node*)malloc(sizeof(Node));
		node2->left = node2->right = NULL;
		node2->data = data[L];

		node->data = data[R];
		node->left = node2; node->right=NULL;
	}else{
		int size=R-L+1;
		int layer=int(log2(double(size)))+1;
		int lNum=(pow(2,layer-1)-2)/2; int rNum=lNum;
		int lastLine = size-pow(2,layer-1)+1;
		int lastLineVol = pow(2,layer-1);
		if(lastLine>lastLineVol/2){
			lNum += lastLineVol/2; rNum += (lastLine-lastLineVol/2);
		}else{
			lNum += lastLine;
		}
		
		//node->left = node->right = NULL;
		node->data = data[L+lNum];
		node->left = BuildTree(L, L+lNum-1);
		node->right = BuildTree(L+lNum+1, R);
	}
	return node;
}

int main(){
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> data[i];
	}
	sort(data,data+n);	
	Node *node;
	node = BuildTree(0,n-1);
	
}