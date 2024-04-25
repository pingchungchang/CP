#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
int n,x;
vector<vector<int>> dp;
int main(){
	cin>>n>>x;
	v = vector<pair<int,int>>(n);
	dp = vector<vector<int>>(n+1,vector<int>(x+1));
	for(int i = 0;i<n;i++)cin>>v[i].first>>v[i].second;
	dp[0][0] = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=x;j++){
			if(dp[i][j] == 1){
				if(j+v[i].first<=x){
					dp[i+1][j+v[i].first] = 1;
				}
				if(j+v[i].second<=x)dp[i+1][j+v[i].second] = 1;
			}
		}
	}
	if(dp[n][x] == 1)cout<<"Yes";
	else cout<<"No";
	return 0;
}
