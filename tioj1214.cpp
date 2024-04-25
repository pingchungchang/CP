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

const int mxn = 110;
const ll mod = 1e9+7;
const ll p = 41;
int n;
vector<int> tree1[mxn],tree2[mxn];
int sz1[mxn],sz2[mxn];
void get_sz(vector<int> tree[],int now,int par,int sz[]){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		get_sz(tree,nxt,now,sz);
		sz[now] += sz[nxt];
	}
//	cout<<now<<','<<sz[now]<<endl;
	return;
}
void centroid(vector<int> tree[],int now,int par,int sz[],int tar,vector<int>& cens){
	bool flag = true;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		if(sz[nxt]>tar)flag = false;
		centroid(tree,nxt,now,sz,tar,cens);
	}
	if(n-sz[now]<=tar&&flag)cens.push_back(now);
	return;
}
ll dfs(vector<int> tree[],int now,int par){
	vector<ll> tmp;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		tmp.push_back(dfs(tree,nxt,now));
	}
	//why reverse sort?
	sort(tmp.rbegin(),tmp.rend());
	ll re = 1;
	for(auto &i:tmp){
		re*= p;
		re += i;
		re %= mod;
	}
	return re;
}
void solve(){
	for(int i = 1;i<=n;i++){
		tree1[i].clear();
		tree2[i].clear();
	}
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree1[a].push_back(b);
		tree1[b].push_back(a);
	}
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree2[b].push_back(a);
		tree2[a].push_back(b);
	}
	get_sz(tree1,1,1,sz1);
	get_sz(tree2,1,1,sz2);
	vector<int> a;
	centroid(tree1,1,1,sz1,n/2,a);
	set<ll> st;
	for(auto &i:a)st.insert(dfs(tree1,i,i));
	vector<int> b;
	centroid(tree2,1,1,sz2,n/2,b);
	auto h = dfs(tree2,b[0],b[0]);
//	for(auto i:a)cout<<i<<' ';cout<<";";for(auto i:b)cout<<i<<":";
	if(st.find(h) == st.end()){
		cout<<"Different\n";
	}
	else cout<<"Same\n";
	return;	
}
int main(){
	io
	while(cin>>n){
		if(n == 0)return 0;
		solve();
	}
}

