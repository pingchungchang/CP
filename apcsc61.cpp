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
	int n;
	cin>>n;
	ll dp[2][4];
	memset(dp,0LL,sizeof(dp));
	dp[0][0] = 1;
	int now = 0,pre = 1;
	for(int i = 0;i<n;i++){
		swap(now,pre);
		for(int j = 0;j<4;j++){
			dp[now][j] = 0;
			for(int k = 0;k<4;k++){
				if(j == k)continue;
				dp[now][j] += dp[pre][k];
			}
		}
	}
	cout<<dp[now][0];
}

