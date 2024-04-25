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

pii dir[] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int main(){
	io
	int n;
	cin>>n;
	int dist[n][n] = {};
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	a--,b--,c--,d--;
	dist[a][b] = 1;
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		x--,y--;
		dist[x][y] = -1;
	}
	queue<pii> q;
	q.push({a,b});
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto i:dir){
			pii nxt = {i.fs+now.fs,i.sc+now.sc};
			if(nxt.fs>=0&&nxt.fs<n&&nxt.sc>=0&&nxt.sc<n&&dist[nxt.fs][nxt.sc] == 0){
				dist[nxt.fs][nxt.sc] = dist[now.fs][now.sc]+1;
				q.push(nxt);
			}
		}
	}
	cout<<dist[c][d]-1;
}

