#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5050;
ll dp[mxn];
ll cnt[mxn];

void solve(){
	memset(cnt,0,sizeof(cnt));
	memset(dp,0,sizeof(dp));
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[min(mxn-1,k)]++;
	}
	int mex = 0;
	while(cnt[mex])mex++;
	dp[mex] = 0;
	for(int i = mex-1;i>=0;i--){
		dp[i] = 1e18;
		for(int j = i+1;j<=mex;j++){
			dp[i] = min(dp[i],dp[j]+1ll*j*(cnt[i]-1)+i);
		}
	}
	cout<<dp[0]<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
