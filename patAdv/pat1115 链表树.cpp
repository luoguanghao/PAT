///g++ 段错误///
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node *left, *right;	
};

Node* Insert(int v, Node *node){
	if(!node){
		node = (Node*)malloc(sizeof(Node));
		node->left=node->right=NULL;
		node->data = v;
	}else{
		if(v<=node->data){
			node->left=Insert(v, node->left);
		}else if(v>node->data){
			node->right=Insert(v, node->right);
		}
	}
	return node;
}


void Count_BFS(Node *node){
	int countA, countB; countA=0;
	int mark, tmpmark;
	vector<int> result;
	queue<Node*> q;
	q.push(node);
	mark=node->data;
	while(q.size()!=0){
		Node *top=q.front(); q.pop();countA++;
		if(top->left){q.push(top->left); tmpmark=top->left->data;}
		if(top->right){q.push(top->right); tmpmark=top->right->data;}
		if(top->data==mark){
			result.push_back(countA);		
			mark=tmpmark;
			countA=0;
		}
	}
	
	printf("%d + %d = %d",result[result.size()-1],result[result.size()-2],
		result[result.size()-1]+result[result.size()-2]);
}

int main(){
	int n;
	cin >> n;
	int tmp;
	Node *node;
	for(int i=0;i<n;i++){
		cin >> tmp;
		node = Insert(tmp,node);
	}
	
	Count_BFS(node);
	return 0;
}