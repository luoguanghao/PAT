#include <iostream>
using namespace std;

struct Node{
	int data;
	int high;
	Node * left;
	Node * right;
};

int getHeight(Node * node){
	if(node==NULL) return 0;
	int highL = getHeight(node->left);
	int highR = getHeight(node->right);
	int highT = highL>highR?highL:highR;
	highT++;
	return highT;
}

int getBalanceInfector(Node * node){
	return getHeight(node->left)-getHeight(node->right);
}

void R(Node * &node){
	Node * temp = node->left;
	node->left = temp->right;
	temp->right = node;
	node = temp;
}

void L(Node * &node){
	Node * temp = node->right;
	node->right = temp->left;
	temp->left = node;
	node = temp;
}

void Insert(Node * &node, int data){
	if(node==NULL){
		node = new Node;
		node->data = data;
		node->high = 1;
		node->right = node->left = NULL;
		return ;
	}
	
	if(data<node->data){
		Insert(node->left,data);
		if(getBalanceInfector(node) ==2){
			if(getBalanceInfector(node->left)==1){
				R(node);
			}else if(getBalanceInfector(node->left)==-1){
				L(node->left);
				R(node);
			}
		}
	}else{
		Insert(node->right,data);
		if(getBalanceInfector(node) ==-2){
			if(getBalanceInfector(node->right)==1){
				R(node->right);
				L(node);
			}else if(getBalanceInfector(node->right)==-1){
				L(node);
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	int temp;

	Node * Tree = NULL;
	for(int i=0;i<n;i++){
		cin >> temp;
		Insert(Tree,temp);
	}

	printf("%d",Tree->data);

	return 0;

}