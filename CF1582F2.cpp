#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 5040+10;
vector<int> v[mxn*4];
int n;
int dp[2][mxn*2];
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		v[k].push_back(i);
	}
	bool roll = false;
	for(auto &i:dp[roll])i = 1e9;
	dp[roll][0] = 0;
	for(int i = 0;i<mxn;i++){
		roll ^= 1;
		for(int j = 0;j<mxn*2;j++)dp[roll][j] = dp[roll^1][j];
		for(int j = 0;j<mxn*2;j++){
			if((j^i)>=mxn*2)continue;
			auto it = upper_bound(v[i].begin(),v[i].end(),dp[roll][j]);
			if(it == v[i].end())continue;
			dp[roll][j^i] = min(dp[roll][j^i],*it);
		}
	}
	for(int i = 0;i<mxn*2;i++){
		if(dp[roll][i]<mxn*1000)ans.push_back(i);
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}
