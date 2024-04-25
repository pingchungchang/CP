#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
	ll val;
	int pos;
	int type;
	node(int a,ll b,int c){
		val = b;
		pos =a;
		type = c;
	}
};
class Compare{
public:
	bool operator()(node a,node b){
		return a.val>b.val;
	}	
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> paths(n);
	vector<vector<ll>> dist(n,vector<ll>(2,1e18));
	for(int i =0;i<m;++i){
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		paths[a].push_back(make_pair(b,c));
	}
	priority_queue<node,vector<node>,Compare> pq;
	dist[0] = {0,0};
	pq.push(node(0,0,0));
	/*type = 0: not used coupon yet*/
	vector<vector<bool>> goneto(n,vector<bool>(2,false));
	while(!pq.empty()){
		node now = pq.top();
		pq.pop();
		if(goneto[now.pos][now.type] == true)continue;
		goneto[now.pos][now.type] = true;
		for(int i =0;i<paths[now.pos].size();i++){
			ll nxt = paths[now.pos][i].first;
			if(now.type == 0){
				if(dist[nxt][1]>paths[now.pos][i].second/2+dist[now.pos][0]){
					dist[nxt][1] = paths[now.pos][i].second/2+dist[now.pos][0];
					pq.push(node(nxt,dist[nxt][1],1));
				}
			}
			if(dist[nxt][now.type]>paths[now.pos][i].second+dist[now.pos][now.type]){
				dist[nxt][now.type] = paths[now.pos][i].second+dist[now.pos][now.type];
				pq.push(node(nxt,dist[nxt][now.type],now.type));
			}

		}
	}
	cout<<min(dist[n-1][0],dist[n-1][1]);
}
