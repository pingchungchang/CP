#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n,m;
	cin>>n>>m;
	map<string,int> mp;
	map<string,pii> mp1;
	string v[n];
	for(auto &i:v)cin>>i;
	string s;
	cin>>s;
	for(int i = 0;i<n;i++){
		for(int j = 1;j<m;j++){
			mp[v[i].substr(j-1,2)] = i+1;
			mp1[v[i].substr(j-1,2)] = {j,j+1};
		}
		for(int j = 2;j<m;j++){
			mp[v[i].substr(j-2,3)] = i+1;
			mp1[v[i].substr(j-2,3)] = {j-1,j+1};
		}
	}
	int dp[m] = {};
	if(s.size()<2){
		cout<<"-1\n";
		return;
	}
	if(mp[s.substr(0,2)] != 0){
		dp[1] = 2;
	}
	if(s.size()>2&&mp[s.substr(0,3)] != 0)dp[2] = 3;
	for(int i = 3;i<m;i++){
		if(dp[i-2] != 0&&mp[s.substr(i-1,2)] != 0)dp[i] = 2;
		if(dp[i-3] != 0&&mp[s.substr(i-2,3)] != 0)dp[i] = 3;
	}
	if(dp[m-1] == 0){
		cout<<"-1\n";
		return;
	}
	int now = m-1;
	vector<pair<int,pii>> ans;
	while(now > 0){
		string tmp = s.substr(now-dp[now]+1,dp[now]);
		ans.push_back({mp[tmp],mp1[tmp]});
		now -= dp[now];
	}
	reverse(_all(ans));
	cout<<ans.size()<<'\n';
	string ss;
	for(auto &i:ans){
		cout<<i.sc.fs<<' '<<i.sc.sc<<' '<<i.fs<<'\n';
//		ss += v[i.fs-1].substr(i.sc.fs-1,i.sc.sc-i.sc.fs+1);
	}
//	cout<<ss<<"\n\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

