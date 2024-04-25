#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>

const int mxn = 1e5+10;
set<int> st[mxn];
vector<int> tree[mxn];
vector<tiii> req[mxn];
int n,q;
bitset<mxn> ans;

void dfs(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		if(st[now].size()<st[nxt].size())swap(st[now],st[nxt]);
		while(!st[nxt].empty()){
			st[now].insert(*st[nxt].begin());
			st[nxt].erase(st[nxt].begin());
		}
	}
	while(req[now].size()){
		auto tmp = req[now].back();
		req[now].pop_back();
		auto lit = st[now].lower_bound(get<0>(tmp));
		auto rit = st[now].upper_bound(get<1>(tmp));
		if(lit != rit)ans[get<2>(tmp)] = true;
	}
	return;
}

void solve(){
	for(int i = 0;i<=q;i++)ans[i] = false;
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		req[i].clear();
		st[i].clear();
	}
	cin>>n>>q;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		st[k].insert(i);
	}
	for(int i = 1;i<=q;i++){
		int l,r,x;
		cin>>l>>r>>x;
		req[x].push_back(make_tuple(l,r,i));
	}
	dfs(1,1);
	for(int i = 1;i<=q;i++){
		cout<<(ans[i]?"YES\n":"NO\n");
	}
	cout<<"\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
