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
#pragma GCC optimize("O3,-unroll loops")
const ll mxn = 203;
const ll inf = 1e17;
ll re[mxn][mxn];
ll val[mxn];
ll bb[mxn][mxn],ans[mxn][mxn];
void mult(ll a[][mxn],ll b[][mxn]){
	for(auto &i:re)for(auto &j:i)j = -inf;
	for(int i = 0;i<mxn;i++){
		for(int j = 0;j<mxn;j++){
			for(int k = 0;k<mxn;k++){
				re[i][j] = max(re[i][j],a[i][k]+b[k][j]);
			}
		}
	}
	for(auto &i:re)for(auto &j:i)if(j<-inf)j = -inf;
}
void assign(ll x[][mxn],ll y[][mxn]){
	for(int i = 0;i<mxn;i++){
		for(int j = 0;j<mxn;j++)x[i][j] = y[i][j];
	}
	return;
}

int main(){
	io
	ll n,m;
	ll s,t;
	cin>>n>>m;
	cin>>s>>t;
	for(auto &i:bb)for(auto &j:i)j = -inf;
	for(auto &i:ans)for(auto &j:i)j = -inf;
	for(int i = 1;i<=n;i++)cin>>val[i];
	for(int i = 0;i<m;i++){
		ll st,ed;
		cin>>st>>ed;
		bb[st][ed] = val[ed];
	}
	ans[s][s] = 0;
	mult(ans,bb);
//	for(int i = 0;i<10;i++){
//		for(int j= 0;j<10;j++)cout<<re[i][j]<<' ';cout<<endl;
//	}
//	return 0;
	while(t){
		if(t&1){
			mult(ans,bb);
			assign(ans,re);
		}
		mult(bb,bb);
		assign(bb,re);
		t>>=1;
	}
	ll fin = -inf;
	for(auto &i:ans[s])fin = max(fin,i);
	cout<<fin;
}

