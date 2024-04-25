#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	io
	int dp[10010];
	memset(dp,10001,sizeof(dp));
	dp[1] = 0;
	dp[0] = 0;
	for(int i = 1;i<=10001;i++){
		for(int j = i+1;j<=min(2*i,10001);j++){
			dp[j] = min(dp[j],dp[i]+1);
		}
	}
	int t = 0;
	int n;
	while(cin>>n){
		if(n <0)return 0;
		t++;
		cout<<"Case "<<t<<": "<<dp[n]<<'\n';
	}
}
