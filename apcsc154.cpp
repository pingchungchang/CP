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
int deg[mxn];
int ans[mxn];
bitset<mxn> goneto;
int p;
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		deg[b]++;
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(!deg[i]){
			q.push(i);
			ans[p++] = i;
			goneto[i] = true;
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt]){
				q.push(nxt);
				goneto[nxt] = true;
				ans[p++] = nxt;
			}
		}
	}
	if(p == n){
		cout<<"POSSIBLE\n";
		for(int i = 0;i<n;i++)cout<<ans[i]<<' ';cout<<'\n';
	}
	else cout<<"IMPOSSIBLE\n";
	return 0;
}

