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
int main(){
	int n,p,l,r;
	cin>>n>>p>>l>>r;
	int dist[n];
	int dir[n];
	fill(dist,dist+n,-1);
	for(int i = 0;i<n;i++)cin>>dir[i];
	queue<pii> q;
	q.push({0,0});
	dist[0] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		now.fs = dir[now.fs];
		if(now.fs<0||now.fs>=n)continue;
		if(now.sc>dist[now.fs])continue;
		else dist[now.fs] = now.sc;
		if(now.fs-l>=0&&dist[now.fs-l] == -1){
			q.push({now.fs-l,now.sc+1});
			dist[now.fs-l] = now.sc+1;
		}
		if(now.fs+r<n&&dist[now.fs+r] == -1){
			q.push({now.fs+r,now.sc+1});
			dist[now.fs+r] = now.sc+1;
		}
	}
	cout<<dist[p];
}

