#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 2e5+10;
string ans;
vector<pii> paths[mxn];
int fa[mxn];
int dep[mxn];
set<int> st;

void dfs(int now,int par){
	dep[now] = dep[par]+1;
	fa[now] = par;
	for(auto nxt:paths[now]){
		if(nxt.fs == par)continue;
		if(fa[nxt.fs]){
			st.insert(now);
			st.insert(nxt.fs);
			ans[nxt.sc] = '1';
			continue;
		}
		dfs(nxt.fs,now);
	}
	return;
}

void solve(int id){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back({b,i});
		paths[b].push_back({a,i});
	}
	ans = string(m,'0');
	dfs(1,1);
	int c = 0;
	for(auto &i:ans)if(i == '1')c++;
	assert(m != n+2||c == 3);
	if(m == n+2&&st.size()<=3){
		assert(st.size() == 3);
		int now = *st.rbegin();
		for(auto &i:st)if(dep[i]>dep[now])now = i;
		int tar = -1;
		int spare = -1;
		int nn = -1;
		assert(now<=n);
		for(auto nxt:paths[now]){
			assert(nxt.sc<m);
			if(ans[nxt.sc] == '1')tar = nxt.sc;
			else if(nxt.fs == fa[now])spare = nxt.sc;
		}
		assert(tar != spare);
		if(tar != -1&&spare != -1)swap(ans[spare],ans[tar]);
		else assert(false);
	}
	cout<<ans<<'\n';

	for(int i = 0;i<=n;i++){
		paths[i].clear();
		fa[i] = false;
	}
	ans.clear();
	st.clear();
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(int i = 1;i<=t;i++){
		solve(i);
	}
}
