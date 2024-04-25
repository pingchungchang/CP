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
bitset<mxn> goneto;
vector<int> paths[mxn];
void dfs(int now){
	goneto[now] = true;
	for(auto nxt:paths[now])if(!goneto[nxt])dfs(nxt);
	return;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(!goneto[i]){
			dfs(i);
			ans++;
		}
	}
	cout<<ans-1;
}

