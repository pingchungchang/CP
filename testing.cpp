#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

namespace HLD{
	int idx[mxn],sz[mxn],bs[mxn],dep[mxn],par[mxn],link_top[mxn],cnt;
	void dfs1(int now){
		for(auto nxt:tree[now]){
			if(nxt == par[now])continue;
			par[nxt] = now;
			dep[nxt] = dep[now]+1;
			dfs1(nxt,now);
			if(!bs[now]||sz[bs[now]]<sz[nxt])bs[now] = nxt;
		}
		return;
	}
	void dfs2(int now,int top){
		idx[now] = ++cnt;
		link_top[now] = top;
		if(bs[now])dfs2(bs[now],top);
		for(auto nxt:tree[now]){
			if(nxt == par[now]||nxt == bs[now])continue;
			dfs2(nxt,nxt);
		}
		return;
	}
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
