#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

short dp[mxn][mxn];
pair<short,short> pre[mxn][mxn];
char lst[mxn][mxn];

void solve(){
	string a,b;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i  = 0;i<a.size();i++){
		for(int j = 0;j<b.size();j++){
			dp[i][j] = 0;
			pre[i][j] = {-1,-1};
			lst[i][j] = 0;
		}
	}
	if(a[0] == b[0])dp[0][0] = 1;
	for(int i = 1;i<a.size();i++){
		dp[i][0] = dp[i-1][0];
		if(a[i] == b[0])dp[i][0] = 1;
	}
	for(int i = 1;i<b.size();i++){
		dp[0][i] = dp[0][i-1];
		if(a[0] == b[i])dp[0][i] = 1;
	}
	for(int i = 1;i<a.size();i++){
		for(int j = 1;j<b.size();j++){
			if(dp[i-1][j] == dp[i][j-1]){
				if(lst[i-1][j]<lst[i][j-1])lst[i][j] = lst[i-1][j],pre[i][j] = {i-1,j};
				else lst[i][j] = lst[i][j-1],pre[i][j] = {i,j-1};
			}
			else if(dp[i-1][j]<dp[i][j-1])pre[i][j] = {i,j-1},dp[i][j] = dp[i][j-1];
			else pre[i][j] = {i-1,j},dp[i][j] = dp[i-1][j];
			if(a[i] == b[j]){
				if(dp[i-1][j-1]+1>dp[i][j]){
					dp[i][j] = dp[i-1][j-1]+1;
					lst[i][j] = a[i];
					pre[i][j] = {i-1,j-1};
				}
				else if(dp[i-1][j-1] == dp[i][j]){
					if(a[i] < lst[i][j]){
						lst[i][j] = a[i];
						pre[i][j] = {i-1,j-1};
					}
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
