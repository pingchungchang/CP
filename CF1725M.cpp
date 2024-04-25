#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int inf = 1e18;
const int mxn = 1e6+10;
vector<pll> g[mxn],rg[mxn];
int n,m;
int d1[mxn],d2[mxn];
priority_queue<pll,vector<pll>,greater<pll>> pq;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	fill(d1,d1+mxn,inf);
	fill(d2,d2+mxn,inf);
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		rg[b].push_back({a,c});
	}
	d1[1] = 0;
	pq.push({d1[1],1});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != d1[now.sc])continue;
		for(auto nxt:g[now.sc]){
			if(d1[nxt.fs]>now.fs+nxt.sc){
				d1[nxt.fs] = now.fs+nxt.sc;
				pq.push({d1[nxt.fs],nxt.fs});
			}
		}
	}
	for(int i = 1;i<=n;i++){
		d2[i] = d1[i];
		if(d1[i]<inf)pq.push({d2[i],i});
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != d2[now.sc])continue;
		for(auto nxt:rg[now.sc]){
			if(d2[nxt.fs]>now.fs+nxt.sc){
				d2[nxt.fs] = now.fs+nxt.sc;
				pq.push(make_pair(d2[nxt.fs],nxt.fs));
			}
		}
	}
	for(int i = 2;i<=n;i++)cout<<(d2[i]<inf?d2[i]:-1)<<' ';
}
