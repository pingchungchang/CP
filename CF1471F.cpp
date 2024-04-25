#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3e5+10;
bool col[mxn],vis[mxn];
vector<int> paths[mxn];
int n,m;

void dfs(int now,int c){
	vis[now] = true;
	col[now] = c;
	if(c == 1){
		for(auto &i:paths[now])col[i] = 0;
		for(auto &i:paths[now])if(!vis[i])dfs(i,0);
	}
	else{
		for(auto &i:paths[now]){
			if(col[i] == 1&&!vis[i])dfs(i,1);
		}
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++){
		paths[i].clear();
		col[i] = vis[i] = false;
	}
	cin>>n>>m;
	fill(col,col+n+1,1);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	dfs(1,1);
	vector<int> ans;
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			cout<<"NO\n";
			return;
		}
		if(col[i])ans.push_back(i);
	}
	cout<<"YES\n";cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
