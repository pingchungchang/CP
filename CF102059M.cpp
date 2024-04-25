#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
vector<int> eul;
int n,tar;
vector<pii> tree[mxn];
int par[mxn];
pll dp[mxn][2];

void dfs(int now){
	eul.push_back(now);
	for(auto nxt:tree[now]){
		if(nxt.fs == par[now])continue;
		par[nxt.fs] = now;
		dfs(nxt.fs);
	}
	return;
}

inline pll calc(ll p){
	for(int i = 0;i<=n;i++)dp[i][0] = dp[i][1] = make_pair(0,0);
	for(int i = eul.size()-1;i>=0;i--){
		int now = eul[i];
		pll tmp = make_pair(0,0);
		for(auto nxt:tree[now]){
			if(nxt.fs == par[now])continue;
			pll big = max(dp[nxt.fs][0],dp[nxt.fs][1]);
			tmp.fs += big.fs,tmp.sc += big.sc;
		}
		dp[now][1] = dp[now][0] = tmp;
		for(auto nxt:tree[now]){
			if(nxt.fs == par[now])continue;
			pll tsum = tmp;
			pll big = max(dp[nxt.fs][0],dp[nxt.fs][1]);
			tsum.fs -= big.fs,tsum.sc -= big.sc;
			tsum.fs += dp[nxt.fs][0].fs,tsum.sc += dp[nxt.fs][0].sc;
			tsum.fs += nxt.sc-p,tsum.sc++;
			dp[now][1] = max(dp[now][1],tsum);
		}
	}
	//for(int i = 1;i<=n;i++)cout<<dp[i][0].fs<<','<<dp[i][1].fs<<' ';cout<<'\n';
	return max(dp[1][0],dp[1][1]);
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>tar;
	for(int i = 1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	dfs(1);
	ll l = -1e12,r = 1e12;
	pll tmp = calc(-r);
	if(tmp.sc<tar){
		cout<<"Impossible";
		return 0;
	}
	while(l != r){
		ll mid = l+(r-l+1)/2;
		pll re = calc(mid);
		//cout<<mid<<":"<<re.fs<<' '<<re.sc<<'\n';
		if(re.sc>=tar)l = mid;
		else r = mid-1;
	}
	auto re = calc(l);
	cout<<re.fs+l*tar;
}
