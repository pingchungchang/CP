#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 330;
string s;
int del;
int dp[mxn][mxn];
int dp2[mxn];

int f(int l,int r){
	if(l>=r)return dp[l][r] = 0;
	if(dp[l][r] != -1)return dp[l][r];
	dp[l][r] = r-l;
	if(s[l] == 'o'){
		for(int i = l+1;i<r;i++){
			if(s[i] == 'f'&&f(l+1,i)==0)dp[l][r] = min(max(0,f(i,r)-del-1),dp[l][r]);
		}
	}
	for(int i = l+1;i<=r;i++){
		dp[l][r] = min(dp[l][r],f(l,i)+f(i,r));
	}
	return dp[l][r];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>del;
	memset(dp,-1,sizeof(dp));
	int n = s.size();
	s = "#"+s;
	cout<<f(1,n+1);
}
/*
offffocfofoocffofoffff
1
*/
