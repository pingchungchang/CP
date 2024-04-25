#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5050;
vector<pii> tree[mxn];
pii par[mxn];
int dep[mxn];
int ans[mxn];
int n,q;
bool flag;

void dfs(int now){
	for(auto nxt:tree[now]){
		if(nxt.fs == par[now].fs)continue;
		dep[nxt.fs] = dep[now]+1;
		par[nxt.fs] = {now,nxt.sc};
		dfs(nxt.fs);
	}
	return;
}

inline void color(int a,int b,int c){
	while(a != b){
		if(dep[a]<dep[b])swap(a,b);
		ans[par[a].sc] = c;
		a = par[a].fs;
	}
	return;
}

inline void check(int a,int b,int c){
	int small = 1e9;
	while(a != b){
		if(dep[a]<dep[b])swap(a,b);
		small = min(small,ans[par[a].sc]);
		a = par[a].fs;
	}
	if(small != c)flag = false;
	return;
	ans[a] = c;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back({b,i});
		tree[b].push_back({a,i});
	}
	par[1] = {0,0};
	dfs(1);
	vector<tuple<int,int,int>> req;
	fill(ans,ans+n,1);
	cin>>q;
	for(int i = 0;i<q;i++){
		int a,b,c;
		cin>>a>>b>>c;
		req.push_back(make_tuple(c,a,b));
	}
	sort(req.begin(),req.end());
	for(auto &i:req){
		color(get<1>(i),get<2>(i),get<0>(i));
	}
	flag = true;
	for(auto &i:req){
		check(get<1>(i),get<2>(i),get<0>(i));
	}
	if(flag)for(int i = 1;i<n;i++)cout<<ans[i]<<' ';
	else cout<<"-1";
	return 0;
}
