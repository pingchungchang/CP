#include <bits/stdc++.h>
using namespace std;

struct node{
	int par;
	vector<int> paths;
	int depth;
	vector<int> dist;
	node(){
		dist = vector<int>(20,0);
		par = 0;
		depth = -1;
	}
};
int n,qe;
vector<node> v;
void dfs(int now){
	for(int nxt:v[now].paths){
		if(nxt != v[now].par){
			v[nxt].depth = v[now].depth+1;
			dfs(nxt);
		}
	}
	return;
}
int findpar(int now,int k){
	if(now == 0|| k == 0)return now;
	for(int i = 19;i>=0;i--){
		if((1<<i)<=k){
			return findpar(v[now].dist[i],k-(1<<i));
		}
	}
}
void solve(){
	int a,b;
	cin>>a>>b;
	a--,b--;
	if(v[a].depth<v[b].depth)swap(a,b);
	a = findpar(a,v[a].depth-v[b].depth);
//	cout<<a<<' '<<b<<' ';
	while(a != b){
		for(int i = 19;i>=0;i--){
			if((1<<i)>v[a].depth)continue;
			if(v[a].dist[i] != v[b].dist[i]){
				a = v[a].dist[i];
				b = v[a].dist[i];
				break;
			}
			if(i == 0&&a != b){
				a = v[a].dist[0];
				b = v[b].dist[0];
			}
		}
	}
	cout<<a+1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>qe;
	v = vector<node>(n,node());
	for(int i = 1;i<n;i++){
		int k;
		cin>>k;
		v[i].par = k-1;
		v[k-1].paths.push_back(i);
	}
	v[0].depth = 0;
	dfs(0);
	queue<int> q;
	for(int nxt:v[0].paths)q.push(nxt);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		v[now].dist[0] = v[now].par;
		for(int i = 1;i<20;i++){
			int pre = v[now].dist[i-1];
			v[now].dist[i] = v[pre].dist[i-1];
		}
		for(int nxt:v[now].paths)if(nxt != v[now].par)q.push(nxt);
	}
	for(int i = 0;i<qe;i++)solve();
}
/*
10 10
1 2 3 4 5 6 7 8 9
6 9
8 10
10 3
5 1
8 10
2 10
8 9
4 1
10 1
10 6
*/
