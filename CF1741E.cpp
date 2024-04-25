#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n;
	cin>>n;
	bool dp[n+1] = {};
	int arr[n];
	dp[n] = true;
	for(auto &i:arr)cin>>i;
	for(int i = n-1;i>=0;i--){
		if(i+arr[i]+1<=n)dp[i]|=dp[i+arr[i]+1];
		if(i-arr[i]>=0)dp[i-arr[i]]|=dp[i+1];
	}
//	for(auto &i:dp)cout<<i;
	if(dp[0])cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

