#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<char,int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs){ //从小到大
    return lhs.second<rhs.second;
}

int main(){
    map<char,int> mp;
    string a,b;
    cout << a << b;
    int i=0, j=0;
    while(i<a.length() && j<b.length()){
        if(a[i]==b[j]){
            i++; j++;
        }
        if(a[i]!=b[j]){
            if('a'<=a[i]&&'z'>=a[i]){
                a[i] = a[i]-32;
            }
            if(mp.find(a[i])==map::end()){
                mp.insert(pair(a[i],i));
            }
            i++;
        }
    }
    while(i<a.length()){
        if(mp.find(a[i])==map::end()){
            mp.insert(make_pair(a[i],i));
        }
        i++;
    }

    vector<PAIR> sort_vector(mp.begin(),mp.end());
    sort(sort_vector.begin(),sort_vector.end(),cmp_by_value);

    for(int i=0; i<sort_vector.size;i++){
        cout << sort_vector[i].first;
    }
}