#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#pragma GCC optimize("O3")
vector<vector<char>> tmp;
int r,c;
pii dir[] = {{1,0},{0,1},{0,-1},{-1,0}};
void dfs(int a,int b){
	if(tmp[a][b] != '^')return;
	int total = 0;
	for(auto &d:dir){
		if(tmp[a+d.fs][b+d.sc] == '^')total++;
	}
	if(total<2)tmp[a][b] = '.';
	else return;
	for(auto &d:dir){
		dfs(a+d.fs,b+d.sc);
	}
}
void solve(){
	cin>>r>>c;
	vector<vector<char>> v(r+2,vector<char>(c+2,'#'));
	for(int i = 1;i<=r;i++)for(int j = 1;j<=c;j++){
		char c;
		cin>>c;
		v[i][j] = c;
	}
	tmp = v;
	for(int i = 1;i<=r;i++){
		for(int j = 1;j<=c;j++){
			if(tmp[i][j] == '.')tmp[i][j] = '^';
		}
	}
	for(int i = 1;i<=r;i++){
		for(int j = 1;j<=c;j++){
			int total = 0;
			for(auto &d:dir){
				if(tmp[d.fs+i][d.sc+j] == '^')total++;
			}
			if(total<2)dfs(i,j);
		}
	}
	for(int i = 1;i<=r;i++)for(int j= 1;j<=c;j++){
		if(v[i][j] == '^'&&tmp[i][j] != '^'){
			cout<<"Impossible\n";
			return;
		}
	}
	cout<<"Possible\n";
	for(int i = 1;i<=r;i++){
		for(int j= 1;j<=c;j++)cout<<tmp[i][j];
		cout<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int asd = 1;asd<=t;asd++){
		cout<<"Case #"<<asd<<": ";
		solve();
	}
}

