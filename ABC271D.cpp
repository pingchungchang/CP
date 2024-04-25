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
const int mxn = 1e4+10;
pll dp[110][mxn];
pll add(pll a,pll b){
	return {a.fs+b.fs,b.sc};
}
int main(){
	io
	int n,s;
	cin>>n>>s;
	pll arr[n+1];
	dp[0][0].fs = 1;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=s;j++){
			if(j>=arr[i].fs&&dp[i-1][j-arr[i].fs].fs == 1)dp[i][j] = {1,1};
			if(j>=arr[i].sc&&dp[i-1][j-arr[i].sc].fs == 1)dp[i][j] = {1,2};
		}
	}
//	for(int j = 1;j<=n;j++){	
//		for(int i = 0;i<=s;i++){
//			cout<<dp[j][i].fs<<' ';
//		}
//		cout<<endl; 
//	}
	if(dp[n][s].fs != 1)cout<<"No";
	else{
		cout<<"Yes\n";
		string ans(n,'T');
		int now = s;
		for(int i = n;i>=1;i--){
			if(dp[i][now].sc == 1){
				ans[i-1] = 'H';
				now -= arr[i].fs;
			}
			else{
				ans[i-1] = 'T';
				now -= arr[i].sc;
			}
		}
		cout<<ans;
	}
}

