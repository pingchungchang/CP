#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mod = 998244353;
ll dp[20101];
ll n,x;
ll arr[1010];

inline ll pw(ll a,ll b){
	assert(a<mod);
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
	cin>>n>>x;
	dp[0] = 1;
	for(int i = 0;i<n;i++)cin>>arr[i];
	x++;
	ll chance = inv(n);
	for(int i = 0;i<=x;i++){
		for(int j = 0;j<n;j++){
			int t = min(x,i+arr[j]);
			dp[t] = mad(dp[t],dp[i]*chance%mod);
		}
	}
	//for(int i = 1;i<=x;i++)cout<<dp[i]<<' ';cout<<endl;
	for(int i = 1;i<=x;i++)dp[i] = mad(dp[i],dp[i-1]);
	ll sum = 0,cnt = 0;
	for(int i = 0;i<n;i++){
		if(x<=arr[i]){
			sum = mad(sum,dp[x-1]);
			if(!i)cnt = dp[x-1];
		}
		else{
			ll t = x-arr[i]-1;
			sum = mad(sum,mub(dp[x-1],dp[t]));
			if(!i)cnt = mub(dp[x-1],dp[t]);
		}
		//cout<<i<<":"<<cnt<<','<<sum<<endl;
	}
	cout<<cnt*inv(sum)%mod;
}
