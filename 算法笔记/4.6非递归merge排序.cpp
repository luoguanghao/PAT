#include<stdio.h>
#include<stdlib.h>

#define maxn 101

int min(int a, int b){
	return a<b?a:b;
}

void merge(int A[],int L1, int R1, int L2, int R2){
	int i=L1, j=L2, index = 0, temp[maxn];
	while(i<=R1 && j<=R2){
		if(A[i]<=A[j]){
			temp[index]=A[i];
			index++; i++;
		}else{
			temp[index]=A[j];
			index++; j++;
		}
	}
	while(i<=R1){
		temp[index]=A[i];
		index++; i++;
	}
	while(j<=R2){
		temp[index]=A[j];
		index++; j++;
	}
	for(i=0;i<index;i++){
		A[L1+i]=temp[i];
	}
}

void mergeSort(int A[],int n){
	int step,mid;
	for(step=2; step/2<n; step*=2){
		for(int i=0; i<n; i+=step){
			mid=i + step/2 -1;
			if(mid+1<n){
				merge(A, i, mid, mid+1, min(i+step-1,n-1));
			}
		}
	}
}

int main(){
	int n,i;
	int A[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	mergeSort(A,n);

	for(i=0;i<n;i++){
		printf("%d",A[i]);
	}
	return 0;
}
