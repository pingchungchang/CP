#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
vector<pii> paths[mxn];
pii ans[mxn*2];
int dep[mxn*2];

void dfs(int now){
	for(auto nxt:paths[now]){
		if(!dep[nxt.fs]){
			dep[nxt.fs] = dep[now]+1;
			dfs(nxt.fs);
		}
		if(dep[nxt.fs]>=dep[now]){
			ans[nxt.sc] = {now,nxt.fs};
		}
		else ans[nxt.sc] = {nxt.fs,now};
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back({b,i});
		paths[b].push_back({a,i});
	}
	for(int i = 1;i<=n;i++){
		if(!dep[i]){
			dep[i] = 1;
			dfs(i);
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i].fs<<' '<<ans[i].sc<<'\n';
	}
	return 0;
}
