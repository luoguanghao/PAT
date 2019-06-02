#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 101;

int n;
int layer = 0,maxLayer=0;
string pre,mid;
struct Node{
	char data;
	
	Node * left;
	Node * right;
};

Node * BuildTree(int preL,int preR, int midL,int midR){
	if(preL>preR){
		if(layer>maxLayer) maxLayer=layer;
		return NULL; //????
	}
	Node* node = new Node;
	node->data = pre[preL];
	layer++;
	
	int i,index=0;
	for(i=midL;i<n;i++){
		if(mid[i]==pre[preL]) break;
		index++;
	}
	node->left = BuildTree(preL+1,preL+index,midL,i-1);
	node->right = BuildTree(preL+index+1,preR,i+1,midR);
	layer--;
	return node;
}

void PrintPostT(Node * node){
	printf("%c ",node->data);
	if(node->left) PrintPostT(node->left);
	if(node->right) PrintPostT(node->right);
	
}

int getHight(Node * node){
	if(node==NULL){
		return 0;
	}
	int highL = getHight(node->left);
	int highR = getHight(node->right);
	int highT = highL>highR?highL:highR;
	highT++;
	return highT;
}

int main(){

	cin >> n;
	cin >> pre >> mid;

	Node * Tree = BuildTree(0,n-1,0,n-1);

	printf("%d\n",getHight(Tree));
	//PrintPostT(Tree);
	//printf("\nlayer %d",maxLayer);
	return 0;
}
/*
ABDFGHIEC
FDHGIBEAC
*/