#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
int deg[mxn],idx[mxn];
int n,m;

void solve(){
	for(int i = 0;i<=n;i++){
		paths[i].clear();
		deg[i] = idx[i] = 0;
	}
	cin>>n>>m;
	vector<pii> edges,ans;
	for(int i = 0;i<m;i++){
		int t,a,b;
		cin>>t>>a>>b;
		if(t == 1){
			paths[a].push_back(b);
			ans.push_back({a,b});
			deg[b]++;
		}
		else edges.push_back({a,b});
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	int c = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		idx[now] = ++c;
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt]){
				q.push(nxt);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(deg[i]){
			cout<<"NO\n";
			return;
		}
	}
	for(auto &i:edges){
		if(idx[i.fs]>idx[i.sc])swap(i.fs,i.sc);
		ans.push_back(i);
	}
	cout<<"YES\n";
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
