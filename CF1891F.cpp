#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 1e6+10;
ll bit[mxn],ans[mxn];
int cnt = 0;
pii dfn[mxn],req[mxn];
vector<int> tree[mxn];
int q;

void modify(int p,int v){
	for(;p<=q;p+=p&-p){
		bit[p] += v;
	}
	return;
}
ll getval(int p){
	ll re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

void dfs(int now){
	dfn[now].fs = ++cnt;
	for(auto nxt:tree[now]){
		dfs(nxt);
	}
	dfn[now].sc = cnt;
}

void solve(){
	for(int i = 1;i<=max(q,cnt);i++){
		modify(i,-getval(i));
		cnt = ans[i] = dfn[i].fs = dfn[i].sc = req[i].fs = req[i].sc = 0;
		tree[i].clear();
	}
	cin>>q;
	int C = 1;
	req[0] = {-1,1};
	for(int i = 1;i<=q;i++){
		int tp;
		cin>>tp;
		if(tp == 1){
			int p;
			cin>>p;
			tree[p].push_back(++C);
			req[i] = {-1,C};
		}
		else cin>>req[i].fs>>req[i].sc;
	}
	dfs(1);
	/*
	for(int i = 1;i<=C;i++)cout<<dfn[i].fs<<' ';cout<<"\n";
	for(int i = 1;i<=C;i++)cout<<dfn[i].sc<<' ';cout<<'\n';

   */
	for(int i = q;i>=0;i--){
		if(req[i].fs == -1){
			ans[req[i].sc] = getval(dfn[req[i].sc].fs);
		}
		else{
			ll p = req[i].fs,v = req[i].sc;
			modify(dfn[p].fs,v);
			modify(dfn[p].sc+1,-v);
		}
	}
	for(int i = 1;i<=C;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
