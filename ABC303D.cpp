#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

#define ll long long
const ll mxn = 3e5+10;
ll dp[mxn][2];
ll x,y,z;

void solve(){
	cin>>x>>y>>z;
	string s;
	cin>>s;
	int n = s.size();
	s = "#"+s;
	dp[0][0] = 0;
	dp[0][1] = z;
	for(int i = 1;i<=n;i++){
		if(s[i] == '#')continue;
		if(s[i] == 'A'){
			dp[i][0] = min({dp[i-1][0]+y,dp[i-1][1]+min(y,x)+z});
			dp[i][1] = min({dp[i-1][0]+z+min(y,x),dp[i-1][1]+x});
		}
		else{
			dp[i][0] = min({dp[i-1][0]+x,dp[i-1][1]+z+min(y,x)});
			dp[i][1] = min({dp[i-1][0]+z+min(y,x),dp[i-1][1]+y});
		}
	}
	//for(int i = 0;i<=n;i++)cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
	cout<<min(dp[n][0],dp[n][1]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
