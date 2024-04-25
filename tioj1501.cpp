#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
int n;
int arr[mxn],dp[mxn];

bool check(ll k){
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	if(abs(arr[1]-arr[0])<=k)dp[1] = 1;
	for(int i = 2;i<n;i++){
		if(abs(arr[i]-arr[i-2])<=k)dp[i] = dp[i]||dp[i-2];
		if(abs(arr[i]-arr[i-1])<=k)dp[i] = dp[i]||dp[i-1];
	}
	return dp[n-1];
}

void solve(){
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	ll l = 0,r = INT_MAX;
	while(l != r){
		auto mid = (l+r)>>1;
		if(check(mid))r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
