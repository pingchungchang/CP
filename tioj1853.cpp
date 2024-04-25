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
	int dp[2] = {},rdp[2] = {};
	int n;
	cin>>n;
	char c;
	short now = 0;
	for(int i = 0;i<n;i++){
		cin>>c;
		now^=1;
		if(c == '0'){
			dp[now] = min(dp[now^1],rdp[now^1])+1;
			rdp[now] = rdp[now^1];
		}
		else{
			dp[now] = dp[now^1];
			rdp[now] = min(rdp[now^1],dp[now^1])+1;
		}
	}
	cout<<dp[now];
}

