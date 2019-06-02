#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int p;
    long long n;
    int temp;
    vector<int> v;
    scanf("%ld %d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int result=0;
    for(int i=0; i<n; i++){
        for(j=i+result; j<n; j++){
            if(v[i]*p>=v[j]){
                if(j-i+1>result){
                    result=j-i+1;
                }
            }else{
                break;
            }
        }
    }
    cout << result;

    return 0;
}