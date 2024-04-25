#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 5050;
int n;
long double dp[2][mxn];
long double pw[mxn],pwsum[mxn];
int arr[mxn];

inline long double calc(long double sum,int t){
	return sum/pwsum[t-1]-1200/sqrt(t);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	reverse(arr,arr+n);

	pw[0] = 1;
	for(int i = 1;i<mxn;i++)pw[i] = pw[i-1]*0.9;
	pwsum[0] = pw[0];
	for(int i = 1;i<mxn;i++)pwsum[i] = pw[i]+pwsum[i-1];

	bool roll = 0;
	for(auto &i:dp[roll])i = -1e9;
	dp[roll][0] = 0;
	for(int i = 0;i<n;i++){
		roll ^= 1;
		for(auto &j:dp[roll])j = -1e9;
		for(int j = 0;j<=i+1;j++){
			dp[roll][j] = dp[roll^1][j];
			if(j)dp[roll][j] = max(dp[roll][j],dp[roll^1][j-1]+pw[j-1]*arr[i]);
		}
		//cout<<arr[i]<<":";for(int j = 0;j<=n;j++)cout<<dp[roll][j]<<' ';cout<<endl;
	}

	long double ans = -1e9;
	for(int i = 1;i<=n;i++)ans = max(ans,calc(dp[roll][i],i));
	cout<<fixed<<setprecision(10)<<ans;
}
