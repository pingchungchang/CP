#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;

int N,M;
int arr[mxn][mxn];
bitset<mxn> done[mxn];
pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};

int bfs(int sr,int sc){
	queue<pii> q;
	q.push(pii(sr,sc));
	vector<pii> out;
	int cc = 0;
	done[sr][sc] = true;
	//cerr<<sr<<' '<<sc<<":"<<endl;
	while(!q.empty()){
		auto now = q.front();q.pop();
		//cerr<<now.fs<<' '<<now.sc<<'\n';
		cc++;
		if(arr[now.fs][now.sc] <= 0){
			out.push_back(now);
			continue;
		}
		for(auto d:dir){
			pii nxt = pii(now.fs+d.fs,now.sc+d.sc);
			if(done[nxt.fs][nxt.sc]||!arr[nxt.fs][nxt.sc])continue;
			done[nxt.fs][nxt.sc] = true;
			q.push(nxt);
		}
	}
	for(auto [r,c]:out)done[r][c] = false;
	return cc;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=M;j++){
			char c;
			cin>>c;
			arr[i][j] = (c != '#');
		}
	}
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=M;j++){
			if(!arr[i][j]){
				for(auto &d:dir)if(arr[i+d.fs][j+d.sc]==1)arr[i+d.fs][j+d.sc] = -1;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=M;j++){
			if(arr[i][j])ans = max(ans,1);
			if(!done[i][j]&&arr[i][j]==1)ans = max(ans,bfs(i,j));
		}
	}
	cout<<ans<<'\n';
	return 0;
}
