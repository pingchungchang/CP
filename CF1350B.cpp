#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	ll arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll ans = 1;
	ll dp[n+1];
	memset(dp,0,sizeof(dp));
	for(int i = n;i>=1;i--){
		dp[i] = 1;
		for(int j = i+i;j<=n;j+=i){
			if(arr[j]>arr[i])dp[i] = max(dp[i],dp[j]+1);
		}
	}
	cout<<*max_element(dp+1,dp+n+1)<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
