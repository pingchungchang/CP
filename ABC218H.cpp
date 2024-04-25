#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 1e12+10;
const ll mxn = 2e5+10;
ll arr[mxn];
pll dp[mxn][2];
ll n,tar;

inline pll calc(ll p){
	for(auto &i:dp)for(auto &j:i)j = {0,0};
	dp[0][1] = {0,-1};
	for(int i = 1;i<=n;i++){
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		pll ta = {dp[i-1][0].fs+arr[i]-p,dp[i-1][0].sc-1},tb = dp[i-1][1];
		dp[i][1] = max(ta,tb);
	}
	auto re = max(dp[n][0],dp[n][1]);
	re.sc = -re.sc;
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>tar;
	for(int i = 2;i<=n;i++)cin>>arr[i];
	for(int i = n;i>=1;i--)arr[i] += arr[i-1];
	if(tar+tar>n)tar = n-tar;
	ll l = -inf,r = inf;
	while(l != r){
		ll mid = l+(r-l)/2;
		auto tmp = calc(mid);
		//cout<<l<<' '<<r<<' '<<mid<<":"<<tmp.fs<<' '<<tmp.sc<<endl;
		if(tmp.sc>tar)l = mid+1;
		else r = mid;
	}
	pll tmp = calc(l);
	cout<<tmp.fs+l*tar;
}
