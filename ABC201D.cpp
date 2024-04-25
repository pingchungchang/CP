#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3030;
int dp[mxn][mxn];
string arr[mxn];
int n,m;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = n-2;i>=0;i--){
		dp[i][m-1] = dp[i+1][m-1];
		if((i+m)&1)dp[i][m-1] += (arr[i+1][m-1] == '+'?1:-1);
		else dp[i][m-1] += (arr[i+1][m-1] == '-'?1:-1);
	}
	for(int i = m-2;i>=0;i--){
		dp[n-1][i] = dp[n-1][i+1];
		if((n+i)&1)dp[n-1][i] += (arr[n-1][i+1] == '+'?1:-1);
		else dp[n-1][i] += (arr[n-1][i+1] == '-'?1:-1);
	}
	for(int i = n-2;i>=0;i--){
		for(int j = m-2;j>=0;j--){
			if(!((i+j)&1))dp[i][j] = max(dp[i+1][j]+(arr[i+1][j]=='+'?1:-1),dp[i][j+1]+(arr[i][j+1] == '+'?1:-1));
			else dp[i][j] = min(dp[i+1][j]+(arr[i+1][j] == '-'?1:-1),dp[i][j+1]+(arr[i][j+1] == '-'?1:-1));
		}
	}
	cout<<(dp[0][0] == 0?"Draw":dp[0][0]>0?"Takahashi":"Aoki");
}
