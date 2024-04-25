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
#pragma GCC optimize("O3")
const ll mxn = 1e7+10;
ll dp[mxn];
bitset<mxn> isprime;
ll ans[mxn];
int main(){
	io
	ll n = 1e7+3;
//	cin>>n;
	fill(dp,dp+mxn,1LL);
	for(int i = 2;i<=n;i++){
//		if(i>10)break;
		if(!isprime[i]){
			for(ll j = i;j<=n;j += i){
				isprime[j] = true;
				ll tmp = j;
				ll re = 1,pw = i;
				while(tmp%i == 0){
					re += pw;
					pw *= i;
					tmp /= i;
				}
				dp[j] *= re;
			}
		}
	}
//	cout<<dp[3]<<endl;
//	for(int i = 2;i<=10;i++)cout<<dp[i]<<' ';cout<<endl;
	fill(ans,ans+n+1,-1LL);
	ans[1] = 1;
	for(int i = 2;i<=n;i++){
		if(dp[i]<n&&ans[dp[i]] == -1)ans[dp[i]] = i;
	}
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		cout<<ans[k]<<'\n';
	}
	return 0;
	
}

