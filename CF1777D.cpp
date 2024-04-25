#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
const ll mod = 1e9+7;
vector<int> tree[mxn];
int n;
int dp[mxn];
ll ans = 0;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

void dfs(int now,int par){
	dp[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		dp[now] = max(dp[now],dp[nxt]+1);
	}
	ans += dp[now];
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)dp[i] = 0,tree[i].clear();
	ans = 0;
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	cout<<ans%mod*pw(2,n-1)%mod<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
