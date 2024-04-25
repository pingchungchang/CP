#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		ans = (ans|k);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
