#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxN = 1010;
const int mxM = 12;
const int mod = 998244353;
int dp[mxN][mxM][mxM][mxM];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		dp[1][i][11][11] = 1;
	}

	for(int i = 2;i<=n;i++){
		//cout<<i-1<<":";for(int j = 1;j<=m;j++)cout<<dp[i-1][j][11][11]<<' ';cout<<endl;
		for(int now = 1;now<=m;now++){
			for(int p1 = 1;p1<=m;p1++){
				for(int p2 = p1+1;p2<=m;p2++){
					for(int p3 = p2+1;p3<=m;p3++){
						if(p1>=now)
							dp[i][now][p2][p3] = mad(dp[i][now][p2][p3],dp[i-1][p1][p2][p3]);
						else if(p1<now&&p2>=now)
							dp[i][p1][now][p3] = mad(dp[i][p1][now][p3],dp[i-1][p1][p2][p3]);
						else if(p2<now&&p3>=now)
							dp[i][p1][p2][now] = mad(dp[i][p1][p2][now],dp[i-1][p1][p2][p3]);
					}
					if(p1>=now)
						dp[i][now][p2][11] = mad(dp[i][now][p2][11],dp[i-1][p1][p2][11]);
					else if(p2>=now)
						dp[i][p1][now][11] = mad(dp[i][p1][now][11],dp[i-1][p1][p2][11]);
					else if(now>p2)
						dp[i][p1][p2][now] = mad(dp[i][p1][p2][now],dp[i-1][p1][p2][11]);
				}
				if(p1>=now)
					dp[i][now][11][11] = mad(dp[i][now][11][11],dp[i-1][p1][11][11]);
				if(p1<now)
					dp[i][p1][now][11] = mad(dp[i][p1][now][11],dp[i-1][p1][11][11]);
			}
		}
	}

	int ans = 0;
	for(int p1 = 1;p1<=m;p1++){
		for(int p2 = p1+1;p2<=m;p2++){
			for(int p3 = p2+1;p3<=m;p3++){
				ans = mad(ans,dp[n][p1][p2][p3]);
			}
		}
	}
	cout<<ans;
}
