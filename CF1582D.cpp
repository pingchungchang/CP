#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	int ans[n] = {};
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 1;i<n;i+=2){
		ans[i] = arr[i-1];
		ans[i-1] = -arr[i];
	}
	if(ans[n-1] == 0){
		ans[n-1] = arr[0];
		ans[0]-=arr[n-1];
		if(ans[0] == 0){
			ans[n-1]+=arr[0];
			ans[0] -= arr[n-1];
		}
	}
	for(auto i:ans)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
