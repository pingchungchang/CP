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
ll calc(ll a,ll b){
	ll re = b-a;
	return a*b/re;
}
int main(){
	ll dp[30][30];
	memset(dp,0LL,sizeof(dp));
	dp[1][1] = 1;
	for(int i = 2;i<=28;i++){
		dp[i][1] = i;
		for(int j = 2;j<i;j++){
			dp[i][j] = calc(dp[i-1][j-1],dp[i][j-1]);
		}
		dp[i][i] = i;
	}
//	for(int i = 1;i<=28;i++){
//		for(int j =1;j<=i;j++)cout<<dp[i][j]<<' ';cout<<endl;
//	}
	ll r,c;
	cin>>r>>c;
	cout<<dp[r][c];
	
}

