#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int inf = 1e9;
const int mxn = 303;
const int mxn2 = 21;
string arr[mxn];
int dist[mxn2][mxn2];
int dd[mxn][mxn];
pii dir[] = {{-1,0},{1,0},{0,-1},{0,1}};
ll dp[mxn2][1LL<<mxn2];

void BFS(pii st){
	for(auto &i:dd)for(auto &j:i)j = inf;
	queue<pii> q;
	dd[st.fs][st.sc] = 0;
	q.push(st);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &i:dir){
			pii nxt = {i.fs+now.fs,i.sc+now.sc};
			if(arr[nxt.fs][nxt.sc] == '#'||dd[nxt.fs][nxt.sc] != inf)continue;
			dd[nxt.fs][nxt.sc] = dd[now.fs][now.sc]+1;
			q.push(nxt);
		}
	}
	return;
}

void solve(){
	int n,m,t;
	cin>>n>>m>>t;
	pii s,e;
	arr[0] = arr[n+1] = string(m+2,'#');
	for(int i = 1;i<=n;i++){
		cin>>arr[i];arr[i] = "#"+arr[i]+"#";
	}
	vector<pii> v;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(arr[i][j] == 'S')s = {i,j};
			else if(arr[i][j] == 'G')e = {i,j};
			else if(arr[i][j] != '.'&&arr[i][j] != '#')v.push_back({i,j});
		}
	}
	v.push_back(s);
	v.push_back(e);
	for(int i = 0;i<v.size();i++){
		BFS(v[i]);
		for(int j = 0;j<v.size();j++){
			dist[i][j] = dd[v[j].fs][v[j].sc];
		}
	}
	int ans = 0;
	for(auto &i:dp)for(auto &j:i)j = inf;
	dp[v.size()-2][1<<(v.size()-2)] = 0;
	//for(auto &i:v)cout<<i.fs<<' '<<i.sc<<',';cout<<endl;
	/*
	for(int i = 0;i<v.size();i++){
		for(int j = 0;j<v.size();j++)cout<<dist[i][j]<<' ';cout<<endl;
	}

   */
	for(int i = 1;i<(1<<v.size());i++){
		for(int j = 0;j<v.size();j++){
			if((1<<j)&i){
				for(int k = 0;k<v.size();k++){
					if(j == k)continue;
					if(i&(1<<k)){
						dp[k][i] = min(dp[k][i],dp[j][i^(1<<k)]+dist[j][k]);
					}
				}
			}
		}
		if(dp[v.size()-1][i] <= t)ans = max(ans,__builtin_popcount(i)-2);
	}
	if(dist[v.size()-2][v.size()-1]>t)ans = -1;
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
