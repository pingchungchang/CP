#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

ll dp[62];

void solve(){
	ll k;
	cin>>k;
	if(k&1){
		cout<<"-1\n";
		return;
	}
	string ans;
	for(int i = 61;i>=0;i--){
		while(dp[i]<=k){
			k -= dp[i];
			ans += '1';
			for(int j = 0;j<i;j++)ans+= '0';
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(ll i = 0;i<62;i++)dp[i] = (1LL<<(i+2))-2;
	while(t--)solve();
}
