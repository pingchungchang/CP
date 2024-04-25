#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	if(v[n-1]<v[n-2]){
		cout<<-1<<'\n';
		return;
	}
	vector<vector<int>> ans;
	for(int i = n-3;i>=0;i--){
		if(v[i]>v[i+1]){
			v[i] = v[i+1]-v[n-1];
			ans.push_back({i+1,i+2,n});	
		}
	}
	for(int i = 1;i<n;i++){
		if(v[i]<v[i-1]){
			cout<<-1<<'\n';
			return;
		}
	}
	cout<<ans.size()<<'\n';
	for(int i = 0;i<ans.size();i++){
		for(int j = 0;j<3;j++)cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}
