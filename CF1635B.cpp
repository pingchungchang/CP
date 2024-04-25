#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int ans =0;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = 1;i<n-1;i++){
		if(v[i]>v[i+1]&&v[i]>v[i-1]){
			v[i+1] = v[i];
			if(i != n-2)v[i+1] = max(v[i+1],v[i+2]);
			ans++;
		}
	}
	cout<<ans<<'\n';
	for(auto i:v)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
