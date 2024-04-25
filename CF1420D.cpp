#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 3e5+10;
ll fac[mxn],ifac[mxn];
const ll mod = 998244353;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
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
inline ll mub(ll a,ll b){
	if(!b)return a;
	return mad(a,mod-b);
}
inline ll C(ll a,ll b){
	if(a<b)return 0LL;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

vector<int> all;
int n,kk;
pll arr[mxn];
ll add[mxn*2],del[mxn*2];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	cin>>n>>kk;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		all.push_back(arr[i].fs);
		all.push_back(arr[i].sc);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i =1;i<=n;i++){
		arr[i].fs = lower_bound(all.begin(),all.end(),arr[i].fs)-all.begin();
		arr[i].sc = lower_bound(all.begin(),all.end(),arr[i].sc)-all.begin();
		add[arr[i].fs]++;
		del[arr[i].sc]++;
	}
	ll ans = 0;
	ll c = 0;
	for(int i = 0;i<all.size();i++){
		//cout<<all[i]<<":"<<add[i]<<' '<<del[i]<<' '<<c<<' '<<ans<<'\n';
		while(add[i]){
			ans = mad(ans,C(c,kk-1));
			c++;
			add[i]--;
		}
		c -= del[i];
	}
	cout<<ans<<'\n';
	return 0;
}
