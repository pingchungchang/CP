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
ld dp[110][110][110];
int main(){
//	io
	ll a,b,c;
	cin>>a>>b>>c;
	dp[a][b][c] = 1;
	for(int i = a;i<100;i++){
		for(int j = b;j<100;j++){
			for(int k = c;k<100;k++){
				dp[i][j][k+1] += dp[i][j][k]*k/(i+j+k);
				dp[i][j+1][k] += dp[i][j][k]*j/(i+j+k);
				dp[i+1][j][k] += dp[i][j][k]*i/(i+j+k);
			}
		}
	}
	ld ans = 0;
	ld total = 0;
	for(int i = 0;i<=100;i++){
		for(int j = 0;j<=100;j++){
			ans += dp[i][j][100];
			ans += dp[i][100][j];
			ans += dp[100][i][j];
			total += (dp[i][j][100]+dp[i][100][j]+dp[100][i][j])*(i+j+100-a-b-c);
		}
		ans -= dp[i][100][100];
		ans -= dp[100][100][i];
		ans -= dp[100][i][100];
		total -= (dp[i][100][100]+dp[100][100][i]+dp[100][i][100])*(i+100+100-a-b-c);
	}
	ans -= 2*dp[100][100][100]*300;
	cout<<fixed<<setprecision(10)<<(ld)total/ans;
//	while(cin>>a>>b>>c)cout<<dp[a][b][c]<<endl;
}

