#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;

void solve(){
	string s;
	cin>>s;
	vector<pair<char,int>> v;
	int n = s.size();
	pll dp[n+1];
	dp[0] = {0,1};
	dp[1] = {1,0};
	for(int i = 2;i<=n;i++){
		dp[i].fs = dp[i-1].fs+dp[i-1].sc;
		dp[i].sc = dp[i-1].fs;
		if(dp[i].fs>=mod)dp[i].fs-=mod;
	}
	for(auto &i:s){
		if(v.empty()||v.back().fs != i)v.push_back({i,1});
		else v.back().sc++;
	}
	ll ans = 1;
	for(auto &i:v){
		if(i.fs == 'm'||i.fs == 'w')ans = 0;
		if(i.fs != 'u'&&i.fs != 'n')continue;
		ans = ans*(dp[i.sc].fs+dp[i.sc].sc)%mod;
	}
	cout<<ans;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
