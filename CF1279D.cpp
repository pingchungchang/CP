#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mod = 998244353;

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
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

const ll mxn = 1e6+10;
ll n;
ll chance[mxn];
ll chose[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	ll C = inv(n);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		ll tmp = inv(k)*C%mod;
		while(k--){
			int a;
			cin>>a;
			chance[a] = mad(chance[a],tmp);
			chose[a]++;
		}
	}
	ll ans = 0;
	for(int i = 1;i<mxn;i++){
		ans = mad(ans,chance[i]*chose[i]%mod*C%mod);
	}
	cout<<ans;
}
