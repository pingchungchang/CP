#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,m;
vector<string> v;
pair<int,int> dir[8] = {make_pair(1,1),make_pair(-1,1),make_pair(1,-1),make_pair(-1,-1),make_pair(1,0),make_pair(0,1),make_pair(-1,0),make_pair(0,-1)};
void dfs(int r,int c){
	v[r][c] = '$';
	for(auto i:dir){
		if(i.fs+r<n&&i.sc+c<m&&i.fs+r>=0&&i.sc+c>=0&&v[i.fs+r][i.sc+c] == '@')dfs(r+i.fs,c+i.sc);
	}
	return;
}
void solve(){
	int ans = 0;
	v = vector<string>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(v[i][j] == '@'){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	while(cin>>n>>m){
		if(n == 0&&m == 0)return 0;
		solve();
	}
}

