#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 2e6+10;
const ll mod = 1e9+7;
ll dp[mxn][3];

inline ll mad(ll a,ll b){
	a+=b;
	return a>=mod?a-mod:a;
}

void solve(){
	int k;
	cin>>k;
	cout<<dp[k][2]*4%mod<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	dp[3][0] = 0;dp[3][1] = dp[3][2] = 1;
	dp[4][0] = dp[4][1] = dp[4][2] = 1;
	for(int i = 5;i<mxn;i++){
		dp[i][0] = dp[i-1][2]+dp[i-2][2]*2;
		dp[i][1] = dp[i-1][0]+dp[i-2][0]*2+1;
		dp[i][2] = max(dp[i][1],dp[i][0]);
		dp[i][0]%=mod;dp[i][1]%=mod,dp[i][2]%=mod;
	}
	int t;cin>>t;
	while(t--)solve();
}
