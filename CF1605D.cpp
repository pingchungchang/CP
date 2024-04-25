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
int ans[mxn],dep[mxn];
int n;
vector<int> v[2];
bitset<mxn> done;

void dfs(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt,now);
	}
	v[dep[now]&1].push_back(now);
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)tree[i].clear();
	for(int i = 0;i<=n;i++)done[i] = false;
	for(int i = 0;i<=n;i++)v[i].clear();
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dep[1] = 1;
	dfs(1,1);
	if(v[0].size()>v[1].size())swap(v[0],v[1]);
	for(int i = 20;i>=0;i--){
		if(v[0].size()&(1<<i)){
			for(int j = 0;j<(1<<i);j++){
				ans[v[0].back()] = (1<<i)+j;
				done[(1<<i)+j] = true;
				v[0].pop_back();
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(!done[i]){
			ans[v[1].back()] = i;
			v[1].pop_back();
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
