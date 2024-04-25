#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	ll dp[] = {0,0,0,0};
	dp[3] = 1;
	for(auto &i:s){
		if(i == 'a'){
			dp[0] = mad(dp[0],dp[3]);
		}
		else if(i == 'b'){
			dp[1] = mad(dp[1],dp[0]);
		}
		else if(i == 'c'){
			dp[2] = mad(dp[1],dp[2]);
		}
		else{
			dp[2] = mad(dp[2]*3%mod,dp[1]);
			dp[1] = mad(dp[1]*3%mod,dp[0]);
			dp[0] = mad(dp[0]*3%mod,dp[3]);
			dp[3] = dp[3]*3%mod;
		}
		//for(auto &j:dp)cout<<j<<' ';cout<<'\n';
	}
	cout<<dp[2];
}
