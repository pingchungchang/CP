#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mod = 998244353;
const ll mxn = 3e5+10;

ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll fac[mxn],ifac[mxn];
ll arr[mxn];

void solve(){
	ll N;
	cin>>N;
	ll ls = 0,rs = 0;
	for(int i = 0;i<N*2;i++){
		cin>>arr[i];
	}
	sort(arr,arr+N*2);
	for(int i = 0;i<N*2;i++){
		rs += arr[i]*(i<N?-1:1);
	}
	rs %= mod;
	cout<<fac[N*2]*ifac[N]%mod*ifac[N]%mod*rs%mod<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	ifac[mxn-1] = pw(fac[mxn-1],mod-2);
	for(int i = mxn-2;i>=0;i--)ifac[i] = ifac[i+1]*(i+1)%mod;
	ll N = 2;
	int t = 1;
	while(t--)solve();
}
