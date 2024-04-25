#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;

int dist[mxn][mxn];
vector<pii> dir;
int n,m;

void BFS(pii s){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(dist[i][j] != -2)dist[i][j] = -1;
		}
	}
	dist[s.fs][s.sc] = 0;
	queue<pii> q;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &i:dir){
			pii nxt = {i.fs+now.fs,i.sc+now.sc};
			if(nxt.fs>n||nxt.fs<1||nxt.sc>m||nxt.sc<1)continue;
			if(dist[nxt.fs][nxt.sc] == -1){
				dist[nxt.fs][nxt.sc] = dist[now.fs][now.sc]+1;
				q.push(nxt);
			}
		}
	}
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int s1,s2;
	cin>>s1>>s2;
	pii tmp[] = {{1,0},{-1,0},{0,1},{0,-1}};
	for(auto &i:tmp)dir.push_back(make_pair(i.fs*s1,i.sc*s1));
	for(auto &i:tmp)dir.push_back(make_pair(i.fs*s2,i.sc*s2));
	int a,b;
	cin>>a>>b;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>dist[i][j];
			if(dist[i][j] == 1)dist[i][j] = -2;
		}
	}
	BFS(make_pair(1,1));
	if(dist[a][b] == -1){
		cout<<"-1";
		return 0;
	}
	ans += dist[a][b];
	BFS(make_pair(a,b));
	if(dist[n][m] == -1){
		cout<<-1;
		return 0;
	}
	ans += dist[n][m];
	cout<<ans;
}
