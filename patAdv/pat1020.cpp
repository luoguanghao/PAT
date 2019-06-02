#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
};

int n;
int post[32], mid[32];

node * buildTree(int postL, int postR, int midL, int midR){
    if(postL>postR){
        return NULL;
    }
    node * root = new node;
    root->data = post[postR];
    int i;
    for(i=midL;i<=midR;i++){
        if(mid[i]==post[postR]);
            break;
    }
    root->left = buildTree(postL,i-1,midL,i-1);
    root->right = buildTree(i,postR-1,i+1,midR);

    return root;
}

void BFS(node * root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node * top = q.front();
        q.pop();
        printf("%d ",top->data);
        if(top->left!=NULL)
            q.push(top->left);
        if(top->right!=NULL)
            q.push(top->right);
        
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",mid[i]);
    }

    node * root = buildTree(0,n-1,0,n-1);

}