#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mod = 1e9+7;
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

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll sum = 0;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		sum += c;
	}
	ll ans = 0;
	ll S = n*(n-1)/2;
	S %= mod;
	ll SS = S;
	sum %= mod;
	for(int i = 0;i<k;i++){
		//cout<<i<<":"<<sum<<' '<<S<<endl;
		ans = mad(ans,sum*inv(S)%mod);
		sum = mad(sum*SS%mod,m*S%mod*inv(SS)%mod);
		S = S*SS%mod;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
