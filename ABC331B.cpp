#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 119;
ll dp[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	fill(dp,dp+mxn,INT_MAX);
	ll s,m,l;
	cin>>s>>m>>l;
	dp[0] = 0;
	for(int i = 1;i<mxn;i++){
		if(i>=6)dp[i] = min(dp[i],dp[i-6]+s);
		if(i>=8)dp[i] = min(dp[i],dp[i-8]+m);
		if(i>=12)dp[i] = min(dp[i],dp[i-12]+l);
	}
	ll ans = 1e18;
	for(int i = n;i<mxn;i++)ans = min(ans,dp[i]);
	cout<<ans<<'\n';
}
