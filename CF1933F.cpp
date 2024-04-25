#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
int arr[mxn][mxn],dist[mxn][mxn];
int n,m;
pii dir[] = {{1,1},{0,0},{2,0}};
queue<pii> q;

pii mv(pii now,int dx,int dy){
	now.fs+=dx;now.sc += dy;
	if(now.fs<0)now.fs += n;
	if(now.fs>=n)now.fs -= n;
	return now;
}

void solve(){
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++)cin>>arr[i][j];
	}
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)dist[i][j] = -1;
	q.push({0,0});
	dist[0][0] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &d:dir){
			if(now.sc != m-1){
				pii nxt = mv(now,1,1);
				if(dist[nxt.fs][nxt.sc] == -1&&arr[nxt.fs][nxt.sc] != 1){
					dist[nxt.fs][nxt.sc] = dist[now.fs][now.sc]+1;
					q.push(nxt);
				}
			}
			pii n1 = mv(now,1,0),n2 = mv(now,2,0);
			if(arr[n1.fs][n1.sc] != 1&&arr[n2.fs][n2.sc] != 1&&dist[n2.fs][n2.sc]==-1){
				dist[n2.fs][n2.sc] = dist[now.fs][now.sc]+1;
				q.push(n2);
			}
		}
	}
	int ans = 1e9;
	for(int i = 0;i<n;i++){
		if(dist[i][m-1] == -1)continue;
		int np = i-dist[i][m-1]%n;
		if(np<0)np += n;
		ans = min(ans,dist[i][m-1]+(np==n-1?0:np+1));
	}
	cout<<(ans>=1e7?-1:ans)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
