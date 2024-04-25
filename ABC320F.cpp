//failed
#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 330;
const int inf = 1e9+10;
int dp[2][mxn][mxn];
int buf[mxn][mxn];
int s = 0,e;
int pos[mxn];
pii arr[mxn];
int n,H;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	bool roll = false;
	cin>>n>>H;
	for(int i = 1;i<=n;i++)cin>>pos[i];
	for(int i = 1;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 1;i<=n;i++){
		if(pos[i]-pos[i-1]>=H){
			cout<<-1;
			return 0;
		}
	}
	for(auto &i:dp[roll])for(auto &j:i)j = inf;
	for(int i = 0;i<=H;i++)dp[roll][i][i] = 0;
	for(int i = n-1;i>=0;i--){
		int d = pos[i+1]-pos[i];
		roll ^= 1;
		for(auto &j:dp[roll])for(auto &k:j)k = inf;
		for(int j = 0;j<=H;j++){
			for(int k = 0;k<=H;k++){
				if(j-d>=0&&k+d<=H)dp[roll][j][k] = min(dp[roll][j][k],dp[roll^1][j-d][k+d]);
			}
		}
		for(auto &j:buf)for(auto &k:j)k = inf;
		for(int j = H;j>=0;j--){
			for(int k = 0;k<=H;k++){
				buf[j][k] = min(buf[j][k],dp[roll][min(H,j+arr[i].sc)][k]+arr[i].fs);
				if(k>=arr[i].sc)buf[j][k] = min(buf[j][k],dp[roll][j][k-arr[i].sc]+arr[i].fs);
			}
		}
		for(int j = 0;j<=H;j++)for(int k = 0;k<=H;k++)dp[roll][j][k] = min(dp[roll][j][k],buf[j][k]);
		cout<<i<<":"<<endl;for(int j = 0;j<=H;j++){
			for(int k = 0;k<=H;k++){
				cout<<j<<' '<<k<<":"<<(dp[roll][j][k] == inf?-1:dp[roll][j][k])<<' ';
				cout<<endl;
			}
		}cout<<endl;

		/*
	   */

	}
	int ans = *min_element(dp[roll][H],dp[roll][H]+H+1);
	cout<<(ans>=inf?-1:ans);
}
