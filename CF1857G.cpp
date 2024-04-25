#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define int ll
#define fs first
#define sc second
#define  tiii tuple<int,int,int>

const int mxn = 2e5+10;
const ll mod = 998244353;
ll dsu[mxn],sz[mxn];
ll n,S;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	sz[a] += sz[b];
	dsu[b] = a;
}

void solve(){
	cin>>n>>S;
	for(int i = 0;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
	for(int i = 1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		pq.push(make_tuple(c,a,b));
	}
	ll ans = 1;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		ll val = get<0>(now),a = get<1>(now),b = get<2>(now);
		a = root(a),b = root(b);
		ll rest = sz[a]*sz[b]-1;
		//cout<<a<<' '<<b<<' '<<val<<' '<<rest<<',';
		ans = ans*pw(S-val+1,rest)%mod;
		onion(a,b);
	}
	cout<<ans<<'\n';
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
