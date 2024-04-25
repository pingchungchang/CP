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

const int mxn = 2e5+10;
pll ans;
pll dp[mxn];
vector<pll> childs[mxn];
void dfs(int now,int par){
	for(auto nxt:childs[now]){
		if(dp[now].fs == LONG_LONG_MIN)dp[now].fs = 0;
		else dp[now].sc = 0;
		if(nxt.fs == par)continue;
		dfs(nxt.fs,now);
		ll tmp[4] = {dp[nxt.fs].fs+nxt.sc,dp[nxt.fs].sc+nxt.sc,dp[now].fs,dp[now].sc};
		if(tmp[0]+tmp[2]>ans.fs){
			swap(ans.fs,ans.sc);
			ans.fs = tmp[0]+tmp[2];
		}
		else if(tmp[0]+tmp[2]>ans.sc)ans.sc = tmp[0]+tmp[2];
		
		if(tmp[1]+tmp[2]>ans.sc)ans.sc = tmp[1]+tmp[2];
		if(tmp[0]+tmp[3]>ans.sc)ans.sc = tmp[0]+tmp[3];
		sort(tmp,tmp+4);
		dp[now] = {tmp[3],tmp[2]};
	}
	
//	cout<<now<<' '<<ans.fs<<','<<ans.sc<<' '<<dp[now].fs<<' '<<dp[now].sc<<endl;
	return;
}
int main(){
	io
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)dp[i] = {LONG_LONG_MIN,LONG_LONG_MIN};
	for(int i = 0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		childs[a].push_back({b,c});
		childs[b].push_back({a,c});
	}
	dfs(1,1);
	cout<<ans.sc;
}

