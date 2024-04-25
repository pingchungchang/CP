#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5e5+10;
map<vector<int>,ll> mp[mxn];
vector<int> paths[mxn];
int n,m;

void solve(){
	for(int i = 0;i<=n;i++)mp[i].clear();
	for(int i = 0;i<=n;i++)paths[i].clear();
	cin>>n>>m;
	ll arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		sort(paths[i].begin(),paths[i].end());
		if(paths[i].empty())continue;
		mp[paths[i].size()][paths[i]]+=arr[i];
	}
	ll G = 0;
	for(int i = 1;i<=n;i++){
		for(auto &j:mp[i])G = __gcd(G,j.sc);
	}
	cout<<G<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
