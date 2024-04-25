#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxn = 505;
vector<pair<int,int>> v;
vector<int> paths[mxn];
ll n,m;
vector<pair<int,int>> dir;
int matchx[mxn],matchy[mxn];
int col[mxn];
bitset<mxn> vis;

void dfs1(int now,int c){
	col[now] = c;
	for(auto nxt:paths[now]){
		if(!col[nxt]){
			dfs1(nxt,-c);
		}
	}
	return;
}

bool dfs(int now){
	vis[now] = true;
	for(auto nxt:paths[now]){
		if(vis[matchx[nxt]])continue;
		if(!matchx[nxt]){
			matchx[nxt] = now;
			return true;
		}
		if(matchx[nxt] == now)continue;
		if(dfs(matchx[nxt])){
			matchx[nxt] = now;
			return true;
		}
	}
	return false;
}

void solve(){
	v.push_back({0,0});
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)v.push_back({i,j});
	}
	int c = 1;
	for(int i = 1;i<=n;i++){
		for(int j =1;j<=m;j++){
			for(auto &k:dir){
				int nx = i+k.first,ny = j+k.second;
				if(nx<=n&&nx>0&&ny<=m&&ny>0){
					auto p = lower_bound(v.begin(),v.end(),make_pair(nx,ny))-v.begin();
					paths[p].push_back(c);
					paths[c].push_back(p);
				}
			}
			c++;
		}
	}
	for(int i = 1;i<=n*m;i++){
		if(!col[i])dfs1(i,1);
	}
	int ans = 0;
	for(int i = 1;i<=n*m;i++){
		vis.reset();
		if(col[i] == 1&&dfs(i))ans++;
	}
	cout<<ans*2;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n>m)swap(n,m);
	for(int i = -3;i<=3;i++){
		for(int j = -3;j<=3;j++){
			if(abs(i)+abs(j)==3)dir.push_back({i,j});
		}
	}
	if(n==1){
		cout<<m/6*6+max(0LL,m%6-3)*2LL;
		return 0;
	}
	if(n*m<mxn){
		solve();
	}
	else cout<<((n*m>>1)<<1);
}
