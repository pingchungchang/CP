#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 2e5+10;
int dist[mxn];
vector<int> paths[mxn];
priority_queue<pii,vector<pii>,less<pii>> pq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	memset(dist,-1,sizeof(dist));
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 0;i<k;i++){
		int p,h;
		cin>>p>>h;
		dist[p] = max(dist[p],h);
		pq.push({h,p});
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(dist[now.sc] != now.fs)continue;
		if(now.fs == 0)continue;
		for(auto nxt:paths[now.sc]){
			if(dist[nxt]<now.fs-1){
				dist[nxt] = now.fs-1;
				pq.push({dist[nxt],nxt});
			}
		}
	}
	vector<int> ans;
	for(int i = 1;i<=n;i++){
		if(dist[i] != -1)ans.push_back(i);
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}
