#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;

ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ll n;
	cin>>n;
	ll tans = mad(pw(10,n),mod-2*pw(9,n)%mod);
	tans = mad(tans,pw(8,n));
	cout<<tans;
}
