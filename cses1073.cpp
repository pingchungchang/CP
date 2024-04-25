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
bitset<mxn> cut;
vector<int> paths[mxn];
int low[mxn],idx[mxn];
int cnt = 1;
vector<int> st;
int group[mxn];
int gcnt = 0;

void dfs(int now,int par){
	low[now] = idx[now] = cnt++;
	st.push_back(now);
	int c = 0;
	for(auto &nxt:paths[now]){
		if(nxt == par)continue;
		if(idx[nxt]){
			low[now] = min(low[now],idx[nxt]);
		}
		else{
			c++;
			dfs(nxt,now);
			low[now] = min(low[now],low[nxt]);
			if(low[nxt]>=low[now]){
				gcnt++;
				while(st.back() != nxt){
					group[st.back()] = gcnt;
					st.pop_back();
				}
				group[nxt] = gcnt;
				st.pop_back();
				cut[now] = true;
			}
		}
	}
	if(par == -1&&c>1){
		cut[now] = true;
		gcnt++;
	}
	while(!st.empty()){
		group[st.back()] = gcnt;
		st.pop_back();
	}
}
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	dfs(1,-1);
}

