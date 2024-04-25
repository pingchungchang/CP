#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
bitset<mxn> isemp;
bitset<mxn> rect;
vector<int> groups[mxn],paths[mxn],tree[mxn],st;
int idx[mxn],low[mxn],cnt,gcnt;
int par[mxn],sz[mxn],link_top[mxn],bs[mxn],dep[mxn];

void tarjan(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(!idx[nxt]){
			tarjan(nxt);
			if(low[nxt]==idx[now]){
				gcnt++;
				int c = 0;
				while(st.back() != nxt){
					c++;
					groups[st.back()].push_back(gcnt);
					tree[gcnt].push_back(st.back());
					tree[st.back()].push_back(gcnt);
					st.pop_back();
				}
				groups[st.back()].push_back(gcnt);
				tree[gcnt].push_back(st.back());
				tree[st.back()].push_back(gcnt);
				st.pop_back();
				groups[now].push_back(gcnt);
				tree[gcnt].push_back(now);
				tree[now].push_back(gcnt);
			}
			low[now] = min(low[now],low[nxt]);
		}
		else {
			low[now] = min(low[now],idx[nxt]);
		}
	}
	// cout<<now<<":";for(auto &i:st)cout<<i<<' ';cout<<endl;
	return;
}
void dfs1(int now){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par[now])continue;
		par[nxt] = now;
		dep[nxt] = dep[now]+1;
		dfs1(nxt);
		sz[now] += sz[nxt];
		if(!bs[now]||sz[bs[now]]<sz[nxt])bs[now] = nxt;
	}
	return;
}
void dfs2(int now,int top){
	link_top[now] = top;
	if(bs[now])dfs2(bs[now],top);
	for(auto nxt:tree[now]){
		if(nxt == par[now]||nxt == bs[now])continue;
		dfs2(nxt,nxt);
	}
	return;
}
int lca(int a,int b){
	int ta = link_top[a],tb = link_top[b];
	while(ta != tb){
		if(dep[ta]<dep[tb]){
			swap(ta,tb);
			swap(a,b);
		}
		a = par[ta];
		ta = link_top[a];
		// cout<<a<<','<<b<<','<<ta<<','<<tb<<endl;
	}
	if(dep[a]<dep[b])return a;
	else return b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	gcnt = n;
	tarjan(1);
	par[1] = 1;
	dep[1] = 1;
	dfs1(1);
	dfs2(1,1);
	// for(int i = 1;i<=n*2;i++){
	// 	for(auto nxt:tree[i])cout<<i<<' '<<nxt<<'\n';
	// }
	// return 0;
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a == c||b == c){
			cout<<"NO\n";
			continue;
		}
		else if(tree[c].size()<=1)cout<<"YES\n";
		else{
			int k = lca(a,b);
			if((lca(a,c) == c||lca(b,c) == c)&&lca(k,c) == k)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	return 0;
}