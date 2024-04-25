#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
bitset<mxn> done;
vector<int> paths[mxn];
int dep[mxn];
void dfs(int now){
	done[now] = true;
	for(auto nxt:paths[now]){
		if(done[nxt])continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt);
	}
	return;
}

void solve(){
	int n;
	cin>>n;
	int cen = 0;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		if(paths[i].size() == 1)cen = paths[i][0];
	}
	dfs(cen);
	vector<int> ans;
	for(int i = 1;i<=n;i++){
		if(dep[i]%3 == 0)ans.push_back(paths[i].size());
	}
	sort(ans.begin(),ans.end());
	for(auto &i:ans)cout<<i<<' ';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
