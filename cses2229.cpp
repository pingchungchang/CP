#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 505;
const int mod = 1e9+7;
int dp[2][mxn*mxn];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
inline int mub(int a,int b){
	return mad(a,mod-b);
}

inline int sum(int row,int l,int r){
	if(l<=0)return dp[row][r];
	else return mub(dp[row][r],dp[row][l-1]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	bool roll = 0;
	for(auto &i:dp[roll])i = 1;
	for(int i = 1;i<=n;i++){
		roll ^= 1;
		for(int j = 0;j<=k;j++){
			int rest = n-i;
			dp[roll][j] = sum(roll^1,j-rest,j);
		}
		for(int j = 1;j<=k;j++)dp[roll][j] = mad(dp[roll][j],dp[roll][j-1]);
	}
	cout<<(k?mub(dp[roll][k],dp[roll][k-1]):1);
}
