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
const int inf = 1e9+10;
struct edge{
	int s,e,v,id;
	edge(){
		s = e= v = id= 0;
	}
	edge(int ss,int ee,int vv,int ii){
		s = ss,e = ee,v = vv,id = ii;
	}
	bool operator<(const edge &b)const{
		return v<b.v;
	}
};
vector<int> change;
vector<edge> paths[mxn];
int goneto[mxn];
int deg[mxn];
int n,m;
int idx[mxn];
int cc = 0;
bool f(int k){
	fill(idx,idx+mxn,0);
	fill(goneto,goneto+mxn,0);
	fill(deg,deg+mxn,0);
	cc = 0;
	queue<int> q;
	for(int i= 1;i<=n;i++){
		for(auto &nxt:paths[i]){
			if(nxt.v<=k)continue;
			deg[nxt.e]++;
		}
	}
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	int cnt = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		idx[now] = ++cc;
		cnt++;
		for(auto &nxt:paths[now]){
			if(nxt.v<=k)continue;
			deg[nxt.e]--;
			if(!deg[nxt.e]){
				q.push(nxt.e);
			}
		}
	}
	if(cnt == n)return true;
	else return false;
}
int main(){
	io
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back(edge(a,b,c,i+1));
	}
	int l = 0,r = 1e9+10;
	while(l != r){
		int mid = (l+r)>>1;
		if(f(mid)){
			r = mid;
		}
		else l = mid+1;
	}
	f(l);
	change.clear();
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i]){
			if(nxt.v<=l&&idx[nxt.s]>idx[nxt.e])change.push_back(nxt.id);
		}
	}
	cout<<l<<' '<<change.size()<<'\n';
	for(auto &i:change)cout<<i<<'\n';
	return 0;
	
}

