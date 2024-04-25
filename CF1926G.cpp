#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn  =1e5+10;
vector<int> tree[mxn];
int dp[mxn][2];
int N;
string s;

void dfs(int now){
	dp[now][0] = dp[now][1] = mxn;
	for(auto nxt:tree[now]){
		dfs(nxt);
	}

	int ts = 0;
	if(s[now] != 'P'){
		ts = 0;
		for(auto nxt:tree[now]){
			ts += min(dp[nxt][0],dp[nxt][1]+1);
		}
		dp[now][0] = ts;
	}
	if(s[now] != 'S'){
		ts = 0;
		for(auto nxt:tree[now]){
			ts += min(dp[nxt][1],dp[nxt][0]+1);
		}
		dp[now][1] = ts;
	}
	return;
}

void solve(){
	for(int i = 0;i<=N;i++)tree[i].clear();
	cin>>N;
	for(int i = 2;i<=N;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
	}
	cin>>s;
	s = "#"+s;
	dfs(1);
	cout<<min(dp[1][0],dp[1][1])<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
