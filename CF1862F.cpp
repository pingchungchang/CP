#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e4+10;
bitset<mxn*100> dp;
int n;

void solve(){
	for(int i = 0;i<n*mxn;i++)dp[i] = 0;
	ll w,f;
	cin>>w>>f;
	cin>>n;
	ll arr[n];
	dp[0] = 1;
	ll sum = 0;
	for(auto &i:arr){
		cin>>i;
		sum += i;
		dp |= dp<<i;
	}
	ll ans = (sum+w-1)/w;
	for(int i = 0;i<mxn*n;i++){
		if(dp[i]){
			ans = min(ans,max((i+w-1)/w,(sum-i+f-1)/f));
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
