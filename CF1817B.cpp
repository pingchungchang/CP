#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 4020;
vector<pii> paths[mxn];
vector<pii> ans;
int n,m;
int pre[mxn];
int dist[mxn];
bitset<mxn> vis;
queue<int> q;

inline void BFS(int s,int ban){
	fill(dist,dist+n+1,-1);
	for(int i = 0;i<=n;i++)pre[i] = 0;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(nxt.sc == ban)continue;
			if(dist[nxt.fs] != -1)continue;
			q.push(nxt.fs);
			pre[nxt.fs] = now;
			dist[nxt.fs] = dist[now]+1;
		}
	}
	return;
}

inline bool check(int s,int e){
	vis.reset();
	int tmp = e;
	ans.clear();
	ans.push_back({s,e});
	while(tmp){
		vis[tmp] = true;
		if(pre[tmp])ans.push_back({pre[tmp],tmp});
		tmp = pre[tmp];
	}
	bool flag = false;
	for(int i = 1;i<=n;i++){
		if(vis[i]){
			vector<int> v;
			for(auto nxt:paths[i]){
				if(vis[nxt.fs])continue;
				v.push_back(nxt.fs);
			}
			if(v.size()>=2){
				ans.push_back({i,v[0]});
				ans.push_back({i,v[1]});
				flag = true;
				break;
			}
		}
	}
	if(!flag)return false;
	cout<<"YES\n";
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return true;
}

void solve(){
	ans.clear();
	for(int i = 0;i<=n+m;i++){
		pre[i] = 0;
		paths[i].clear();
	}
	cin>>n>>m;
	for(int i= 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back({b,i});
		paths[b].push_back({a,i});
	}
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i]){
			BFS(i,nxt.sc);
			if(dist[nxt.fs] != -1){
				if(check(i,nxt.fs)){
					return;
				}
			}
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
