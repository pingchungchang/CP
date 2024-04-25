#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dist[mxn];
vector<int> g[mxn],rg[mxn];
int ans[2][mxn];
int n,m;


void BFS(vector<int> paths[],int s){
	fill(dist,dist+n+1,mxn);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt]>n){
				dist[nxt] = dist[now]+1;
				q.push(nxt);
			}
		}
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++){
		g[i].clear();
		rg[i].clear();
	}
	cin>>n>>m;
	fill(ans[0],ans[0]+n+1,mxn);
	fill(ans[1],ans[1]+n+1,mxn);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		rg[b].push_back(a);
	}
	BFS(g,1);
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
	for(int i = 1;i<=n;i++){
		ans[1][i] = ans[0][i] = dist[i];
		pq.push(make_tuple(dist[i],0,i));
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(ans[get<1>(now)][get<2>(now)] != get<0>(now))continue;
		if(!get<1>(now)){
			int pos = get<2>(now);
			for(auto nxt:rg[pos]){
				if(dist[nxt]>=dist[pos]){
					if(ans[1][nxt]>ans[0][pos]){
						ans[1][nxt] = ans[0][pos];
						pq.push(make_tuple(ans[0][pos],1,nxt));
					}
				}
				else{
					if(ans[0][nxt]>ans[0][pos]){
						ans[0][nxt] = ans[0][pos];
						pq.push(make_tuple(ans[0][pos],0,nxt));
					}
				}
			}
		}
		else{
			int pos = get<2>(now);
			for(auto nxt:rg[pos]){
				if(dist[nxt]<dist[pos]){
					if(ans[1][nxt]>ans[1][pos]){
						ans[1][nxt] = ans[1][pos];
						pq.push(make_tuple(ans[1][pos],1,nxt));
					}
				}
			}
		}
	}
	for(int i = 1;i<=n;i++)cout<<min(ans[0][i],ans[1][i])<<' ';cout<<'\n';
	/*

   */
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
