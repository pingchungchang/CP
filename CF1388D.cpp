#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll


const int mxn = 2e5+10;
vector<int> paths[mxn];
int deg[mxn];
int dp[mxn];
int n;
int arr[mxn];
vector<int> v,rv;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>dp[i];
		arr[i] = dp[i];
	}
	for(int i = 0;i<n;i++){
		int p;
		cin>>p;
		p--;
		if(p < 0)continue;
		paths[i].push_back(p);
		deg[p]++;
	}
	ll ans = 0;
	queue<int> q;
	for(int i = 0;i<n;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		ans += dp[now];
		if(dp[now]>=0)v.push_back(now);
		else rv.push_back(now);
		for(auto nxt:paths[now]){
			dp[nxt] += max(0LL,dp[now]);
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	cout<<ans<<'\n';
	reverse(rv.begin(),rv.end());
	for(auto &i:v)cout<<i+1<<' ';for(auto &i:rv)cout<<i+1<<' ';
}
