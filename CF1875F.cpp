#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ld long double

int n,m;
const int mxn = 5050;
vector<int> paths[mxn];
ld dp[mxn];
ld chance[mxn][mxn];

void solve(){
	for(int i = 0;i<=n;i++)paths[i].clear();
	cin>>n>>m;
	dp[n] = 1;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
	for(int i = n-1;i>=1;i--){
		dp[i] = 0;
		for(auto &j:paths[i]){
			dp[i] += dp[j]/1.0/paths[i].size();
		}
	}
	for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
	cout<<fixed<<setprecision(10)<<dp[1]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	chance[1][1] = 1;
	for(int i = 2;i<mxn;i++){
		ld pref = 0;
		for(int j = 1;j<=(i+1)/2;j++){
			dp[i][j] = (1-pref)
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
