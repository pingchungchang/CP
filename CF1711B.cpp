#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll> v(n+1,0),cnt(n+1,0);
	vector<vector<int>> paths(n+1);
	for(int i = 1;i<=n;i++)cin>>v[i];
	for(int i = 0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
		cnt[a]++;cnt[b]++;
	}
	if(m%2 == 0){
		cout<<0<<'\n';
		return;
	}
	ll total = 0;
	for(int i = 1;i<=n;i++)total += v[i];
	for(int i = 1;i<=n;i++){
		if((m-cnt[i])%2 == 0){
			total = min(total,v[i]);
		}
		for(auto nxt:paths[i]){
			if((m-cnt[nxt]-cnt[i]+1)%2 == 0){
				total = min(total,v[i]+v[nxt]);
			}
		}
	}
	cout<<total	<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

