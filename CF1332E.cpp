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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,L,R;
	cin>>n>>m>>L>>R;
	R -= L;
	if(n*m&1)cout<<pw(R+1,n*m);
	else{
		if(R&1)cout<<pw(2ll,n*m-1)*pw(R/2+1,n*m)%mod;
		else cout<<mad(pw(R+1,n*m),1)*inv(2)%mod;
	}
	return 0;
}
