#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	int l = 0,r = n-1;
	while(l != r){
		for(int i = 0;i<m;i++){
			if(l != r)l++;
		}
		for(int i = 0;i<m;i++){
			if(l != r)r--;
		}
	}
	cout<<arr[l];
}
