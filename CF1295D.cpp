#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll a,m;
	cin>>a>>m;
	ll G = __gcd(a,m);
	a/=G,m/=G;
	vector<ll> primes;
	ll ans = m;
	ll M = m;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i = 2;i*i<=m;i++){
			if(m%i == 0){
				flag = true;
				primes.push_back(i);
				while(m%i == 0)m/=i;
			}
		}
	}
	if(m != 1)primes.push_back(m);
	for(auto &i:primes)ans = ans/i*(i-1);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
