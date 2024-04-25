#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll> vals;
const ll mod = 998244353;
bool check(){
	for(auto &i:vals)if(i != 0)return true;
	return false;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vals = vector<ll> (n+1,0LL);
	for(int i = 1;i<=n;i++)cin>>vals[i];
	vector<ll> deg(n+1,0);
	vector<vector<ll>> paths(n+1);
	for(int i = 0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		deg[b]++;
	}
	queue<int> qv;
	for(int i = 1;i<=n;i++)if(vals[i] != 0)qv.push(i);
	for(int i = 1;i<=n;i++){
		if(qv.empty()){
			cout<<i-1<<'\n';
			return;
		}
		while(!qv.empty()){
			auto tmp = qv.front();
			qv.pop();
			vals[tmp]--;
			for(auto nxt:paths[tmp])vals[nxt]++;
		}
		for(int j = 1;j<=n;j++){
			if(vals[j] != 0)qv.push(j);
		}
	}
	queue<ll> q;
	for(int i =1;i<=n;i++){
		if(deg[i] == 0)q.push(i);
	}
	ll ans = 0;
	ll dp[n+1];
	memset(dp,0LL,sizeof(dp));
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		dp[now] += vals[now];
		for(auto nxt:paths[now]){
			dp[nxt] += dp[now];
			dp[nxt] %= mod;
			deg[nxt]--;
			if(deg[nxt] == 0)q.push(nxt);
		}
	}
	for(int i = 1;i<=n;i++){
//		cout<<dp[i]<<',';
		if(paths[i].size() == 0){
			cout<<(dp[i]+n)%mod<<'\n';
			return;
		}
	}
	
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

