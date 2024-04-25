#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	vector<ll> paths;
	ll par;
	ll subsize;
	node(){
		par = -1;
		subsize = 0;
	}
};
ll n;
vector<node> v;
ll dist[200005];
void maketree(ll now){
	for(ll nxt:v[now].paths){
		if(nxt == v[now].par)continue;
		v[nxt].par = now;
		maketree(nxt);
		v[now].subsize += v[nxt].subsize;
	}
	v[now].subsize++;
	return;
}
void bfs(ll root){
	memset(dist,-1,sizeof(dist));
	queue<ll> q;
	q.push(root);
	dist[root] = 0;
	while(!q.empty()){
		ll now = q.front();
		q.pop();
		for(ll nxt:v[now].paths){
			if(nxt == v[now].par)continue;
			if(dist[nxt] == -1){
				dist[nxt] = dist[now]+1;
				q.push(nxt);
			}
		}
	}
	return;
}
int main(){
	cin>>n;
	v = vector<node>(n);
	for(ll i = 0;i<n-1;i++){
		ll a,b;
		cin>>a>>b;
		v[a-1].paths.push_back(b-1);
		v[b-1].paths.push_back(a-1);
	}
	bfs(0);
	maketree(0);
	ll ans[200005];
	memset(ans,0,sizeof(ans));
	for(ll i = 0;i<n;i++)ans[0]+= dist[i];
	queue<ll> q;
	for(ll nxt:v[0].paths){
		q.push(nxt);
	}
	while(!q.empty()){
		ll now = q.front();
		q.pop();
		ans[now] = ans[v[now].par]-v[now].subsize+(n-v[now].subsize);
		for(ll nxt:v[now].paths){
			if(nxt != v[now].par){
				q.push(nxt);
			}
		}
	}
	for(ll i = 0;i<n;i++)cout<<ans[i]<<' ';
	return 0;
}
