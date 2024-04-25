#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


const int mxn = 2020;
vector<int> paths[mxn];
int dist[mxn];
int cnt[mxn];
pii req[mxn];
int n,m;

void BFS(int cen){
	fill(dist,dist+n+1,mxn);
	dist[cen] = 0;
	queue<int> q;
	q.push(cen);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt]>dist[now]+1){
				dist[nxt] = dist[now]+1;
				q.push(nxt);
			}
		}
	}
	return;
}

void solve(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	int k;
	cin>>k;
	for(int i = 0;i<k;i++){
		cin>>req[i].fs>>req[i].sc;
	}
	string ans(n,'0');
	for(int i = 1;i<=n;i++){
		BFS(i);
		bool flag = true;
		for(int j = 0;j<k;j++){
			if(dist[req[j].fs]<req[j].sc)flag = false;
		}
		if(flag)ans[i-1] = '1';
	}
	fill(dist,dist+n+1,mxn);
	queue<int> q;
	for(int i = 0;i<n;i++)if(ans[i] == '1')dist[i+1] = 0,q.push(i+1);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt]>dist[now]+1){
				q.push(nxt);
				dist[nxt] = dist[now]+1;
			}
		}
	}
	bool flag = true;
	for(int i = 0;i<k;i++){
		if(dist[req[i].fs] != req[i].sc)flag = false;
	}
	if(flag){
		cout<<"Yes\n"<<ans;
		return;
	}
	else cout<<"No";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
