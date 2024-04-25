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

const int mxn = 1e5+10;
vector<int> paths[mxn];
int col[mxn];

bool dfs(int now,int c){
	if(col[now] == 0)col[now] = c;
	else if(col[now] != c)return false;
	else return true;
	c = -c;
	for(auto nxt:paths[now]){
		if(dfs(nxt,c) == false)return false;
	}
	return true;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i= 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		if(col[i] == 0){
			if(dfs(i,1) == false){
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
	return 0;
}

