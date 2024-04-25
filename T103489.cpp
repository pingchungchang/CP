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
int low[mxn],idx[mxn],gid[mxn];
int cnt = 0;
int gcnt = 0;
vector<int> st;
void dfs(int now,int par){
	low[now] = idx[now] = ++cnt;
	st.push_back(now);
//	cout<<now<<' '<<par<<' '<<idx[now]<<endl;
	for(auto nxt:paths[now]){
		if(nxt == par)continue;
		if(idx[nxt] != 0)low[now] = min(low[now],low[nxt]);
		else{
			dfs(nxt,now);
			low[now] = min(low[now],low[nxt]);
		}
	}
	if(low[now] == idx[now]){
		gcnt++;
		while(st.back() != now){
			gid[st.back()] = gcnt;
			st.pop_back();
		}
		gid[now] = gcnt;
		st.pop_back();
	}
	return;
}
int main(){	
	io
	ll n,m;
	cin>>n>>m;
	for(int i= 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		if(!idx[i])dfs(i,-1);
	}
	cout<<gcnt;
}

