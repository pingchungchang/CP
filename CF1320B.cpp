#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> g[mxn],rg[mxn];
int dist[mxn];
int n,m;

void BFS(int start,vector<int> paths[],int d[]){
	fill(d,d+n+1,-1);
	queue<int> q;
	d[start] = 0;
	q.push(start);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(d[nxt] != -1)continue;
			d[nxt] = d[now]+1;
			q.push(nxt);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		rg[b].push_back(a);
	}
	int k;
	cin>>k;
	vector<int> v;
	for(int i = 0;i<k;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	BFS(v.back(),rg,dist);
	pii ans = {0,0};
	for(int i = 1;i<v.size();i++){
		set<int> st;
		int now = v[i-1];
		int small = n;
		for(auto &nxt:g[now]){
			small = min(small,dist[nxt]);
		}
		for(auto &nxt:g[now]){
			if(dist[nxt] == small)st.insert(nxt);
		}
		if(st.find(v[i]) == st.end())ans.fs++,ans.sc++;
		else if(st.size() != 1)ans.sc++;
	}
	cout<<ans.fs<<' '<<ans.sc;
}
