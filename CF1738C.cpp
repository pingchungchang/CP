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
const ll mxn = 110;

int dp[mxn][mxn][2][2];

void f(int i,int j,int s,int p){
	if(dp[i][j][s][p] != 0)return;
	bool flag = false;
	if(i != 0){
		if(p == 0){
			f(i-1,j,s^1,p^1);
			if(dp[i-1][j][s^1][p^1] == -1)flag = true;
		}
		else{
			f(i-1,j,s,p^1);
			if(dp[i-1][j][s][p^1] == -1)flag = true;
		}
	}
	if(j != 0){
		f(i,j-1,s,p^1);
		if(dp[i][j-1][s][p^1] == -1)flag = true;
	}
	if(flag)dp[i][j][s][p] = 1;
	else dp[i][j][s][p] = -1;
//	cout<<i<<' '<<j<<' '<<s<<' '<<p<<' '<<dp[i][j][s][p]<<'\n';
	return;
}
void solve(){
	int n;
	cin>>n;
	pii p = {0,0};
	while(n--){
		int tmp;
		cin>>tmp;
		if((to_string(tmp).back()-'0')&1)p.fs++;
		else p.sc++;
	}
	f(p.fs,p.sc,0,0);
//	cout<<p.fs<<' '<<p.sc<<'\n';
	if(dp[p.fs][p.sc][0][0] == -1)cout<<"Bob";
	else cout<<"Alice";
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	//dp[oddcnt][evcnt][sumcnt][turn]
	// 1000 1001 1010 1011 0100 0101 0110 0111
	dp[1][0][0][0] = -1;dp[1][0][0][1] = -1;dp[1][0][1][0] = 1;dp[1][0][1][1] = 1;
	dp[0][1][0][0] = 1;dp[0][1][0][1] = -1;dp[0][1][1][0] = -1;dp[0][1][1][1] = 1;
//	for(int i = 0;i<mxn;i++)for(int j = 0;j<mxn;j++)for(int k = 0;k<2;k++)if(dp[i][j][k][0] == -1)cout<<i<<' '<<j<<' '<<k<<endl;
	while(t--)solve();
}

