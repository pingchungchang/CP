#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const int mxn = 1e5+10;
struct edge{
	int s,e;
	int id;
	edge(){}
	edge(int ss,int ee,int ii){
		s = ss,e = ee,id = ii;
	}
};
vector<edge> paths[mxn];
int low[mxn];
int idx[mxn];
int cnt = 1;
vector<pii> ans;
void dfs(int now,int par){
	low[now] = idx[now] = cnt++;
	for(auto nxt:paths[now]){
		if(nxt.e == par)continue;
		if(low[nxt.e]){
			low[now] = min(low[now],low[nxt.e]);
		}
		else{
			dfs(nxt.e,now);
			low[now] = min(low[now],low[nxt.e]);
			if(idx[now]<low[nxt.e]){
				ans.push_back({min(now,nxt.e),max(now,nxt.e)});
			}
		}
	}
	return;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(edge(a,b,i+1));
		paths[b].push_back(edge(b,a,i+1));
	}
	dfs(1,-1);
	sort(_all(ans));
	ans.erase(unique(_all(ans)),ans.end());
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}

