#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> v(n+1,vector<ll>(m,0));
	for(ll i = 1;i<=n;i++){
		for(auto &j:v[i])cin>>j;
	}
	map<ll,vector<ll>> mp;
	vector<ll> vals(n+1,0);
	for(ll i = 1;i<=n;i++){
		for(ll j = 0;j<m;j++)vals[i] += (j+1)*v[i][j];
		mp[vals[i]].push_back(i);
	}
	if(mp.begin()->sc.size() == 1){
		cout<<mp.begin()->sc[0]<<' ';
	}
	else cout<<mp.rbegin()->sc[0]<<" ";
	cout<<abs(mp.begin()->fs-mp.rbegin()->fs)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

