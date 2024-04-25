#include <bits/stdc++.h> 
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 998244353;
const ll mxn = 4040;
pll dp[2][mxn];
ll n,k;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	a -= b;
	return a<0?a+mod:a;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	bool roll = 0;
	for(int i = 0;i<2;i++){
		for(int j = 1;j<=k;j++)dp[i][j] = {k,0};
	}
	for(int i = 2;i<=n;i++){
		roll ^= 1;
		for(auto &j:dp[roll])j = {0,0};
		dp[roll][1].fs = mad(dp[roll^1][k].fs,mub(dp[roll^1][k].fs,dp[roll^1][k-1].fs)*(k-1)%mod);
		dp[roll][1].sc = mad(dp[roll^1][k].sc,mub(dp[roll^1][k].sc,dp[roll^1][k-1].sc)*(k-1)%mod);
		for(int j = 2;j<k;j++){
			dp[roll][j].fs = 
			mad(mub(dp[roll^1][k-1].fs,dp[roll^1][j-1].fs),mub(dp[roll^1][j-1].fs,dp[roll^1][j-2].fs)*(k-j+1)%mod);

			dp[roll][j].sc = 
			mad(mub(dp[roll^1][k-1].sc,dp[roll^1][j-1].sc),mub(dp[roll^1][j-1].sc,dp[roll^1][j-2].sc)*(k-j+1)%mod);
		}
		dp[roll][k].fs = mub(dp[roll^1][k-1].fs,dp[roll^1][k-2].fs);
		dp[roll][k].sc = mub(dp[roll^1][k-1].sc,dp[roll^1][k-2].sc);
		dp[roll][k].sc = mad(dp[roll][k].sc,dp[roll][k].fs);
		//for(int j = 1;j<=k;j++)cout<<dp[roll][j].fs<<','<<dp[roll][j].sc<<' ';cout<<'\n';
		for(int j = 1;j<=k;j++){
			dp[roll][j].fs = mad(dp[roll][j].fs,dp[roll][j-1].fs);
			dp[roll][j].sc = mad(dp[roll][j].sc,dp[roll][j-1].sc);
		}
	}
	cout<<dp[roll][k].sc;
}
