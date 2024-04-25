#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<pll> tree[mxn];
pll par[mxn][20];
int centree[mxn];
int sz[mxn],dep[mxn];
pll dp[mxn];
ll dif[mxn];
pll pars[mxn][20];
bitset<mxn> done;
int n,q;

void dfs1(int now){
	for(int i = 1;i<20;i++){
		par[now][i].fs = par[par[now][i-1].fs][i-1].fs;
		par[now][i].sc = par[now][i-1].sc+par[par[now][i-1].fs][i-1].sc;
	}
	for(auto nxt:tree[now]){
		if(nxt.fs == par[now][0].fs)continue;
		dep[nxt.fs] = dep[now]+1;
		par[nxt.fs][0] = {now,nxt.sc};
		dfs1(nxt.fs);
	}
}

ll dist(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int d = dep[a]-dep[b];
	ll re = 0;
	for(int i = 18;i>=0;i--){
		if(d&(1<<i))re += par[a][i].sc,a = par[a][i].fs;
	}
	for(int i = 18;i>=0;i--){
		if(par[a][i].fs != par[b][i].fs){
			re += par[a][i].sc;
			re += par[b][i].sc;
			a = par[a][i].fs,b = par[b][i].fs;
		}
	}
	if(a != b){
		re += par[a][0].sc;
		re += par[b][0].sc;
	}
	return re;
}

void szdfs(int now,int fa){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt.fs == fa||done[nxt.fs])continue;
		szdfs(nxt.fs,now);
		sz[now] += sz[nxt.fs];
	}
	return;
}
int find_centroid(int now,int fa,int tar){
	for(auto nxt:tree[now]){
		if(nxt.fs == fa||done[nxt.fs])continue;
		if(sz[nxt.fs]>tar)return find_centroid(nxt.fs,now,tar);
	}
	return now;
}

void cendfs(int now,int fa){
	szdfs(now,now);
	auto cen = find_centroid(now,now,(sz[now]-1)/2);
	centree[cen] = fa;
	done[cen] = true;
	for(auto nxt:tree[cen]){
		if(done[nxt.fs])continue;
		cendfs(nxt.fs,cen);
	}
	return;
}

void add(int k){
	if(done[k])return;
	int now = k;
	done[k] = true;
	dp[now].sc++;
	for(int i = 1;pars[now][i].fs != -1;i++){
		dp[pars[now][i].fs].fs += pars[now][i].sc;
		dp[pars[now][i].fs].sc ++;
		dif[pars[now][i-1].fs] += pars[now][i].sc;
	}
}

ll ask(int k){
	ll re = dp[k].fs;
	int pre = -1,now = k;
	for(int i = 1;pars[now][i].fs != -1;i++){
		ll p = pars[now][i].fs,d = pars[now][i].sc;
		re += dp[p].fs+dp[p].sc*d;
		re -= dif[pars[now][i-1].fs]+dp[pars[now][i-1].fs].sc*d;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	par[0][0] = {0,0};
	dfs1(0);
	cendfs(0,-1);
	done.reset();
	int C = 0;
	for(int i = 0;i<n;i++)if(centree[i] != -1)C++;

	for(int i = 0;i<n;i++){
		int tmp = i;
		int C = 0;
		for(auto &j:pars[i])j = {-1,0};
		while(tmp != -1){
			pars[i][C++] = {tmp,dist(i,tmp)};
			tmp = centree[tmp];
		}
	}

	while(q--){
		int t,x;
		cin>>t>>x;
		if(t == 1){
			add(x);
			//cout<<"add:"<<x<<'\n';
		}
		else cout<<ask(x)<<'\n';
	}
	//for(int i = 0;i<n;i++)cout<<i<<":"<<centree[i]<<','<<dp[i].fs<<' '<<dp[i].sc<<' '<<dif[i]<<endl;
	return 0;
}
