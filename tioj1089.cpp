#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 550;
int n,m;
vector<int> paths[mxn];
int mx[mxn],my[mxn];
int ans = 0;
bitset<mxn> vis;

bool dfs(int now){
	vis[now] = true;
	for(auto &i:paths[now]){
		if(!my[i]){
			my[i] = now;
			mx[now] = i;
			return true;
		}
		else if(!vis[my[i]]&&dfs(my[i])){
			my[i] = now;
			mx[now] = i;
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
	for(int i = 1;i<=n;i++){
		vis.reset();
		if(dfs(i))ans++;
	}
	cout<<ans;
}
