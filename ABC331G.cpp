#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

using mint=modint998244353;
const int mxn = 2e5+10;
priority_queue<pll,vector<pll>,greater<pll>> pq;
vector<mint> v[mxn];
const ll mod = 998244353;
ll n,m;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		ll k;
		cin>>k;
		v[i] = vector<mint>(k+1,mint(0));
		v[i][0] = 1;
		v[i].back() = mod-1;
		pq.push(make_pair(v[i].size(),i));
	}
	while(pq.size()>1){
		auto a = pq.top().sc;
		pq.pop();
		auto b = pq.top().sc;
		pq.pop();
		v[a] = convolution(v[a],v[b]);
		v[b].clear();
		pq.push(make_pair(v[a].size(),a));
	}
	auto now = pq.top().sc;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ans = mad(ans,inv(i)*(mod-v[now][i].val())%mod);
	}
	cout<<ans*n%mod;
}
