#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mod = 998244353;
const int mxn = 303;
int dp[2][mxn+2][mxn+2];
pii arr[mxn];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i = 0;i<n;i++)cin>>arr[i].fs;
	for(int i = 0;i<n;i++)cin>>arr[i].sc;
	sort(arr,arr+n);
	//for(int i = 0;i<n;i++)cout<<arr[i].sc<<' ';cout<<endl;
	bool roll = 0;
	dp[roll][0][n+1] = 1;
	for(int i = 0;i<n;i++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int j = 0;j<=k;j++){
			for(int l = 1;l<=n+1;l++){
				if(l>arr[i].sc){
					if(j)dp[roll][j][l] = dp[roll^1][j-1][l];
				}
				else if(l != arr[i].sc){
					dp[roll][j][l] = dp[roll^1][j][l];
				}
			}
			for(int l = arr[i].sc;l<=n+1;l++){
				dp[roll][j][arr[i].sc] = mad(dp[roll][j][arr[i].sc],dp[roll^1][j][l]);
			}
		}
		/*
		cout<<i<<":"<<endl;
		for(int j = 0;j<=k;j++){
			for(int l = 1;l<=n+1;l++)cout<<dp[roll][j][l]<<' ';cout<<endl;
		}
	   */
	}
	int ans = 0;
	for(int i = 0;i<=n+1;i++)ans = mad(ans,dp[roll][k][i]);
	cout<<ans;
}
