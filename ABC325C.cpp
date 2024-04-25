#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1010;

string arr[mxn];
vector<pii> dir;
int n,m;

void dfs(int r,int c){
	arr[r][c] = '.';
	for(auto &i:dir){
		int nr = i.fs+r,nc = i.sc+c;
		if(nr>=0&&nr<n&&nc>=0&&nc<m&&arr[nr][nc] == '#')dfs(nr,nc);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = -1;i<=1;i++)for(int j = -1;j<=1;j++)if(i||j)dir.push_back({i,j});
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == '#')ans++,dfs(i,j);
		}
	}
	cout<<ans;
}
