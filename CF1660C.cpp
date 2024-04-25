#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	string s;
	cin>>s;
	int n = s.size();
	int dp[n] = {};
	map<char,int> mp;
	mp[s[0]] = 0;
	for(int i= 1;i<n;i++){
		dp[i] = dp[i-1];
		if(mp.count(s[i]) == 0){
			mp[s[i]] = i;
			continue;
		}
		int pre = mp[s[i]];
		if(pre != 0)dp[i] = max(dp[i],dp[pre-1]+1);
		else dp[i] = max(dp[i],1);
		mp[s[i]] = i;
	}
//	for(auto i:dp)cout<<i<<' ';
	cout<<s.size()-2*dp[n-1]<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

