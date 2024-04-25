#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
vector<pii> paths[mxn];
bitset<mxn> vis;
pii ans[mxn];
int dp[mxn];

int dfs(int now,int par){
	vis[now] = true;
	for(auto nxt:paths[now]){
		if(nxt.fs == par)continue;
		if(vis[nxt.fs]){
			dp[nxt.fs] ^= 1,ans[nxt.sc] = {now,nxt.fs};
			continue;
		}
		if(!dfs(nxt.fs,now)){
			dp[now] ^= 1;
			ans[nxt.sc] = {now,nxt.fs};
		}
		else ans[nxt.sc] = {nxt.fs,now};
	}
	return dp[now];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back({b,i});
		paths[b].push_back({a,i});
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			if(dfs(i,i)){
				cout<<"IMPOSSIBLE";
				return 0;
			}
		}
	}
	for(int i = 0;i<m;i++)cout<<ans[i].fs<<' '<<ans[i].sc<<'\n';
}
