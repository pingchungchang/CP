#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

typedef tree<pii,null_type,greater<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mxn = 1e5+10;
vector<int> paths[mxn];
int n;
int arr[mxn];
pii val[mxn];
int dep[mxn],dp[mxn];
ordered_set st;
int C = 0;

void dfs(int now,int par){
	val[now] = make_pair(arr[now],C++);
	st.insert(val[now]);
	if(now != par&&paths[now].size() == 1){
		if(st.size()&1)dp[now] = st.find_by_order(st.size()/2)->fs*2;
		else dp[now] = (st.find_by_order(st.size()/2)->fs+st.find_by_order(st.size()/2-1)->fs);
		//cout<<now<<":";for(auto &i:st)cout<<i.fs<<',';cout<<endl;
		st.erase(val[now]);
		return;
	}
	if(dep[now]&1)dp[now] = 2e9;
	else dp[now] = -1;
	for(auto nxt:paths[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt,now);
		if(dep[now]&1)dp[now] = min(dp[now],dp[nxt]);
		else dp[now] = max(dp[now],dp[nxt]);
	}
	st.erase(val[now]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	dfs(1,1);
	//for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
	cout<<dp[1]/2;
}
