#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 1e5+10;
int arr[mxn];
int sum[mxn];
int cnt[mxn];
int dp[mxn];
int n;
vector<int> v[mxn];

void solve(){
	cin>>n;
	for(auto &i:v)i.clear();
	ll ans = 0;
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	for(int i =0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n,greater<int>());
	for(int i = 0;i<n;i++){
		cnt[arr[i]]++;
		sum[arr[i]] += i;
		v[arr[i]].push_back(i);
	}
	for(int i = mxn-1;i>=1;i--){
		ll tmp = 0;
		ll nu = 0;
		for(int j = i;j<mxn;j+=i){
			tmp += nu*sum[j];
			nu += cnt[j];
			tmp -= dp[j];
		}
		dp[i] = tmp;
		ans += dp[i]*i;
	}
	for(int i = 1;i<mxn;i++){
		sort(v[i].rbegin(),v[i].rend());
		for(int j = 0;j<v[i].size();j++)ans += v[i][j]*j*i;
	}
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
