#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
ll arr[mxn];
int n,tar;

inline pll calc(ll p){
	pll dp[2];
	for(auto &i:dp)i = {0ll,0ll};
	for(int i = 1;i<=n;i++){
		pll tmp[2];
		tmp[0] = min(dp[0],dp[1]);
		tmp[1] = tmp[0];
		tmp[1] = min(tmp[1],make_pair(dp[0].fs+arr[i]-p,dp[0].sc+1));
		dp[0] = tmp[0],dp[1] = tmp[1];
	}
	return min(dp[0],dp[1]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>tar;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = n-1;i>=1;i--)arr[i] -= arr[i-1];
	n--;
	ll l = -1e9,r = 1e9;
	while(l != r){
		ll mid = l+(r-l)/2;
		pll re = calc(mid);
		if(re.sc>=tar)r = mid;
		else l = mid+1;
	}
	pll re = calc(l);
	cout<<(re.fs+l*tar);
}
