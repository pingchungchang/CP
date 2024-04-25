#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int dp[2][3];
string s;
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	string pat = "CEP";
	int ans = 0;
	do{
		bool roll = 0;
		memset(dp,0,sizeof(dp));
		dp[roll][1] = dp[roll][2] = -1e9;
		for(auto &i:s){
			roll ^= 1;
			dp[roll][0] = dp[roll^1][0]+(pat[0] == i);
			dp[roll][1] = max(dp[roll^1][0],dp[roll^1][1])+(pat[1] == i);
			dp[roll][2] = max(dp[roll^1][1],dp[roll^1][2])+(pat[2] == i);
		}
		ans = max(ans,dp[roll][2]);
	}while(next_permutation(pat.begin(),pat.end()));
	cout<<ans;
}
