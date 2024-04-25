#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 220;
const int mxc = 1010;
const ll mod = 1e9+7;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

ll dp[2][mxn][mxc];
bool roll = 0;
int arr[mxn];
int n,L;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>L;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	dp[roll][1][0] = dp[roll][0][0] = 1;
	for(int i = 2;i<=n;i++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int j = 0;j<mxn-1;j++){
			for(int k = 0;k<mxc;k++){

				if(k+(arr[i]-arr[i-1])*j<=L)//start new
		dp[roll][j+1][k+(arr[i]-arr[i-1])*j] = mad(dp[roll][j+1][k+(arr[i]-arr[i-1])*j],dp[roll^1][j][k]);

				if(k+(arr[i]-arr[i-1])*j<=L)//is middle
		dp[roll][j][k+(arr[i]-arr[i-1])*j] = mad(dp[roll][j][k+(arr[i]-arr[i-1])*j],dp[roll^1][j][k]*(j+1)%mod);

				if(j&&k+(arr[i]-arr[i-1])*j<=L)//end group
		dp[roll][j-1][k+(arr[i]-arr[i-1])*j] = mad(dp[roll][j-1][k+(arr[i]-arr[i-1])*j],dp[roll^1][j][k]*j%mod);


			}
		}
		/*
		cout<<i<<":"<<endl;
		for(int j = 0;j<=n;j++){
			for(int k = 0;k<=L;k++)cout<<j<<' '<<k<<":"<<dp[roll][j][k]<<endl;//cout<<endl;
		}cout<<endl;

	   */
	}
	ll ans = 0;
	for(int i = 0;i<=L;i++)ans = mad(ans,dp[roll][0][i]);
	cout<<ans;
}
