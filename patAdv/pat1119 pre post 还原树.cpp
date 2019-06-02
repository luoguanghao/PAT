#include <iostream>
using namespace std;
const int maxn = 30;
struct Node{
	int data;
	Node *left, *right;
};
int pre[maxn], post[maxn];
bool flag;
Node* BuildTree(int preL,int preR,int postL,int postR){
	Node *node = (Node*)malloc(sizeof(Node));
	if(preR==preL){	//单结点时左递归情况
		node->data=pre[preL];
		node->left=node->right=NULL;
	}else if(preR<preL){ //单结点时右递归
		node=NULL;
		flag=false;
	}else{		
		node->data = pre[preL];
		node->left=node->right=NULL;
		int i;
		for(i=postL;post[i]!=pre[preL+1];i++);
		node->left=BuildTree(preL+1, preL+i-postL+1, postL, i); //back see
		node->right=BuildTree(preL+i-postL+2, preR, i+1, postR-1);
	}
	return node;
}

int c;
void InOrderPrint(Node *node){
	if(node->left) InOrderPrint(node->left);
	if(c) printf(" ");
	printf("%d",node->data); c++;
	if(node->right) InOrderPrint(node->right);
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> pre[i];
	}
	for(int i=0;i<n;i++){
		cin >> post[i];
	}
	flag=true;
	Node * node = BuildTree(0,n-1,0,n-1);
	c=0;
	if(flag) printf("Yes\n");
	else printf("No\n");
	InOrderPrint(node);
	printf("\n");
	return 0;
}

/*
9
1 2 4 8 9 5 3 6 7
8 9 4 5 2 6 7 3 1
*/
/*
else if(preR-preL==1){
		flag=false;
		Node *node2 = (Node*)malloc(sizeof(Node));
		node2->data=pre[preR];
		node2->left=node2->right=NULL;
		node->left=NULL;
		node->data=pre[preL];
		node->right=node2;
	}
*/