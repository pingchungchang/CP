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


int main(){
	io
	int n;
	cin>>n;
	ld dp[1<<n];
	memset(dp,0.0,sizeof(dp));
	ld arr[n][n];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			int k;
			cin>>k;
			arr[i][j] = k/100.0;
		}
	}
	dp[0] = 1.0;
	for(int i = 1;i<(1<<n);i++){
		int cnt = 0;
		int tmp = i;
		while(tmp){
			if(tmp&1)cnt++;
			tmp>>=1;
		}
		for(int j = 0;j<n;j++){
			if(i&(1<<j)){
				dp[i] = max(dp[i],dp[i^(1<<j)]*arr[cnt-1][j]);
			}
		}
//		if(i == 1)cout<<dp[i]<<endl;
	}
//	for(int i = 0;i<n;i++)cout<<dp[i]<<' ';
	cout<<fixed<<setprecision(2)<<dp[(1<<n)-1]*100;
}

