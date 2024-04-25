#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
const ll inf = 1e18;
vector<pll> paths[mxn];
ll dist[mxn];
priority_queue<pll,vector<pll>,greater<pll>> pq;
int n,m;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int k;
	cin>>k;
	for(int i = 0;i<m;i++){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		paths[a].push_back(make_pair(b,c));
		paths[b].push_back(make_pair(a,d));
	}
	fill(dist,dist+n+1,inf);
	while(k--){
		int r;
		cin>>r;
		pq.push(make_pair(0,r));
		dist[r] = 0;
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != dist[now.sc])continue;
		for(auto nxt:paths[now.sc]){
			if(dist[nxt.fs]>nxt.sc+dist[now.sc]){
				dist[nxt.fs] = nxt.sc+dist[now.sc];
				pq.push(make_pair(dist[nxt.fs],nxt.fs));
			}
		}
	}
	ll ans = *max_element(dist+1,dist+n+1);
	if(ans>=inf)cout<<"PEIENWUOrz";
	else cout<<ans;
}
