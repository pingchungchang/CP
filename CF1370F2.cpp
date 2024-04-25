#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
int sz[mxn],del[mxn],dep[mxn];
vector<int> tree[mxn];
int n,md;
pii ans;

inline pii ask(vector<int> &v){
	cout<<"? "<<v.size()<<' ';
	for(auto &i:v)cout<<i<<' ';cout<<endl;
	pii re;
	cin>>re.fs;
	if(re.fs == -1)exit(0);
	cin>>re.sc;
	return re;
}

void szdfs(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		szdfs(nxt,now);
		sz[now] += sz[nxt];
	}
	return;
}

int find_cen(int now,int par,int tar){
	for(auto nxt:tree[now]){
		if(del[nxt]||nxt == par)continue;
		if(sz[nxt]>tar)return find_cen(nxt,now,tar);
	}
	return now;
}

void cendfs(int now){
	szdfs(now,now);
	if(sz[now] == 1){
		ans.fs = now;
		return;
	}
	now = find_cen(now,now,(sz[now]-1)/2);
	vector<int> v;
	for(auto nxt:tree[now]){
		if(del[nxt])continue;
		v.push_back(nxt);
	}
	pii re = ask(v);
	md = min(md,re.sc);
	del[now] = true;
	cendfs(re.fs);
}

void dfs2(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs2(nxt,now);
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++){
		del[i] = dep[i] = sz[i] = 0;
		tree[i].clear();
	}

	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	ans = {0,0};
	md = 1e9;
	cendfs(1);
	assert(ans.fs);
	dep[ans.fs] = 0;
	dfs2(ans.fs,ans.fs);
	vector<int> v;
	for(int i = 1;i<=n;i++)if(dep[i] == md)v.push_back(i);
	ans.sc = ask(v).fs;
	cout<<"! "<<ans.fs<<' '<<ans.sc<<endl;
	string re;
	cin>>re;
	if(re != "Correct")exit(0);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
