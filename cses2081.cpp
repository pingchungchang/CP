#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> tree[mxn];
int sz[mxn],dep[mxn],mx,buf[mxn];
ll ans;
int n,l,r;
int bit[mxn];
bitset<mxn> del;

void modify(int p,int v){
	for(;p<=mx;p+=p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	if(e>mx)e = mx;
	s = max(s-1,0);
	if(s>mx)s = mx;
	int re = 0;
	for(;e>0;e -= e&-e)re += bit[e];
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

void szdfs(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(del[nxt]||nxt == par)continue;
		szdfs(nxt,now);
		sz[now]+=sz[nxt];
	}
	return;
}
int find_centroid(int now,int par,int tar){
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		if(sz[nxt]>tar)return find_centroid(nxt,now,tar);
	}
	return now;
}

vector<int> st;
void dfs1(int now,int par){
	st.push_back(dep[now]);
	//cout<<now<<":"<<dep[now]<<endl;
	ans += getval(l-dep[now]+1,r-dep[now]+1);
	for(auto nxt:tree[now]){
		if(del[nxt]||nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs1(nxt,now);
	}
	return;
}

void cendfs(int now,int par){
	szdfs(now,now);
	int cen = find_centroid(now,now,sz[now]/2);
	del[cen] = true;
	mx = sz[now];
	//cout<<cen<<":"<<ans<<' '<<mx<<endl;
	modify(1,1);
	for(auto nxt:tree[cen]){
		if(del[nxt])continue;
		dep[nxt] = 1;
		dfs1(nxt,nxt);
		while(!st.empty())modify(st.back()+1,1),st.pop_back();
	}
	//for(int i = 1;i<=mx;i++)cout<<getval(i,i)<<' ';cout<<endl;
	fill(bit,bit+mx+1,0);
	for(auto nxt:tree[cen]){
		if(del[nxt])continue;
		cendfs(nxt,cen);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>l>>r;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cendfs(1,1);
	cout<<ans;
}
