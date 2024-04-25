#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll

const int mxn = 2e5+10;
int n,m;
vector<int> tree[mxn];
int num[mxn],arr[mxn];
pii dp[mxn];
bool flag = true;

void dfs(int now,int par){
	pii tmp = {0,0};
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		num[now] += num[nxt];
		tmp.fs += dp[nxt].fs;
		tmp.sc += dp[nxt].sc;
	}
	if((num[now]+arr[now])&1)flag = false;
	if(num[now]+arr[now]<0||num[now]-arr[now]<0)flag = false;
	dp[now].fs = (num[now]+arr[now])/2;
	dp[now].sc = num[now]-dp[now].fs;
	if(dp[now].fs<tmp.fs)flag = false;
	return;
}

void solve(){
	flag = true;
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		num[i] = arr[i] = dp[i].fs = dp[i].sc = 0;
	}
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>num[i];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
