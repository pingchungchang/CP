#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double



vector<string> two(63,"1");

ll lcs(string &a,string &b){
	ll n = a.size(),m = b.size();
	ll dp[n+1][m+1];
	ll returns = 0;
	memset(dp,0LL,sizeof(dp));
	for(ll i = 1;i<=n;i++){
		for(ll j = 1;j<=m;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(a[i-1] == b[j-1])dp[i][j] = dp[i-1][j-1]+1;
		}
	}
	for(ll i = 1;i<=n;i++){
		for(ll j = 1;j<=m;j++){
			if(dp[i][j] == j)returns = j;
		}
	}
	return returns;
}
void solve(){
	string s;
	cin>>s;
	ll ans = INT_MAX;
	for(auto i:two){
		ll tmp = lcs(s,i);
		ans = min(ans,(ll)(s.size()+i.size()-tmp*2));
//		cout<<i<<' '<<tmp<<'\n';
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	two[0] = "1";
	for(ll i = 1;i<63;i++)two[i] = to_string(stoll(two[i-1])*2);
	int t;
	cin>>t;
	while(t--)solve();
}

