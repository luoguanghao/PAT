#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Man{
	char name[4];
	int Height;
};
bool cmp(Man a,Man b){
    if(a.Height!=b.Height)
	    return a.Height<b.Height;
    else
        return 
}

int main(){
	Man manlist[10002];
	int n,k;
	cin >> n >> k;
	int numPerLine = n/k;
	for(int i=0;i<n;i++){
		cin >> manlist[i].name >> manlist[i].Height;
	}
	int numLastLine = numPerLine + n%k;
	sort(manlist,manlist+n,cmp);
	
	vector<Man> a;
	a.push_back(manlist[n-1]);
	int index = n-2;
	while(index>=n-numLastLine){
		a.insert(a.begin(),manlist[index]); index--;
		if(index>=n-numLastLine){
			a.insert(a.end(),manlist[index]); index--;
		}
	}
	for(int i=0;i<a.size();i++){
		printf("%s ",a[i].name);
	}
    printf("\n");
	for(int i=n-numLastLine-1; i>=0;i-=numPerLine){
        a.clear();
        a.push_back(manlist[i]);
        index = i-1;
        while(index>i-numPerLine){
            a.insert(a.begin(),manlist[index]); index--;
            if(index>i-numPerLine){
                a.insert(a.end(),manlist[index]); index--;
            }
        }
        for(int i=0;i<a.size();i++){
		    printf("%s ",a[i].name);
	    }
        printf("\n");
    }

    return 0;
}