#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s[n+2];
	s[0] = s[n+1] = string(m+2,'.');
	for(int i = 1;i<=n;i++){
		cin>>s[i];
		s[i] = "."+s[i]+'.';
	}
	pair<int,int> dir[] = {{1,0},{0,1},{-1,0},{0,-1}};
	//for(auto &i:s)cout<<i<<endl;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(s[i][j] == '#')continue;
			int cnt = 0;
			for(auto &k:dir){
				int nx = k.fs+i,ny = k.sc+j;
				if(s[nx][ny] == '#')cnt++;
			}
			if(cnt>=2){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	assert(false);
}
