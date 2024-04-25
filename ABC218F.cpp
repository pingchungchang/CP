#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 404;
vector<pii> paths[mxn];
int ans[mxn*mxn];
int n,m;
pii pre[mxn];
int dist[mxn];

void BFS(int no){
	memset(dist,-1,sizeof(dist));
	for(auto &i:pre)i = {0,0};
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(nxt.sc == no)continue;
			if(dist[nxt.fs] == -1){
				dist[nxt.fs] = dist[now]+1;
				pre[nxt.fs] = {now,nxt.sc};
				q.push(nxt.fs);
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back({b,i});
	}
	BFS(0);
	set<int> st;
	int now = n;
	while(now){
		st.insert(pre[now].sc);
		now = pre[now].fs;
	}
	for(int i = 1;i<=m;i++){
		ans[i] = dist[n];
	}
	for(auto &i:st){
		BFS(i);
		ans[i] = dist[n];
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<'\n';
	}
}
