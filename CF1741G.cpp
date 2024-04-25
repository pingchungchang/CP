#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e4+10;
int dist[mxn];
int dist2[mxn];
vector<int> paths[mxn];
vector<int> vv[mxn];
int n,m;
int dp[2][1<<6];

bool cmp(int a,int b){
	return dist[a]<dist[b];
}
void BFS(int now){
	queue<int> q;
	fill(dist,dist+n+1,mxn);
	q.push(now);
	dist[now] = 0;
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
	return;
}
void BFS2(int now){
	queue<int> q;
	fill(dist2,dist2+n+1,mxn);
	q.push(now);
	dist2[now] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist2[nxt]>dist2[now]+1){
				q.push(nxt);
				dist2[nxt] = dist2[now]+1;
			}
		}
	}
	return;
}

void solve(){
	cin>>n>>m;
	for(int i= 0;i<=n;i++){
		assert(paths[i].empty());
		assert(vv[i].empty());
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	int f;
	cin>>f;
	int arr[f];
	for(auto &i:arr)cin>>i;
	int kk;
	cin>>kk;
	int pos[kk];
	set<int> no;
	for(int i = 0;i<kk;i++){
		int x;
		cin>>x;
		pos[i] = arr[x-1];
		no.insert(x-1);
	}
	int ans = 0;
	BFS(1);
	for(int i = 0;i<(1<<kk);i++){
		vector<int> req = {1};
		for(int j = 0;j<kk;j++){
			if(i&(1<<j))req.push_back(pos[j]);
		}
		bool flag = true;
		sort(req.begin(),req.end(),cmp);
		for(int j = 1;j<req.size();j++){
			int now = req[j],pre = req[j-1];
			BFS2(pre);
			if(dist[pre]+dist2[now] != dist[now]){
				flag = false;
				break;
			}
		}
		if(!flag)continue;
		BFS2(req.back());
		int pre = req.back();
		for(int j = 0;j<f;j++){
			if(no.find(j)!=no.end())continue;
			if(dist[arr[j]] == dist[pre]+dist2[arr[j]])vv[j].push_back(i);
		}
	}
	memset(dp,0,sizeof(dp));
	bool roll = false;
	dp[roll][0] = 1;
	for(int i = 0;i<f;i++){
		if(no.find(i) != no.end())continue;
		roll ^= 1;
		for(int j = 0;j<(1<<kk);j++)dp[roll][j] = dp[roll^1][j];
		for(auto &j:vv[i]){
			for(int k = 0;k<(1<<kk);k++){
				if(dp[roll^1][k])dp[roll][j|k] = true;
			}
		}
	}
	for(int i = 0;i<(1<<kk);i++)if(dp[roll][i])ans = max(ans,__builtin_popcount(i));
	/*
	for(int i = 0;i<f;i++){
		cout<<arr[i]<<":";
		for(auto &j:vv[i])cout<<j<<' ';cout<<'\n';
	}
	*/
	cout<<kk-ans<<'\n';
	for(int i = 0;i<=max(n,f);i++){
		paths[i].clear();
		vv[i].clear();
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
