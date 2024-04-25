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
const int mxn = 1e4+10;
pii dp[mxn];
int start[mxn];
int main(){
	io
	int n,w;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int s,e,v;
		cin>>s>>e>>v;
		start[i] = s;
		if(dp[e].fs<dp[s-1].fs+v){
			dp[e] = {dp[s-1].fs+v,i};
		}
		for(int j = e;j<mxn;j++)dp[j] = max(dp[j],dp[j-1]);
	}
	vector<int> all;
	int now = mxn-1;
	while(dp[now].sc != 0){
		all.push_back(dp[now].sc);
		now = start[dp[now].sc];
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	cout<<dp[mxn-1].fs<<' '<<all.size()<<'\n';
	for(auto i:all)cout<<i<<' ';
}

