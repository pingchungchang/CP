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
int main(){
	io
	ll n;
	cin>>n;
	short now = 1;
	ll dp[2][3];
	memset(dp,0LL,sizeof(dp));
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		now ^= 1;
		dp[now][0] = max(dp[now^1][1],dp[now^1][2])-k;
		dp[now][1] = max(dp[now^1][0],dp[now^1][2]);
		dp[now][2] = max(dp[now^1][0],dp[now^1][1])+k;
	}
	cout<<*max_element(dp[now],dp[now]+3);
}

