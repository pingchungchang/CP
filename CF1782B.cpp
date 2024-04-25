#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int ans = 1;
	for(int i = 0;i<n-1;i++){
		if(i>=arr[i]&&arr[i+1]>i+1)ans++;
	}
	if(arr[0] != 0)ans++;
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
