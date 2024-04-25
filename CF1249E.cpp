#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int n,C;
int dp[mxn];
int arr[mxn],brr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>C;
	for(int i = 2;i<=n;i++)cin>>arr[i],arr[i] +=arr[i-1];
	for(int i = 2;i<=n;i++)cin>>brr[i],brr[i] += brr[i-1];
	pii small = {0,0};
	for(int i = 2;i<=n;i++){
		dp[i] = min(arr[i]+small.fs,brr[i]+C+small.sc);
		small.fs = min(small.fs,dp[i]-arr[i]);
		small.sc = min(small.sc,dp[i]-brr[i]);
	}
	for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';
	return 0;
}
/*
dp[i] = min dp[j]+pref[i]-pref[j] = pref[i] + min dp[j]-pref[j]
dp[i] = min dp[j]+C+pref2[i]-pref2[j] = C+pref2[i]+min dp[j]-pref2[j]
*/
