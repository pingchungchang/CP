#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define pc __builtin_popcount

const int mxn = 2e5+10;
vector<int> tree[mxn];
int dep[mxn],arr[mxn];
pii par[mxn][20];
int n;

void dfs(int now){
	for(int i = 1;i<20;i++){
		par[now][i].fs = par[par[now][i-1].fs][i-1].fs;
		par[now][i].sc = par[par[now][i-1].fs][i-1].sc|par[now][i-1].sc;
	}
	for(auto nxt:tree[now]){
		if(nxt == par[now][0].fs)continue;
		dep[nxt] = dep[now]+1;
		par[nxt][0] = {now,arr[now]};
		dfs(nxt);
	}
	return;
}

pii dist(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int dif = dep[a]-dep[b];
	int d = arr[a]|arr[b];
	for(int i = 19;i>=0;i--){
		if(dif&(1<<i)){
			d |= par[a][i].sc;
			a = par[a][i].fs;
		}
	}
	for(int i = 19;i>=0;i--){
		if(par[a][i].fs != par[b][i].fs){
			d |= par[a][i].sc;
			d |= par[b][i].sc;
			a = par[a][i].fs;
			b = par[b][i].fs;
		}
	}
	if(a != b)d|=par[a][0].sc,a = par[a][0].fs;
	return make_pair(a,d);
}

int up(int a,int d){
	for(int i = 19;i>=0;i--){
		if(d&(1<<i))a = par[a][i].fs;
	}
	return a;
}

int calc(int a,int m,int b){
	return __builtin_popcount(dist(a,m).sc)+__builtin_popcount(dist(m,b).sc);
}

void solve(){
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		dep[i] = 0;
	}
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	par[1][0] = {1,arr[1]};
	dfs(1);

	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;

		auto re = dist(a,b);
		int ans = pc(re.sc);
		pii now = {a,arr[a]};
		for(int i = 0;i<=30;i++){
			for(int j = 19;j>=0;j--){
				if(dep[now.fs]-(1<<j)<dep[re.fs])continue;
				if(pc(par[now.fs][j].sc|now.sc)<i){
					now.sc|=par[now.fs][j].sc;
					now.fs = par[now.fs][j].fs;
				}
			}
			ans = max(ans,calc(a,now.fs,b));
			if(dep[now.fs] != dep[re.fs]){
				now.sc |= par[now.fs][0].sc;
				now.fs = par[now.fs][0].fs;
			}
			ans = max(ans,calc(a,now.fs,b));
		}

		now = {b,arr[b]};
		for(int i = 0;i<=30;i++){
			for(int j = 19;j>=0;j--){
				if(dep[now.fs]-(1<<j)<dep[re.fs])continue;
				if(pc(par[now.fs][j].sc|now.sc)<i){
					now.sc|=par[now.fs][j].sc;
					now.fs = par[now.fs][j].fs;
				}
			}
			ans = max(ans,calc(b,now.fs,a));
			if(dep[now.fs] != dep[re.fs]){
				now.sc |= par[now.fs][0].sc;
				now.fs = par[now.fs][0].fs;
			}
			ans = max(ans,calc(b,now.fs,a));
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
	//cout<<"2 6:"<<dist(2,6).fs<<','<<dist(2,6).sc<<endl;return;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
