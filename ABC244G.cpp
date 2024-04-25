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

const int mxn = 1e5+10;
vector<int> ans;
struct node{
	int dp;
	int par;
	int tar;
	vector<int> childs;
	node(){
		tar = 0;
		dp = par = 0;
	}
};
node tree[mxn];
bitset<mxn> goneto;
vector<int> paths[mxn];
void dfs1(int now){
	goneto[now] = true;
	for(auto &nxt:paths[now]){
		if(goneto[nxt])continue;
		tree[nxt].par = now;
		tree[now].childs.push_back(nxt);
		dfs1(nxt);
	}
	return;
}
void dfs(int now){
	ans.push_back(now);
	tree[now].dp++;
	for(auto &nxt:tree[now].childs){
		dfs(nxt);
	}
	if(now == 1)return;
	if((tree[now].tar&1) != (tree[now].dp&1)){
		ans.push_back(tree[now].par);
		tree[tree[now].par].dp++;
		ans.push_back(now);
		ans.push_back(tree[now].par);
		tree[tree[now].par].dp++;
	}
	else{
		ans.push_back(tree[now].par);
		tree[tree[now].par].dp++;
	}
	return;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	dfs1(1);
	string s;
	cin>>s;
	for(int i = 0;i<n;i++){
		if(s[i] == '1')tree[i+1].tar = 1;
		else tree[i+1].tar = 0;
	}
	dfs(1);
	if((tree[1].dp&1) != (tree[1].tar&1)){
		if(ans.back() == 1)ans.pop_back();
		else ans.push_back(1);
	}
	if(ans.size()>n*4)while(1);
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}

