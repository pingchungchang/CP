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

const int mxn = 505;
int adj[mxn][mxn];
vector<int> paths[mxn];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++){
		int a,b;
		string s;
		cin>>a>>s>>b;
		if(s == "<-")swap(a,b);
		adj[a][b] = 1;
		paths[a].push_back(b);
	}
	if(!k){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++)cout<<adj[i][j]<<' ';cout<<'\n';
		}
	}
	else{
		for(int i = 1;i<=n;i++){
			if(paths[i].empty())cout<<i<<" -> 0\n";
			else{
				cout<<i<<" -> ";
				sort(_all(paths[i]));
				paths[i].erase(unique(_all(paths[i])),paths[i].end());
				for(auto &j:paths[i])cout<<j<<' ';
				cout<<'\n';
			}
		}
	}
	return 0;
}

