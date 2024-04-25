#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,sse4,avx2")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 505;
const int mxk = 22;

int N,M,K;
int dist[mxn][mxn];
int down[mxn][mxn],up[mxn][mxn],lef[mxn][mxn],rig[mxn][mxn];
pii dir[] = {pii(1,0),pii(0,1),pii(-1,0),pii(0,-1)};

int calc(int sr,int sc){
	dist[sr][sc] = 0;
	vector<pii> v;
	for(int d = 1;d*2<=K;d++){
		for(int i = -d;i<=d;i++){
			int r = sr+i,c = sc+d-abs(i);
			if(r>0&&c>0&&r<=N&&c<=M){
				if(r-1>0)dist[r][c] = min(dist[r][c],dist[r-1][c]+down[r-1][c]);
				if(r+1<=N)dist[r][c] = min(dist[r][c],dist[r+1][c]+up[r+1][c]);
				if(c-1>0)dist[r][c] = min(dist[r][c],dist[r][c-1]+rig[r][c-1]);
				if(c+1<=M)dist[r][c] = min(dist[r][c],dist[r][c+1]+lef[r][c+1]);
			}
			c = sc-d+abs(i);
			if(r>0&&c>0&&r<=N&&c<=M){
				if(r-1>0)dist[r][c] = min(dist[r][c],dist[r-1][c]+down[r-1][c]);
				if(r+1<=N)dist[r][c] = min(dist[r][c],dist[r+1][c]+up[r+1][c]);
				if(c-1>0)dist[r][c] = min(dist[r][c],dist[r][c-1]+rig[r][c-1]);
				if(c+1<=M)dist[r][c] = min(dist[r][c],dist[r][c+1]+lef[r][c+1]);
			}
		}
	}
	int ans = 1e9;
	for(int i = -10;i<=10;i++){
		for(int j = -10;j<=10;j++){
			int r = sr+i,c = sc+j;
			if((abs(i)+abs(j))*2>K||r<=0||c<=0||r>N||c>M)continue;
			for(auto &d:dir){
			}
		}
	}
	return dp[K];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>K;
	for(auto &i:dist)for(auto &j:i)j = 1e9;
	for(int i = 1;i<=N;i++){
		for(int j = 2;j<=M;j++){
			cin>>lef[i][j];
			rig[i][j-1] = lef[i][j];
		}
	}
	for(int i = 1;i<N;i++){
		for(int j = 1;j<=M;j++){
			cin>>down[i][j];
			up[i+1][j] = down[i][j];
		}
	}
	if(K&1){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<M;j++)cout<<-1<<' ';cout<<'\n';
		}
		return 0;
	}
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=M;j++){
			cout<<calc(i,j)<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
