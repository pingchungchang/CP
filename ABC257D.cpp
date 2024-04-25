#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	ll p;
	pll pos;
	node(){}
};
int main(){
	io
	int n;
	cin>>n;
	vector<node> v(n,node());
	for(int i = 0;i<n;i++){
		cin>>v[i].pos.fs>>v[i].pos.sc>>v[i].p;
	}
	vector<vector<ll>> adj(n,vector<ll>(n,0LL));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			adj[i][j] = (abs(v[i].pos.fs-v[j].pos.fs)+abs(v[i].pos.sc-v[j].pos.sc)+v[i].p-1)/v[i].p;
		}
	}
//	for(int i = 0;i<n;i++){
//		for(int j = 0;j<n;j++)cout<<adj[i][j]<<' ';cout<<endl;
//	}
	for(int i = 0;i<n;i++){
		for(int j= 0;j<n;j++){
			for(int k = 0;k<n;k++){
				adj[j][k] = min(max(adj[j][i],adj[i][k]),adj[j][k]);
			}
		}
	}
//	for(int i = 0;i<n;i++){
//		for(int j = 0;j<n;j++)cout<<adj[i][j]<<' ';cout<<endl;
//	}
	ll ans = LONG_LONG_MAX;
	for(ll i = 0;i<n;i++){
		ll tmp = 0;
		for(ll j = 0;j<n;j++){
			tmp = max(tmp,adj[i][j]);
		}
		ans = min(ans,tmp);
	}
	cout<<ans;
}

