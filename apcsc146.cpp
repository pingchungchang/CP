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
const int mxn = 1e5+10;
vector<int> paths[mxn];
int ans = 0;

int main(){
	io
	int n;
	cin>>n;
	int s,e;
	cin>>s>>e;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	queue<int> q;
	int dist[n+1];
	fill(dist,dist+n+1,-1);
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt] == -1){
				dist[nxt] = dist[now]+1;
				q.push(nxt);
			}
		}
	}
	int dist2[n+1];
	fill(dist2,dist2+n+1,-1);
	dist2[e] = 0;
	q.push(e);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist2[nxt] == -1){
				dist2[nxt] = dist2[now]+1;
				q.push(nxt);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(dist[i]<dist2[i])ans = max(ans,dist2[i]);
	}
	cout<<ans-1;
}

