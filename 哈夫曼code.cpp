#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int maxn = 70;

struct Map{
    char a;
    int weight;
    friend bool operator < (Map map1, Map map2){ //只需重载'<'
        return map1.weight > map2.weight;
    }
};

struct TNode{
    int weight;
    TNode *left, *right;
};


int main(){
    int n;
    cin >> n;
    priority_queue<
    for(int i=0; i<n; i++){

    }
}