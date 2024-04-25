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
const ll mod = 998244353;
const int mxn = 2e5+10;
int dsu[mxn];
ll pw(ll a,ll b){
	ll re =1;
	while(b){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return re;
}
int sz;
int root(int now){
	if(dsu[now] != now)dsu[now] = root(dsu[now]);
	return dsu[now];
}
void onion(int a,int b){
	int ra = root(a),rb =root(b);
	dsu[ra] = rb;
	if(ra != rb)sz--;
	return;
}
int main(){
	io
	ll n,m;
	cin>>n>>m;
	ll arr[n+1];
	sz = n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		dsu[i] = i;
	}
	ll ans = 0;
	for(ll i = 1;i<=n;i++){
		int pos = arr[i];
		if(root(pos) != root(i)){
			ans += m*(m-1)/2%mod*pw(m,sz-2)%mod;
			ans %= mod;
		}
		onion(pos,i);
	}
	cout<<ans;
}

