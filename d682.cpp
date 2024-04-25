#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n,p;
	cin>>m>>n>>p;
	vector<int> dp(m+1,0);
	vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>(p));
	for(int i =0 ;i<n;i++){
		for(int j =0;j<p;j++)cin>>v[i][j].first>>v[i][j].second;
		sort(v[i].begin(),v[i].end());
	}
	for(int i = 0;i<n;i++){
		for(int j = m;j>=v[i][0].first;j--){
			for(int k = 0;k<p;k++){
				int val = v[i][k].first;
				int x = v[i][k].second;
				if(val>j)continue;
				dp[j] = max(dp[j],dp[j-val]+x);
			}
		}
	}
	cout<<dp[m];	
}
