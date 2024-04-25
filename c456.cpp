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
const int mxn = 5050;
bitset<mxn> goneto,del;
set<pii> st;
vector<int> paths[mxn];
int deg[mxn];
ll ans;
void dfs(int now){
	goneto[now] = true;
	st.insert({deg[now],now});
	for(auto nxt:paths[now]){
		if(!goneto[nxt])dfs(nxt);
	}
	return;
}
void dfs1(set<int>&tmp,int now){
	tmp.insert(now);
	for(auto nxt:paths[now]){
		if(del[nxt]||tmp.find(nxt) != tmp.end())continue;
		dfs1(tmp,nxt);
	}
	return;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		if(!goneto[i])dfs(i);
		else continue;
		ans = max(ans,(ll)st.size()*st.begin()->fs);
//		for(auto &j:st)cout<<j.fs<<' '<<j.sc<<',';cout<<'\n';
		while(!st.empty()){
			auto now = *st.begin();
			st.erase(*st.begin());
			del[now.sc] = true;
			for(auto nxt:paths[now.sc]){
				if(!del[nxt]){
					st.erase(st.find({deg[nxt],nxt}));
					deg[nxt]--;
					st.insert({deg[nxt],nxt});
				}
			}
			set<int> tmp;
			if(st.empty())break;
			dfs1(tmp,st.begin()->sc);
			if(tmp.size() != st.size()){
				st.clear();
				break;
			}
			ans = max(ans,(ll)st.size()*st.begin()->fs);
		}
	}
	cout<<ans;
}

