#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr){
		cin>>i;
		if(i == 1)i++;
	}
	for(int i = 1;i<n;i++){
		if(arr[i]%arr[i-1] == 0)arr[i]++;
	}
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
