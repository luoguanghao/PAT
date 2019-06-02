#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

struct TNode{
	int weight;
	TNode *left, *right;
};
struct cmp{
	bool operator () (TNode * t1, TNode * t2){
		return t1->weight > t2->weight;
	}
};
map<char,int> Map;
priority_queue<TNode*,vector<TNode*>,cmp> a;
char tempA[70]; int w[70];
int n, codeLen;

int Wpl(TNode * T, int depth){
	if(!T->left&&!T->right){
		return depth*T->weight;
	}
	int lW = Wpl(T->left, depth+1);
	int rW = Wpl(T->right, depth+1);
	return lW+rW;
}

int Huffman(){
	TNode * node;
	while(a.size()!=1){
		node = (TNode*)malloc(sizeof(TNode));
		node->left=a.top(); a.pop();
		node->right=a.top(); a.pop();
		node->weight=node->left->weight+node->right->weight;
		a.push(node);
	}

	TNode * Tree = a.top(); a.pop();
	
	return Wpl(Tree,0);
}

void JudgeD(TNode * T, int& cnt0, int& cnt2){
    if(T){
        if(T->right&&T->left) cnt2++;
        else cnt0++;
        JudgeD(T->left,cnt0,cnt2);
        JudgeD(T->right,cnt0,cnt2);
    }
}

void Judge(){
	int m;
	cin >> m;
	char tmp, code[70];
	
	for(int i=0;i<m;i++){
		bool flag = true;  int sum = 0;
		TNode * Tree = (TNode*)malloc(sizeof(TNode));
		Tree->weight = 0;
		Tree->right = Tree->left = NULL;
		
		for(int v=0; v<n; v++){
			cin >> tmp >> code;
			
			if(strlen(code)>n) flag=false;
						
			int k;
			/*for(k=0;tmp!=tempA[k];k++);
			sum += int(strlen(code)) * w[k];*/
			sum += int(strlen(code)) * Map[tmp];
			//cout << '*' << sum << '\n';
			TNode * T = Tree;
			for(k=0; k<strlen(code); k++){
				
				if(code[k]=='0'){
					if(!T->left){
						T->left = (TNode*)malloc(sizeof(TNode));
						T->left->weight = 0;
						T->left->left = T->left->right = NULL;
					}
					T = T->left;
				}else if(code[k]=='1'){
					if(!T->right){
						T->right = (TNode*)malloc(sizeof(TNode));
						T->right->weight = 0;
						T->right->left = T->right->right = NULL;
					}
					T = T->right;
				}
				if(k+1==strlen(code)){
					if(T->left || T->right) flag=false;
				}				
				
			}
			
		}
		printf("sum:%d\n",sum);
        if(sum!=codeLen) flag=false;
        int cnt0=0, cnt2=0;
        JudgeD(Tree, cnt0, cnt2);
        if(cnt0 != cnt2+1) flag = false;
		
        if(flag){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }		
}

int main(){
	
	cin >> n;
	TNode * tempNode;
	char tempChar; int tempW;
	for(int i=0;i<n;i++){
		cin >> tempChar >> tempW;
		Map.insert(make_pair(tempChar, tempW));
		tempNode = (TNode*)malloc(sizeof(TNode));
		tempNode->right=tempNode->left=NULL;
		tempNode->weight=tempW;
		a.push(tempNode);
	}
	
	codeLen = Huffman();
		
	////Judge////////////////
	Judge();
		
		
	
	
	return 0;
}

/*Test
7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
1
A 00000
B 00001
C 0001
D 001
E 01
F 10
G 11

7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
1
A 00000
B 00001
C 0001
D 001
E 00
F 10
G 11

7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
1
A 000
B 001
C 010
D 011
E 100
F 101
G 110

7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
1
A 01010
B 01011
C 0100
D 011
E 10
F 11
G 00
*/