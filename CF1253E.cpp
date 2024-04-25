#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
int dp[2][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector<pii> v;
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back({max(1,a-b),min(a+b,m)});
	}
	/*

   */
	sort(v.begin(),v.end(),[](pii a,pii b){
			return a.sc<b.sc;
			});
	bool roll = false;
	for(int i = 1;i<=m;i++){
		dp[roll][i] = max(v[0].fs-1,i-v[0].sc);
	}
	//cout<<v[0].fs<<' '<<v[0].sc<<":"<<dp[roll][85]<<endl;
	for(int i = 1;i<v.size();i++){
		roll ^= 1;
		for(int j = 1;j<=m;j++){
			dp[roll][j] = dp[roll^1][j];
		}
		for(int j = 0;j<=m;j++){
			int r = min(m,v[i].sc+j);
			int l = max(1,v[i].fs-j);
			dp[roll][r] = min(dp[roll][r],dp[roll^1][l-1]+j);
		}
		for(int j = m-1;j>=1;j--)dp[roll][j] = min(dp[roll][j],dp[roll][j+1]);
		//cout<<v[i].fs<<' '<<v[i].sc<<":";cout<<dp[roll][m]<<endl;
	}
	cout<<dp[roll][m];
}
//dp[i][j]
