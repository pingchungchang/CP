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
const ll mxn = 1001;
ll dp[mxn][mxn];
ll pref[mxn];
const ll inf = 1e18;
ll f(ll l,ll r){
	if(l == r)return 0;
	if(dp[l][r] > -inf)return dp[l][r];
	for(ll k = l;k<r;k++){
		dp[l][r] = max(dp[l][r],max(f(l,k),f(k+1,r))+(pref[k]-pref[l-1])*(pref[r]-pref[k]));
	}
//	cout<<l<<' '<<r<<' '<<dp[l][r]<<endl;
	return dp[l][r];
}
int main(){
	io
	ll n;
	cin>>n;
	for(auto &i:dp)fill(i,i+mxn,-inf);
	for(int i = 1;i<=n;i++){
		cin>>pref[i];
		pref[i]+=pref[i-1];
	}
	cout<<f(1,n);
	
}

