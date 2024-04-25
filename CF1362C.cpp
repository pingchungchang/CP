#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll dp[64];

void solve(){
	ll n;
	cin>>n;
	ll ans = 0;
	for(ll i = 0;i<=60;i++){
		if((1LL<<i)&n){
			ans += dp[i]+i+1;
		}
	}
	//ans -= __builtin_popcount((n+1)^n);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1;i<64;i++)dp[i] = dp[i-1]*2+i;
	int t;cin>>t;
	while(t--)solve();
}
