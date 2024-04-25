#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mod = 998244353;
const int mxn = 550;

ll fac[mxn*2],ifac[mxn*2];
int arr[mxn],brr[mxn];
int N,M,K;
pll dp[2][mxn][mxn];

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = 1ll*re*a%mod;
		b>>=1;
		a = 1ll*a*a%mod;
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
inline pll mad(pll a,pll b){
	a.fs = mad(a.fs,b.fs);
	a.sc = mad(a.sc,b.sc);
	return a;
}
inline pll mub(pll a,pll b){
	a.fs = mub(a.fs,b.fs);
	a.sc = mub(a.sc,b.sc);
	return a;
}
inline ll C(ll a,ll b){
	return 1ll*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ifac[0] = fac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = 1ll*fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	cin>>N>>M>>K;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	for(int i = 1;i<=M;i++)cin>>brr[i];
	sort(arr+1,arr+N+1);
	sort(brr+1,brr+M+1);
	bool roll = false;
	for(int i = 0;i<=N;i++)for(int j = 0;j<=M;j++)dp[roll][i][j] = make_pair(0,1);
	for(int i = 1;i<=K;i++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int j = 1;j<=N;j++){
			for(int k = 1;k<=M;k++){
				dp[roll][j][k] = mad(dp[roll^1][j-1][k-1],dp[roll][j][k]);
				if(arr[j]>brr[k])dp[roll][j][k].fs = mad(dp[roll][j][k].fs,dp[roll^1][j-1][k-1].sc);
				dp[roll][j][k] = mad(dp[roll][j][k-1],dp[roll][j][k]);
				dp[roll][j][k] = mad(dp[roll][j-1][k],dp[roll][j][k]);
				dp[roll][j][k] = mub(dp[roll][j][k],dp[roll][j-1][k-1]);
			}
		}
	}
	ll tmp = dp[roll][N][M].fs;
	ll cnt = 1ll*C(N,K)*C(M,K)%mod;
	cout<<1ll*tmp*inv(cnt)%mod;
}
