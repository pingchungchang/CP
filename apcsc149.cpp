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
const ll mxn = 1e5+10;
bitset<mxn> goneto;
int main(){
	io
	int n,m;
	cin>>n>>m;
	vector<pii> paths[n+1];
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
	}
	int s,e;
	cin>>s>>e;
	vector<ll> dist(n+1,-1);
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	dist[s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		for(auto nxt:paths[now.sc]){
			if(dist[nxt.fs] == -1||dist[nxt.fs]>nxt.sc+now.fs){
				pq.push({nxt.sc+now.fs,nxt.fs});
				dist[nxt.fs] = nxt.sc+now.fs;
			}
		}
	}
	cout<<dist[e];
}

