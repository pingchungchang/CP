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

pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};
int main(){
	io
	int n,m;
	cin>>n>>m;
	int arr[n+2][m+2] = {};
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)arr[i][j] = -1;
	}
	string s;
	int r,c;
	cin>>r>>c;
	queue<pii> q;
   	for(int i = 1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=  0;j<m;j++){
			if(s[j] == 'X')arr[i][j+1] = -2;
		}
	}
	q.push({r,c});
	arr[r][c] = 1;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto i:dir){
			if(arr[now.fs+i.fs][now.sc+i.sc] == -1){
				arr[now.fs+i.fs][now.sc+i.sc] = arr[now.fs][now.sc]+1;
				q.push({now.fs+i.fs,now.sc+i.sc});
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cout<<(arr[i][j]<0?-1:arr[i][j]-1)<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

