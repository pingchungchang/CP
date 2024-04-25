#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 998244353;
ll pw(ll a,ll b){
	ll ans = 1;
	while(b != 0){
		if((b&1) != 0)ans = (ans*a)%mod;
		a = a*a%mod;
		b>>=1;
	}
	return ans;
}

ll inverse(ll k){
	return pw(k,mod-2);
}
int main(){
	ll n;
	cin>>n;
	cout<<inverse(2);
	return 0;
}

