#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	vector<ll> dp(1+n,0);
	vector<ll> v(1+n,0);
	for(ll i = 1;i<=n;i++)cin>>v[i];
	ll ans= (n>=4?v[1]+v[2]+v[3]+v[4]:0LL);
	ans = max(ans,0LL);
	if(n>=4)dp[4] = max(v[1]+v[2]+v[3]+v[4],0LL);
	for(ll i = 5;i<=n;i++){
		ll tmp = v[i]+v[i-1]+v[i-2]+v[i-3]+dp[i-5];
		ans = max(ans,tmp);
		dp[i] = max(dp[i-1],tmp);
	}
	cout<<ans;
}

