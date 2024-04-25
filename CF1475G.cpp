#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> pre[mxn];
int dp[mxn];

void solve(){
	int n;
	cin>>n;
	vector<int> vv(n);
	for(auto &i:vv)cin>>i;
	sort(vv.begin(),vv.end());
	vector<pii> v;
	for(auto &i:vv){
		if(v.empty()||v.back().fs != i)v.push_back({i,1});
		else v.back().sc++;
	}
	int ans = n-1;
	for(auto &i:v){
		dp[i.fs] = i.sc;
		for(auto &j:pre[i.fs])dp[i.fs] = max(dp[i.fs],dp[j]+i.sc);
		ans = min(ans,n-dp[i.fs]);
	}
	for(auto &i:v)dp[i.fs] = 0;
	cout<<ans<<'\n';
	return;
}

int main(){
	for(int i = 1;i<mxn;i++){
		for(int j = i+i;j<mxn;j+=i)pre[j].push_back(i);
	}
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
