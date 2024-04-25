#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int n,q;
vector<int> paths[mxn];
bitset<mxn> vis;

void dfs(int now){
	vis[now] = true;
	for(auto nxt:paths[now]){
		if(!vis[nxt])dfs(nxt);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		paths[l-1].push_back(r);
		paths[r].push_back(l-1);
	}
	dfs(0);
	cout<<(vis[n]?"Yes":"No");
}
