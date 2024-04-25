#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int low[mxn],idx[mxn],cnt,gcnt,gid[mxn];
vector<pii> paths[mxn];
vector<int> st;
int n,m;
int w[mxn];
pii arr[mxn];
pii edges[mxn];
int pre[mxn];

void dfs(int now,int par = -1){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(nxt.fs == par)continue;
		if(!idx[nxt.fs]){
			dfs(nxt.fs,now);
			low[now] = min(low[now],low[nxt.fs]);
		}
		else low[now] = min(low[now],idx[nxt.fs]);
	}
	if(low[now] == idx[now]){
		gcnt++;
		while(st.back() != now){
			gid[st.back()] = gcnt;
			st.pop_back();
		}
		gid[st.back()] = gcnt;
		st.pop_back();
	}
	return;
}

queue<int> q;
void bfs(int s,int bid){
	fill(pre,pre+n+1,-1);
	pre[s] = s;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(nxt.sc == bid)continue;
			if(pre[nxt.fs] != -1)continue;
			pre[nxt.fs] = now;
			q.push(nxt.fs);
		}
	}
	return;
}

void getans(int a,int b,int id){
	bfs(a,id);
	vector<int> v;
	int now = b;
	while(now != a){
		v.push_back(now);
		now = pre[now];
	}
	v.push_back(a);
	cout<<w[id]<<" "<<v.size()<<'\n';
	for(auto &i:v)cout<<i<<' ';cout<<'\n';
	return;
}

void solve(){
	st.clear();
	cnt = gcnt = 0;
	for(int i = 0;i<=n;i++)idx[i] = low[i] = 0,paths[i].clear();
	cin>>n>>m;
	for(int i =1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr[i] = {c,i};
		w[i] = c;
		edges[i] = {a,b};
		paths[a].push_back({b,i});
		paths[b].push_back({a,i});
	}
	sort(arr+1,arr+m+1);
	for(int i = 1;i<=n;i++){
		if(!idx[i])dfs(i);
	}
	for(int i = 1;i<=m;i++){
		int now = arr[i].sc;
		int a = edges[now].fs,b = edges[now].sc;
		if(gid[a] != gid[b])continue;
		getans(a,b,now);
		return;
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
