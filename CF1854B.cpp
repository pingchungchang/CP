#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll

const int mxn = 2e5+10;
bitset<mxn> dp;
int arr[mxn],pref[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	memset(arr,0,sizeof(arr));
	for(int i = 0;i<n;i++)cin>>arr[i];
	pref[0] = arr[0];
	for(int i = 1;i<mxn;i++)pref[i] = pref[i-1]+arr[i];
	int ans = arr[0];
	dp[0] = true;
	for(int i = 0;i<mxn;i++){
		if(dp[i])ans = max(ans,pref[i]-i);
		if(dp.count())dp |= (dp<<arr[i]);
		dp[i] = false;
	}
	cout<<ans;
}
