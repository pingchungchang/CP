#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
vector<int> tree[mxn];
int dp[mxn];
int n;
int ans;

void dfs(int now){
	dp[now] = 1;
	for(auto nxt:tree[now]){
		dfs(nxt);
		dp[now] += dp[nxt];
	}
	return;
}

void dfs1(int now,int done){
	done = max(0,done-1);
	vector<pii> v;
	int sum = 0;
	for(auto nxt:tree[now]){
		sum += dp[nxt];
		v.push_back({dp[nxt],nxt});
	}
	sort(v.rbegin(),v.rend());
	if(v.empty())return;
	//cout<<now<<":"<<done<<' '<<sum<<','<<v[0].fs<<' '<<ans<<endl;
	if(v[0].fs-done<=sum-v[0].fs){
		ans += (sum-done)/2;
		return;
	}
	else{
		ans += sum-v[0].fs;
		done += sum-v[0].fs;
		dfs1(v[0].sc,done);
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)tree[i].clear();
	cin>>n;
	for(int i = 2;i<=n;i++){
		int k;
		cin>>k;
		tree[k].push_back(i);
	}
	ans = 0;
	dfs(1);
	dfs1(1,0);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
