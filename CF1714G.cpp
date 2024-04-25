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

struct node{
	ll a,b,des;
	node(){
		a = b = 0;
		des = 0;
	}
	node(ll aa,ll bb,ll cc){
		a = aa,b = bb,des = cc;
		
	}
};
vector<vector<node>> tree;
vector<ll> dp;
vector<ll> ans;
void dfs(int now,ll val){
//	cout<<now<<'\n';
	ans[now] = upper_bound(_all(dp),val)-dp.begin()-1;
	for(auto nxt:tree[now]){
		dp.push_back(dp.back()+nxt.b);
		dfs(nxt.des,val+nxt.a);
		dp.pop_back();
	}
	return;
}
void solve(){
	ll n;
	cin>>n;
	dp = {0LL};
	ans = vector<ll>(n+1,0);
	tree = vector<vector<node>>(n+1);
	for(int i = 2;i<=n;i++){
		ll x,y,p;
		cin>>p>>x>>y;
		tree[p].push_back(node(x,y,i));
	}
	dfs(1,0);
	for(ll i = 2;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

