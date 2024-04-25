#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int n,m;
const int mxn = 808;
vector<int> paths[mxn];
bitset<mxn> goneto;

void dfs(int now){
	goneto[now] = true;
	for(auto nxt:paths[now]){
		if(goneto[nxt])continue;
		dfs(nxt);
	}
	return;
}
void solve(){
	for(int i = 0;i<m;i++){
		int a,b;cin>>a>>b;
		paths[a].push_back(b);
	}
	int s,e;
	cin>>s>>e;
	dfs(s);
	if(goneto[e])cout<<"Yes!!!\n";
	else cout<<"No!!!\n";
	for(int i = 1;i<=n;i++){
		goneto[i] = false;
		paths[i].clear();
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>m)solve();
}
