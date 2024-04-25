#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 6e5+10;
int n,m,l,mid,r;
vector<int> paths[mxn];
int d1[mxn],d2[mxn],d3[mxn];

ll pref[mxn];

void BFS(int s,int dist[]){
	fill(dist,dist+n+1,-1);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt] != -1)continue;
			dist[nxt] = dist[now]+1;
			q.push(nxt);
		}
	}
	return;
}

void solve(){
	for(int i = 0;i<=m*3;i++)pref[i] = 0,paths[i].clear();
	cin>>n>>m>>l>>mid>>r;
	for(int i = 1;i<=m;i++){
		cin>>pref[i];
	}
	pref[m+1] = 1e18;
	sort(pref+1,pref+m+1);
	for(int i = 1;i<=m*3;i++)pref[i] += pref[i-1];
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	BFS(l,d1);BFS(mid,d2);BFS(r,d3);
	ll ans = 1e18;
	for(int i = 1;i<=n;i++){
		ll len = d1[i]+d2[i]+d3[i];
		//cout<<i<<' '<<len<<' '<<d2[i]<<',';
		ans = min(ans,pref[len]+pref[d2[i]]);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
