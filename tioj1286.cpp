#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e6;

inline ll pw(ll a,ll b){
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
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll ans = 0;
	for(ll i = a;i<=d;i+=b){
		ans = (ans+pw(i,c))%mod;
	}
	cout<<ans;
}
