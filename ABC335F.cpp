#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
const int sq = sqrt(mxn);
const int mod = 998244353;

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
inline int mub(int a,int b){
	return mad(a,mod-b);
}

int dp[mxn][sq+10];
int A[mxn],N;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>A[i];
	dp[1][0] = 1;
	int ans = 0;
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=sq;j++)dp[i][0] = mad(dp[i][0],dp[i][j]);
		ans = mad(ans,dp[i][0]);
		for(int j = 1;j<=sq;j++){
			if(i+j<=N)dp[i+j][j] = mad(dp[i+j][j],dp[i][j]);
		}
		if(A[i]>=sq){
			for(int j = i+A[i];j<=N;j+=A[i]){
				dp[j][0] = mad(dp[j][0],dp[i][0]);
			}
		}
		else{
			if(i+A[i]<=N)dp[i+A[i]][A[i]] = mad(dp[i+A[i]][A[i]],dp[i][0]);
		}
	}
	cout<<ans;
}
