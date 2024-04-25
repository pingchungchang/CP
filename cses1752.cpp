#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
vector<int> tree[mxn];
int N;
set<pii> st[mxn];
int dep[mxn];
int D;

void dfs(int now,int par){
	st[now].insert(pii(dep[now],now));
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt,now);
		if(!st[now].empty()&&!st[nxt].empty()){
			int d = st[now].begin()->fs+st[nxt].begin()->fs-dep[now]*2;
			if(d<D){
				if(st[now].begin()->fs<st[nxt].begin()->fs)st[now].erase(*st[now].begin());
				else st[nxt].erase(*st[nxt].begin());
			}
		}
		if(st[now].size()<st[nxt].size())swap(st[now],st[nxt]);
		while(!st[nxt].empty()){
			st[now].insert(*st[nxt].begin());
			st[nxt].erase(*st[nxt].begin());
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>D;
	for(int i = 1;i<N;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	cout<<st[1].size()<<'\n';
	for(auto &i:st[1])cout<<i.sc<<' ';cout<<'\n';
	return 0;
}
