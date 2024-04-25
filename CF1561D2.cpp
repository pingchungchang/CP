#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e6+10;
int mod;

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
int dp[mxn];
int n;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>mod;
	dp[1] = 1;
	int sum = 1;
	for(int i = 2;i<=n;i++){
		dp[i] = sum;
		int pre = 2;
		int now = 0;
		while(true){
			now = i/(i/pre)+1;
			dp[i] = mad(dp[i],1ll*(now-pre)*dp[i/pre]%mod);
			if(now == i+1)break;
			swap(pre,now);
		}
		sum = mad(sum,dp[i]);
	}
	cout<<dp[n];
}
