#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 210;
const int mod = 998244353;
int dp[2][mxn][mxn];
string arr[mxn];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)cin>>arr[i],arr[i] = "#"+arr[i];
	bool roll = 0;
	dp[roll][1][k] = 1;
	for(int i = 1;i<=n;i++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int j = 1;j<=m;j++){
			if(arr[i][j] == '#')continue;
			int sh = (arr[i][j] == 'o');
			for(int h = 0;h<=k;h++){
				if(h-sh<0)continue;
				dp[roll][j][h-sh] = mad(dp[roll^1][j][h],dp[roll][j-1][h]);
			}
		}
	}
	int sum = 0;
	for(int i = 1;i<=k;i++)sum = mad(sum,dp[roll][m][i]);
	cout<<sum;
}
