#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll inf = 4e18;
const ll mxn = 2e5+10;
ll arr[mxn],brr[mxn];

void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	ll dp[4] = {-inf,-inf,-inf,-inf};//a+b,a-b,-a+b,-a-b
	ll tans = 0,ans = 0;
	for(int i = 1;i<=n;i++)tans += abs(arr[i]-brr[i]);
	ans = tans;
	for(int i = 1;i<=n;i++){
		ll tmp = tans-abs(arr[i]-brr[i]);
		tmp = max({tans,tmp-arr[i]-brr[i]+dp[0],tmp-arr[i]+brr[i]+dp[1],tmp+arr[i]-brr[i]+dp[2],tmp+arr[i]+brr[i]+dp[3]});
		ans = max(ans,tmp);
		dp[0] = max(dp[0],arr[i]+brr[i]-abs(arr[i]-brr[i]));
		dp[1] = max(dp[1],arr[i]-brr[i]-abs(arr[i]-brr[i]));
		dp[2] = max(dp[2],-arr[i]+brr[i]-abs(arr[i]-brr[i]));
		dp[3] = max(dp[3],-arr[i]-brr[i]-abs(arr[i]-brr[i]));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
