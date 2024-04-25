#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
vector<pii> tree[mxn];
int dp[mxn],dep[mxn];
int n;

void dfs(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		dp[nxt.fs] = dp[now]^nxt.sc;
		dfs(nxt.fs,now);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i =1 ;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	dfs(1,1);
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<(dp[a]^dp[b])<<'\n';
	}
	return 0;
}
