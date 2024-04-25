#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	ll arr[2][n+2];
	ll ans = INT_MAX;
	memset(arr,0LL,sizeof(arr));
	for(ll i = 0;i<2;i++)for(int j = 1;j<=n;j++)cin>>arr[i][j];
	ll pre = 0,suf = 0;
	for(ll i = 2;i<=n;i++)suf += arr[0][i];
	for(ll i = 1;i<=n;i++){
		ans = min(ans,max(pre,suf));
		pre += arr[1][i];
		suf -= arr[0][i+1];
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

