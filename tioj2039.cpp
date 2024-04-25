#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e6+10;
const ll inf = 1e14;
ll n,tar;
ll arr[mxn];

inline pll calc(ll p){
	pll dp[2];
	dp[0] = {0ll,0ll};
	dp[1] = {-arr[1],0ll};
	for(int i = 2;i<=n;i++){
		pll tmp[2];
		tmp[0] = dp[0];
		pll tt = make_pair(dp[1].fs+arr[i]-p,dp[1].sc+1);
		tmp[0] = max(tmp[0],tt);
		tmp[1] = dp[1];
		tt = make_pair(dp[0].fs-arr[i],dp[0].sc);
		tmp[1] = max(tmp[1],tt);
		dp[0] = tmp[0];
		dp[1] = tmp[1];
	}
	return max(dp[0],dp[1]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>tar;
	for(int i = 1;i<=n;++i)cin>>arr[i];
	ll l = -1e12,r = 1e12;
	while(l != r){
		ll mid = l+(r-l+1)/2;
		pll re = calc(mid);
		if(re.sc>=tar)l = mid;
		else r= mid-1;
	}
	pll re = calc(l);
	ll ans = re.fs+l*tar;
	re = calc(0ll);
	if(re.sc<=tar)ans = max(ans,re.fs);
	cout<<max(ans,0ll);
}
