#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define big (INT_MAX)
vector<vector<int>> paths;
int n,m;
map<int,ll> mp;
int main(){
	cin>>n>>m;
	paths = vector<vector<int>>(n);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	vector<vector<ll>> dp(n,vector<ll>(1<<n,big));
//	for(int i = 0;i<n;i++){
//		for(int j = 0;j<(1<<n);j++)cout<<dp[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i = 0;i<n;i++)dp[i][0] = 0;
	for(int i = 0;i<=2*n;i++){
		for(int j = 0;j<n;j++){
			for(int k = 0;k<(1<<n);k++){
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[j][k]<<endl;
				if(dp[j][k] < big){
					for(auto nxt:paths[j]){
						ll val = dp[j][k]+1;
						dp[nxt][k^(1<<nxt)] = min(dp[nxt][k^(1<<nxt)],val);
					}
				}
			}
		}
	}
	vector<ll> ans(1<<n,INT_MAX);
	for(int i = 0;i<n;i++){
		for(int j= 0;j<(1<<n);j++){
			ans[j] = min(ans[j],dp[i][j]);
		}
	}
	ll sum = 0;
	for(auto i:ans){
//		cout<<i<<' ';
		sum += i;
	}
	cout<<sum;
}

