#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> pref(100010,0);
ll pre(ll s,ll e){
	return pref[e+1]-pref[s];
}
void solve(){
	ll n;
	cin>>n;
	vector<ll> dp[2] = {vector<ll>(n,-1),vector<ll>(n,-1)};
	int now = 0;
	vector<ll> v(n);
	for(ll i = n-1;i>=0;i--)cin>>v[i];
	for(ll i = 1;i<=n;i++){
		pref[i] = v[i-1]+pref[i-1];
	}
	ll k = sqrt(2*n);
	ll ans = 1;
	dp[0][0] = v[0];
	for(int i = 1;i<n;i++)dp[0][i] = max(v[i],dp[0][i-1]);
	for(ll i = 2;i<=k;i++){
		now ^= 1;
		dp[now] = vector<ll>(n,-1);
		for(ll j = i*(i+1)/2-1;j<n;j++){
			ll lst = dp[now^1][j-i];
			ll tmp = pre(j-i+1,j);
			if(tmp<lst){
				dp[now][j] = tmp;
			}
			dp[now][j] = max(dp[now][j],dp[now][j-1]);
			if(dp[now][j] >-1)ans = i;
		}
//		cout<<i<<':';for(auto it:dp[now])cout<<it<<' ';cout<<'\n';
	}
	cout<<ans<<'\n';
}
/*
7
1 2 1 1 3 2 6

8
10 10 2 1 4 5 1 9
*/
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
