#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

#define ll long long
const int mxn = 1e7+10;
ll dp[mxn];
const ll mod = 998244353;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,a1,x,y,m,k;
	cin>>n>>a1>>x>>y>>m>>k;
	dp[1] = a1;
	for(ll i = 2;i<=n;i++){
		dp[i] = (dp[i-1]*x+y)%m;
	}
	for(int i = 0;i<=k;i++){
		if(i == 1)for(int i = 1;i<=n;i++)dp[i] = mad(dp[i],dp[i-1]);
		else for(int i = n;i>=1;i--)dp[i] = mad(dp[i],dp[i-1]);
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++)ans ^= dp[i]*i;
	cout<<ans;
}
