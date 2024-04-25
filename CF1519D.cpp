#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mxn = 5005;
vector<ll> a,b;
ll dp[mxn][mxn];
ll f(ll i,ll j){
	if(dp[i][j] != -1)return dp[i][j];
	else dp[i][j] = f(i+1,j-1)+a[i]*b[j]+a[j]*b[i];
	return dp[i][j];
}
void solve(){
	int n;
	cin>>n;
	a = vector<ll> (n+1);
	b = vector<ll>(1+n);
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++)cin>>b[i];
	for(int i = 1;i<=n;i++){
		dp[i][i] = a[i]*b[i];
		dp[i][i+1] = a[i]*b[i+1]+a[i+1]*b[i];
	}
	ll pref[n+1];
	memset(pref,0,sizeof(pref));
	for(ll i =1;i<=n;i++)pref[i] = pref[i-1]+a[i]*b[i];
	ll ans = 0;
	for(ll i = 1;i<=n;i++){
		for(ll j = i;j<=n;j++){
			ans = max(ans,pref[i-1]+f(i,j)+pref[n]-pref[j]);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	memset(dp,-1,sizeof(dp));
	int t = 1;
	while(t--)solve();
	
}

