#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;
ll n,x;

inline ll pw(ll a,ll b){
	a %= mod;
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x>>n;
	vector<ll> primes;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i = 2;i*i<=x;i++){
			if(x%i == 0){
				primes.push_back(i);
				while(x%i == 0)x/=i;
			}
		}
	}
	if(x != 1)primes.push_back(x);
	ll ans = 1;
	//for(auto &i:primes)cout<<i<<',';cout<<endl;
	for(auto &i:primes){
		ll now = 1;
		while(now<=n/i)now *= i;
		ll pre = n+1;
		while(now>1){
			ans = ans*pw((now%mod)%mod,(n/now-n/pre))%mod;
			pre = now;
			now /= i;
		}
	}
	cout<<ans;
}
