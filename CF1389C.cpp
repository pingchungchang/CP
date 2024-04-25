#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int ans = 2;
	for(char a = '0';a<='9';a++){
		for(char b = '0';b<='9';b++){
			int dp[2] = {};
			dp[0] = -1e9;
			for(auto &i:s){
				int tmp[] = {dp[0],dp[1]};
				if(i == a)tmp[0] = dp[1]+1;
				if(i == b)tmp[1] = dp[0]+1;
				dp[0] = max(dp[0],tmp[0]);
				dp[1] = max(dp[1],tmp[1]);
			}
			ans = max(ans,dp[1]);
			if(a == b)ans = max(ans,dp[0]);
		}
	}
	cout<<s.size()-ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
