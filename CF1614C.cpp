#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 1e9+7;
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<pair<pll,ll>> v(m);
	for(int i = 0;i<m;i++)cin>>v[i].fs.fs>>v[i].fs.sc>>v[i].sc;
	sort(v.begin(),v.end());
	vector<ll> ans(n+1,0LL);
	queue<pair<pll,ll>> q;
	for(auto i:v)q.push(i);
	for(int i = 1;i<=n;i++){
		while(!q.empty()&&q.front().fs.sc<i)q.pop();
		if(!q.empty()&&q.front().fs.fs<=i){
			if(q.front().fs.sc>=i){
				ans[i] = q.front().sc;
			}
			q.pop();
		}
	}
	ll anss = 0;
//	for(auto i:ans)cout<<i<<' ';cout<<'\n';
	for(ll i = 0;i<32;i++){
		vector<ll> dp(2,0LL);
		for(ll j = 1;j<=n;j++){
			if((1LL<<i)&ans[j]){
				ll tmp = dp[1];
				dp[1]+= dp[0];
				dp[0]+= tmp;
				dp[1]++;
			}
			else{
				dp[1] += dp[1];
				dp[0] += dp[0];
				dp[0]++;
			}
			dp[0]%= mod;
			dp[1]%= mod;
		}
		anss += (1LL<<i)%mod*dp[1];
		anss%=mod;
	}
	cout<<anss%mod<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

