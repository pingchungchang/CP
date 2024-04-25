#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mxn = 50*50+55;
ll dp[55][mxn];
int main(){
	io
	ll n,k;
	cin>>n>>k;
	dp[0][0] = 1;
	for(int i = 0;i<n;i++){
		int x;
		cin>>x;
		for(int j = n;j>=0;j--){
			for(int kk = mxn-1;kk>=0;kk--){
				dp[j+1][kk+x] += dp[j][kk];
			}
		}
	}
//	for(int i = 1;i<=n;i++)cout<<i<<':'<<dp[i][i*k]<<'\n';
	ll ans = 0;
	for(int i = 1;i<=n;i++)ans += dp[i][i*k];
	cout<<ans;
}

