#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll

const ll mod = 1e9+7;
const int mxn = 1e5+10;
vector<int> tree[mxn];
vector<ll> primes;
int n;
ll sz[mxn];
vector<ll> v;

void dfs1(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs1(nxt,now);
		sz[now] += sz[nxt];
	}
	if(now == par)return;
	v.push_back(1LL*(n-sz[now])*sz[now]);
}

void solve(){
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		sz[i] = 0;
	}
	primes.clear();
	v.clear();
	cin>>n;
	for(int i= 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int m;
	cin>>m;
	while(m--){
		int p;
		cin>>p;
		primes.push_back(p);
	}

	dfs1(1,1);

	sort(primes.rbegin(),primes.rend());
	sort(v.rbegin(),v.rend());
	while(primes.size()<v.size())primes.push_back(1);
	if(primes.size()>n-1){
		ll pp = 1;
		int ps = primes.size();
		reverse(primes.begin(),primes.end());
		for(int i = 0;i<ps-n+2;i++){
			pp = pp*primes.back()%mod;
			primes.pop_back();
		}
		primes.push_back(pp);
		reverse(primes.begin(),primes.end());
	}
	//for(auto &i:primes)cout<<i<<',';cout<<'\n';
	ll ans = 0;
	assert(v.size() == n-1);
	for(int i = 0;i<v.size();i++){
		ans = (ans+v[i]%mod*primes[i]%mod)%mod;
	}
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
