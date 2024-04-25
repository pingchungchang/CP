#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e4+10;
const ll inf = 1e18;
ll n,m,k;
ll dp[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(auto &i:dp)i = -inf;
	dp[0] = 0;
	for(int i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		for(int j = m;j>=a;j--){
			dp[j] = max(dp[j],dp[j-a]+b);
		}
	}
	for(int i = 1;i<=m;i++)dp[i] = max(dp[i],dp[i-1]);
	for(int i = 1;i<=k;i++){
		cout<<dp[m/i]*i<<'\n';
	}
	return 0;
}
