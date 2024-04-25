#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


struct Edge{
	int c,w,to;
	Edge(int b,int cc,int d){
		to = b,w = cc,c = d;
	}
	Edge(){}
};
const int mxn = 1e5+10;
vector<Edge> tree[mxn];
int n,dp[mxn];
ll S;
vector<ll> dx[3];
ll total = 0;

void dfs(int now,int par,Edge pre){
	bool leaf = true;
	for(auto nxt:tree[now]){
		if(nxt.to == par)continue;
		leaf = false;
		dfs(nxt.to,now,nxt);
		dp[now] += dp[nxt.to];
	}
	if(now == par)return;
	if(leaf)dp[now]++;
	total += 1LL*dp[now]*pre.w;
	while(pre.w>0){
		ll d = pre.w-pre.w/2;
		dx[pre.c].push_back(d*dp[now]);
		pre.w /= 2;
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		dp[i] = 0;
	}
	total = 0;
	dx[0].clear();dx[1].clear();dx[2].clear();
	cin>>n>>S;
	for(int i = 1;i<n;i++){
		int a,b,c,d = 1;
		cin>>a>>b>>c>>d;
		tree[a].push_back(Edge(b,c,d));
		tree[b].push_back(Edge(a,c,d));
	}
	dfs(1,1,Edge());
	for(auto &i:dx)sort(i.rbegin(),i.rend());
	ll ans = 1e9;
	for(int i = 1;i<=2;i++){
		ll tans = 0,tmp = total;
		for(auto &j:dx[i]){
			if(tmp<=S)break;
			tans += i;
			tmp -= j;
		}
		if(tmp<=S)ans = min(ans,tans);
	}
	int pt = dx[1].size();
	pt--;
	ll tmp = total,tans = 0;
	for(auto &i:dx[1])tmp -= i;
	for(int i = 0;i<dx[2].size();i++){
		tmp -= dx[2][i];
		while(pt>=0&&tmp+dx[1][pt]<=S){
			tmp += dx[1][pt];
			pt--;
		}
		if(tmp>S)continue;
		ans = min(ans,2LL*(i+1)+pt+1);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
