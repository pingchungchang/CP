#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;
const int mxn = 2e5+10;
vector<int> tree[mxn];
ll dp[mxn],sz[mxn];

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}

inline ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}

void dfs1(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs1(nxt,now);
		dp[now] += dp[nxt]+sz[nxt];
		sz[now] += sz[nxt];
	}
	return;
}
void dfs2(int now,int par){
	//cout<<par<<":"<<now<<":"<<sz[par]<<":"<<sz[now]<<endl;
	if(now != par){
		dp[now] = dp[par]-dp[now]-sz[now]+(sz[par]-sz[now])+dp[now];
		sz[now] = sz[par];
	}
	for(auto nxt:tree[now]){
		//cout<<now<<":"<<nxt<<endl;
		if(nxt == par)continue;
		dfs2(nxt,now);
	}
	return;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	if(k == 1||k == 3){
		cout<<1<<'\n';
		return;
	}
	dfs1(1,1);
	dfs2(1,1);
	//for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
	ll total = 0;
	for(int i = 1;i<=n;i++)total = mad(total,dp[i]%mod);
	total = mad(total*inv(2)%mod,n*(n-1)/2%mod);
	//cout<<total<<endl;
	total = total * inv(n*(n-1)/2%mod)%mod;
	cout<<total<<'\n';;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
