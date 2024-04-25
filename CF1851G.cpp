#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn],tree[mxn];
int sz[mxn],par[mxn],dep[mxn],bs[mxn],link_top[mxn],idx[mxn],segtree[mxn*4+4],arr[mxn],done[mxn];
int n,m;
int C;


void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] = v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}
int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	return (mid>=e?getval(now*2+1,l,mid,s,e):mid<s?getval(now*2+2,mid+1,r,s,e):max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e)));
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
	idx[now] = C++;
	if(bs[now])dfs2(bs[now],top);
	for(auto nxt:tree[now]){
		if(nxt == par[now]||nxt==bs[now])continue;
		dfs2(nxt,nxt);
	}
	return;
}

int lca(int a,int b){
	int ta = link_top[a],tb = link_top[b];
	int re = 0;
	while(ta != tb){
		if(dep[ta]<dep[tb]){
			swap(a,b);
			swap(ta,tb);
		}
		re = max(re,getval(0,0,mxn,idx[ta],idx[a]));
		a = par[ta];
		ta = link_top[a];
	}
	if(idx[a]>idx[b])swap(a,b);
	return max(re,getval(0,0,mxn,idx[a],idx[b]));
}


void solve(){
	C = 0;
	for(int i = 0;i<=n+1;i++){
		tree[i].clear();
		paths[i].clear();
		done[i] = sz[i] = par[i] = dep[i] = bs[i] = link_top[i] = idx[i] = arr[i] = 0;
	}
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	arr[n+1] = 2e9;
	for(int i = 1;i<=n;i++){
		paths[i].push_back(n+1);
		paths[n+1].push_back(i);
	}
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	vector<pii> v;
	for(int i = 1;i<=n+1;i++)v.push_back({arr[i],i});
	sort(v.begin(),v.end());
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push(v[0]);
	while(!pq.empty()){
		auto now = pq.top().sc;
		pq.pop();
		if(done[now]){
			tree[now].push_back(done[now]);
			tree[done[now]].push_back(now);
		}
		done[now] = -1;
		for(auto nxt:paths[now]){
			if(!done[nxt]){
				done[nxt] = now;
				pq.push({arr[nxt],nxt});
			}
			else if(done[nxt] != -1){
				if(arr[done[nxt]]>arr[now]){
					done[nxt] = now;
				}
			}
		}
	}
	/*

   */
	for(int i = 1;i<=n+1;i++){
		for(auto nxt:tree[i])cout<<i<<" "<<nxt<<'\n';
	}
	cout<<'\n';
	par[1] = 0,dep[1] = 1;
	dfs1(1);
	dfs2(1,1);
	for(int i = 1;i<=n+1;i++)modify(0,0,mxn,idx[i],arr[i]);
	int q;
	cin>>q;
	while(q--){
		int a,b,e;
		cin>>a>>b>>e;
		if(lca(a,b)>arr[a]+e)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
