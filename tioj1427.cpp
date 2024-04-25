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
#define int short
#pragma GCC optimize("O2")
const int mxn = 5050;
int dp[2][mxn][11][2];
main(){
	io
	int n,m,k;
	cin>>n>>m>>k;
	string a,b;
	cin>>a>>b;
	short now = 0;
	short ans = 0;
	for(int i = 0;i<a.size();i++){
		now ^=1;
		for(int j = 0;j<b.size();j++){
			for(int l = 1;l<=k;l++){
				if(a[i] == b[j]){
					if(i == 0||j == 0){
						dp[now][j][l][1] = (a[i] == 'a'?2:0);
					}
					else{
						dp[now][j][l][1] = max(dp[now^1][j-1][l][1],dp[now^1][j-1][l-1][0])+(a[i] == 'a'?2:0);
					}
				}
				else{
					dp[now][j][l][1] = 0;
				}
				dp[now][j][l][0] = max({dp[now][j][l][1],dp[now][j][l-1][0],dp[now^1][j][l][0]});
				if(j != 0)dp[now][j][l][0] = max({dp[now][j][l][0],dp[now][j-1][l][0]});
				ans = max(ans,dp[now][j][l][0]);
				ans = max(ans,dp[now][j][l][1]);
				cout<<dp[now][j][l][0]<<' ';
			}
//			cout<<endl;
		}
//		cout<<endl;
	}
	
	cout<<ans;
}
//dp[i][j][l];

