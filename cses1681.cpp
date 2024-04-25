#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;

vector<vector<ll>> paths(1e5+5);
vector<ll> ans(1e5+5,0);
vector<ll> goneto(1e5+5,0);
ll n,m;

void dfs(ll now){
	goneto[now] =-1;
	for(ll i =0;i<paths[now].size();i++){
		ll nxt = paths[now][i];
		goneto[nxt]--;
		ans[nxt] += ans[now];
		ans[nxt]%=mod;
		if(goneto[nxt] == 0){
			dfs(nxt);
		}
	}
}
int main(){
	cin>>n>>m;
	for(ll i =0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
		goneto[b]++;
	}
	ans[0] = 1;
	for(int i =0;i<n;i++){
		if(goneto[i] == 0){
			dfs(i);
		}
	}
	cout<<ans[n-1];
}
