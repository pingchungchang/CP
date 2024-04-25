#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,kk;
	cin>>n>>kk;
	int arr[n+1];
	for(int i =1 ;i<=n;i++){
		int k;
		cin>>k;
		arr[k]  = i;
	}
	cout<<arr[kk];
}
