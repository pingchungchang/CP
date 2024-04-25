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

const int mxn = 1e6+10;
vector<pll> paths[mxn];
ll ans = 0;
ll dfs(int now,int par){
	ll d1 = 0,d2 = 0;
	for(auto nxt:paths[now]){
		if(nxt.fs == par)continue;
		ll k = dfs(nxt.fs,now)+nxt.sc;
		if(d1<k){
			swap(d1,d2);
			d1 = k;
		}
		else if(d2<k)d2 = k;
	}
	ans = max(ans,d2+d1);
	return d1;
	
}
int main(){
	io
	int n;
	cin>>n;
	for(int i = 0;i<n-1;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		paths[b].push_back({a,c});
	}
	dfs(1,1);
	cout<<ans;
}

