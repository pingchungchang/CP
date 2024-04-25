#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2020;
int dp[mxn][mxn];
string s;
int f(int l,int r);

int check(int a,int c1,int c2){
	int flag = -1;
	int f1 = f(c1+1,c2),f2 = f(c1,c2-1);
	if(f1 == 2)return 2;
	if(f2 == 2)return 2;
	if(f1 == 0&&s[a]>s[c1])return 2;
	if(f2 == 0&&s[a]>s[c2])return 2;
	if(f1 == 0&&s[a] == s[c1])return 0;
	if(f2 == 0&&s[a] == s[c2])return 0;
	return 1;
}

int f(int l,int r){
	if(dp[l][r] != -1)return dp[l][r];
	if(r == l+1){
		if(s[l] == s[r])dp[l][r] = 0;
		else dp[l][r] = 1;
		return dp[l][r];
	}
	//get left
	int ca = check(l,l+1,r),cb = check(r,l,r-1);
	if(ca != 1&&cb != 1){
		if(ca == 0||cb == 0)dp[l][r] = 0;
		else dp[l][r] = 2;
	}
	else dp[l][r] = 1;
	return dp[l][r];
}

void solve(){
	cin>>s;
	int n = s.size();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)dp[i][j] = -1;
	}
	f(0,n-1);
	if(dp[0][n-1] == 1)cout<<"Alice\n";
	else if(dp[0][n-1] == 2)cout<<"Bob\n";
	else cout<<"Draw\n";
	/*
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)cout<<setw(2)<<dp[i][j]<<' ';
		cout<<'\n';
	}

   */
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
