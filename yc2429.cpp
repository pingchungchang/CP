#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
const ll mod = 998244353;
const ll inf = 1e18;
pll dp[2][mxn];

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	bool roll = false;
	pll big = {0,1};
	for(auto &i:dp)for(auto &j:i)j = {-inf,0};
	dp[roll][0] = {0,1};
	for(int i = 0;i<k;i++){
		roll ^= 1;
		for(int j = 0;j<=k;j++)dp[roll][j] = {-inf,0};
		for(auto &p:arr){
			for(int j = p.fs;j<=k;j++){
				auto &tmp = dp[roll^1][j-p.fs];
				if(tmp.fs+p.sc>dp[roll][j].fs)dp[roll][j] = {tmp.fs+p.sc,tmp.sc};
				else if(tmp.fs+p.sc == dp[roll][j].fs)dp[roll][j].sc = mad(dp[roll][j].sc,tmp.sc);
			}
		}
		for(int j = 0;j<=k;j++){
			if(big.fs<dp[roll][j].fs)big = dp[roll][j];
			else if(big.fs == dp[roll][j].fs)big.sc = mad(big.sc,dp[roll][j].sc);
		}
	}
	cout<<big.fs<<'\n'<<big.sc;
}
