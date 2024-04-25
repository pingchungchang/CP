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
	a %= mod;
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
	if(a>=mod)a %= mod;
	if(b>=mod)b %= mod;
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll len = to_string(n).size();
	ll ans = 0;
	for(ll i = 1;i<len;i++){//1+2+3+...+pw(10,i)-pw(10,i-1)
		ll tmp = mub(pw(10,i),pw(10,i-1));
		tmp = mad(tmp,1)*tmp%mod*inv(2)%mod;
		ans = mad(ans,tmp);
	}
	ll rest = mub(n+1,pw(10,len-1));
	rest = rest*(rest+1)/2%mod;
	ans = mad(ans,rest);
	cout<<ans;
}
