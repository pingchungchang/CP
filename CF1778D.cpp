#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mod = 998244353;
const int mxn = 1e6+10;
ll dp[mxn];

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
	int n;
	string a,b;
	cin>>n;
	cin>>a>>b;
	int dif = 0;
	for(int i = 0;i<n;i++)dif += (a[i] != b[i]);
	dp[n] = 1;
	for(int i = n-1;i>0;i--){
		dp[i] = mad(n,1ll*(n-i)*dp[i+1]%mod)*inv(i)%mod;
	}
	ll ans = 0;
	for(int i = dif;i>0;i--)ans = mad(ans,dp[i]);
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
