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

const int mxn = 3030;
const ll i2 = inv(2);
ll dp[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	dp[1][1] = 1;
	int n;
	cin>>n;
	for(int i = 2;i<=n;i++){
		ll inow = i2;
		ll sum = 0;
		for(int j = i-1;j>=1;j--){
			inow = inow*i2%mod;
			sum = mad(sum,dp[i-1][j]*inow%mod);
		}
		dp[i][1] = sum*inv(mub(1,inow))%mod;
		for(int j = 2;j<=i;j++){
			dp[i][j] = mad(dp[i][j-1],dp[i-1][j-1])*i2%mod;
		}
	}
	for(int i = 1;i<=n;i++)cout<<dp[n][i]<<' ';
}
