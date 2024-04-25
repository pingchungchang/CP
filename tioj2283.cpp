#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 4e5+10;
const ll inf = 1e18;
int n,m;
vector<int> paths[mxn];
ll dist[mxn];
ll val[mxn];
priority_queue<pll,vector<pll>,greater<pll>> pq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int k;
		cin>>k>>val[i+n];
		for(int j = 0;j<k;j++){
			int tmp;
			cin>>tmp;
			paths[i+n].push_back(tmp);
			paths[tmp].push_back(i+n);
		}
	}
	fill(dist,dist+mxn,inf);
	dist[1] = 0;
	pq.push({dist[1],1});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != dist[now.sc])continue;
		for(auto nxt:paths[now.sc]){
			if(dist[nxt]>dist[now.sc]+val[nxt]){
				dist[nxt] = dist[now.sc]+val[nxt];
				pq.push({dist[nxt],nxt});
			}
		}
	}
	ll ans = *max_element(dist+1,dist+n+1);
	cout<<(ans == inf?-1:ans);
}
