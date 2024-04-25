#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double

const ll mxn = 1e4+50;
const ll inf = 1e18;

ld dp[mxn][40];
pll arr[mxn];
ll n;

inline ld dist(pll a,pll b){
	return sqrt((a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc));
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(auto &i:dp)for(auto &j:i)j = inf;
	dp[0][0] = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=30;j++){
			for(int k = 0;k+j<=30;k++){
				dp[i+k+1][j+k] = min(dp[i+k+1][j+k],dp[i][j]+dist(arr[i],arr[i+k+1]));
			}
		}
	}
	ld ans = dp[n-1][0];
	for(int i = 1;i<=30;i++){
		ans = min(ans,dp[n-1][i]+pow(2,i-1));
	}
	cout<<fixed<<setprecision(10)<<ans;
}
