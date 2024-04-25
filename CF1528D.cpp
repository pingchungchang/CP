#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,sse4,popcnt")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1808;
const int inf = 1e9+1000;

int ans[660][660];
int N,M;
int paths[mxn][mxn];
bitset<mxn> done;
int dist[mxn];

void DIJKSTRA(int s){
	fill(dist,dist+mxn,inf);
	done.reset();
	dist[s] = 0;
	for(int i = 0;i<N*3;i++){
		int now = N*3;
		for(int j = 0;j<N*3;j++){
			if(done[j])continue;
			if(dist[j]<=dist[now])now = j;
		}
		done[now] = true;
		if(now<N){
			for(int j = 0;j<N;j++){
				if(!paths[now][j])continue;
				int nxt = (j+dist[now])%N;
				int w = paths[now][j];
				dist[nxt+N] = min(dist[nxt+N],dist[now]+w+N-nxt);
				dist[nxt+N*2] = min(dist[nxt+N*2],dist[now]+w);
			}
		}
		else if(now<N*2){
			dist[now-N] = min(dist[now-N],dist[now]+now-N);
			if(now != N)dist[now-1] = min(dist[now-1],dist[now]);
		}
		else{
			dist[now-N*2] = min(dist[now-N*2],dist[now]);
			if(now+1 != N*3)dist[now+1] = min(dist[now+1],dist[now]+1);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 1;i<=M;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a][b] = c;
	}
	for(int i = 0;i<N;i++){
		DIJKSTRA(i);
		for(int j = 0;j<N;j++)ans[i][j] = dist[j];
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++)cout<<ans[i][j]<<' ';cout<<'\n';
	}
	return 0;
}
