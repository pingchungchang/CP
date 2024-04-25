#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,sse4,avx2")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 256;
bitset<mxn> dp[mxn][mxn];
int n,m;
int arr[mxn][mxn];

void init(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)dp[i][j].reset();
	}
	return;
}

void solve(){
	init();
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)cin>>arr[i][j];
	}
	vector<int> v;
	for(int i = 1;i*i<=arr[1][1];i++){
		if(arr[1][1]%i == 0){
			v.push_back(i);
			if(i*i != arr[1][1])v.push_back(arr[1][1]/i);
		}
	}
	sort(v.begin(),v.end());
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			for(int k = 0;k<v.size();k++){
				if(arr[i][j]%v[k] == 0)dp[i][j][k] = true;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(i == 1&&j == 1)continue;
			dp[i][j] = (dp[i-1][j]|dp[i][j-1])&dp[i][j];
		}
	}
	int ans = 1;
	for(int i = 0;i<v.size();i++){
		if(dp[n][m][i])ans = max(ans,v[i]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
