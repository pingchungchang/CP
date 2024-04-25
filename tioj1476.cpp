#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll dp[2] = {0,1};
	for(int i = 1;i<=n;i++){
		swap(dp[0],dp[1]);
		dp[1] += dp[0];
	}
	cout<<dp[1];
}
