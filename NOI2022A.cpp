#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll inf = 1e18;
const int mxn = 5050;
const int b = 5;
vector<pll> paths[mxn];
ll dist[mxn][1<<b];
int N,M,Q,K;

namespace DIJKSTRA{
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	void GO(vector<int> starts){
		for(auto &i:dist){
			for(auto &j:i)j = inf;
		}
		for(auto &i:starts){
			dist[i][0] = 0;
			pq.push(pll(0,i<<b));
		}
		while(!pq.empty()){
			auto [d,now] = pq.top();
			pq.pop();
			int mask = now%(1<<b);
			now>>=b;
			if(dist[now][mask] != d)continue;
			for(int i = 0;i<b;i++){
				if(mask&(1<<i))continue;
				int tm = mask^(1<<i);
				for(auto [nxt,w]:paths[now]){
					w = w*(100-10*(i+1))/100;
					if(dist[nxt][tm]>d+w){
						dist[nxt][tm] = d+w;
						pq.push(pll(dist[nxt][tm],(nxt<<5)+tm));
					}
				}
			}
			for(auto [nxt,w]:paths[now]){
				if(dist[nxt][mask]>d+w){
					dist[nxt][mask] = d+w;
					pq.push(pll(dist[nxt][mask],(nxt<<5)+mask));
				}
			}
		}
		return;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>K;
	vector<int> v;
	for(int i = 0;i<K;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	for(int i = 0;i<M;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[b].push_back(pii(a,c));
	}
	DIJKSTRA::GO(v);
	cin>>Q;
	while(Q--){
		int s,arr[b];
		cin>>s;
		for(auto &i:arr)cin>>i;
		ll ans = inf;
		for(int i = 0;i<(1<<b);i++){
			ll cost = dist[s][i];
			bool f = true;
			for(int j = 0;j<b;j++){
				if(i&(1<<j)){
					if(arr[j] == -1)f = false;
					cost += arr[j];
				}
			}
			if(!f)continue;
			ans = min(ans,cost);
		}
		cout<<(ans>=inf?-1:ans)<<'\n';
	}
	return 0;
}
