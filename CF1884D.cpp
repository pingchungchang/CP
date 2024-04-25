#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e6+10;
bitset<mxn> done;
ll dp[mxn];
ll cnt[mxn];
int n;

void solve(){
	for(int i = 0;i<=n;i++)dp[i] = cnt[i] = done[i] = 0;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[k]++;
	}
	for(int i = n;i>=1;i--){
		ll s = 0;
		for(int j = i;j<=n;j+=i)s += cnt[j];
		dp[i] = s*(s-1)/2;
		for(int j = i+i;j<=n;j+=i)dp[i] -= dp[j];
	}
	ll ans = 1ll*n*(n-1)/2;
	//for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<'\n';
	for(int i = 1;i<=n;i++){
		if(cnt[i]){
			for(int j = i;j<=n;j+=i){
				if(!done[j])ans -= dp[j];
				done[j] = true;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
