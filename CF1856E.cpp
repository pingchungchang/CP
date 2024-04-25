#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n;
const int mxn = 5050;
vector<int> tree[mxn];
bitset<mxn> dp;
int sz[mxn];
ll ans =0;

void dfs(int now){
	sz[now] = 0;
	vector<int> v;
	for(auto nxt:tree[now]){
		dfs(nxt);
		sz[now] += sz[nxt];
		v.push_back(sz[nxt]);
	}
	dp.reset();
	dp[0] = 1;
	for(auto &i:v)dp|=dp<<i;
	ll lsum = 0;
	for(int i = 0;i+i<=sz[now];i++)if(dp[i])lsum = i;
	ll rsum = sz[now]-lsum;
	//cout<<now<<":"<<sz[now]<<' '<<lsum<<' '<<rsum<<endl;
	ans += lsum*rsum;
	sz[now]++;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
	}
	dfs(1);
	cout<<ans;
}
