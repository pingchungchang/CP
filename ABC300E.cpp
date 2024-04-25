#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 998244353;

inline ll pw(ll a,ll b){
	ll re =1;
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

ll rev[7] = {1LL,1LL,inv(2),inv(3),inv(4),inv(5),inv(6)};
map<ll,ll> dp;

ll calc(ll k){
	if(dp.find(k) != dp.end())return dp[k];
	if(k == 1)return 1;
	ll c = 1;
	ll total = 0;
	for(ll i = 2;i<=6;i++){
		if(k%i == 0){
			ll tmp = calc(k/i);
			if(tmp == 0)continue;
			total += calc(k/i)*rev[5]%mod;
			c++;
		}
	}
	total %= mod;
	return dp[k] = total;
	//return dp[k] = total*(c-1)%mod*inv(c)%mod;
}

void solve(){
	ll n;
	cin>>n;
	cout<<calc(n)<<'\n';
	//for(auto &i:dp)cout<<i.fs<<":"<<i.sc<<endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	//for(int i = 1;i<=6;i++)cout<<i<<':'<<rev[i]<<endl;
	while(t--)solve();
}
