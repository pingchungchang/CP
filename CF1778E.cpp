#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;

struct mat{
	int val[31];
	mat(){
		memset(val,0,sizeof(val));
	}
	int operator[](int k)const{
		return val[k];
	}
	void add(int k){
		if(!k)return;
		for(int i = 30;i>=0;i--){
			if((1<<i)&k){
				if(val[i] == 0){
					val[i] = k;
					return;
				}
				else k^= val[i];
			}
		}
		return;
	}
	int big(){
		int re = 0;
		for(int i = 30;i>=0;i--){
			re = max(re,re^val[i]);
		}
		return re;
	}
	void eat(int k){
		add(k);
	}
	void eat(mat b){
		for(int j = 30;j>=0;j--){
			add(b[j]);
		}
		return;
	}
};

vector<pair<int,mat>> tree[mxn];
vector<mat> pref[mxn],suf[mxn];
mat dp[mxn];
pii par[mxn];
int arr[mxn],ans[mxn];
pii req[mxn];
vector<pii> ask[mxn];
int n,q;
int dfn[mxn];
vector<pii> eul;

void dfs1(int now){
	for(int i = 0;i<tree[now].size();i++){
		int nxt = tree[now][i].fs;
		if(nxt == par[now].fs){
			par[now].sc = i;
			continue;
		}
		par[nxt] = {now,i};
		dfs1(nxt);
		tree[now][i].sc = dp[nxt];
		dp[now].eat(dp[nxt]);
	}
	dp[now].add(arr[now]);
	return;
}

void dfs2(int now){
	for(auto &i:tree[now]){
		pref[now].push_back(i.sc);
		suf[now].push_back(i.sc);
	}
	for(int i = 1;i<tree[now].size();i++){
		pref[now][i].eat(pref[now][i-1]);
	}
	for(int i = (int)suf[now].size()-2;i>=0;i--){
		suf[now][i].eat(suf[now][i+1]);
	}
	for(int i = 0;i<tree[now].size();i++){
		int nxt = tree[now][i].fs;
		if(nxt == par[now].fs)continue;
		mat tmp;
		if(i)tmp.eat(pref[now][i-1]);
		if(i+1 != tree[now].size())tmp.eat(suf[now][i+1]);
		tmp.add(arr[now]);
		tree[nxt][par[nxt].sc].sc = tmp;
		par[nxt].sc = i;
		dfs2(nxt);
	}
	return;
}

void dfs3(int now,int pid = 0){
	dfn[now] = eul.size();
	eul.push_back({now,pid});
	while(!ask[now].empty()){
		auto tmp = ask[now].back();
		ask[now].pop_back();
		if(tmp.fs == now){
			ans[tmp.sc] = dp[1].big();
		}
		else if(dfn[tmp.fs] != -1){
			int p = dfn[tmp.fs]+1;
			p = eul[p].sc;
			mat re;
			if(p)re.eat(pref[tmp.fs][p-1]);
			if(p+1<suf[tmp.fs].size())re.eat(suf[tmp.fs][p+1]);
			re.eat(arr[tmp.fs]);
			ans[tmp.sc] = re.big();
		}
		else{
			ans[tmp.sc] = dp[tmp.fs].big();
		}
	}
	for(auto nxt:tree[now]){
		if(nxt.fs == par[now].fs)continue;
		dfs3(nxt.fs,par[nxt.fs].sc);
	}
	dfn[now] = -1;
	eul.pop_back();
}

void solve(){
	for(int i = 0;i<=n;i++){
		dfn[i] = -1;
		tree[i].clear();pref[i].clear();suf[i].clear();ask[i].clear();
		dp[i] = mat();
		par[i] = {0,0};
		arr[i] = 0;
	}
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back({b,mat()});
		tree[b].push_back({a,mat()});
	}
	cin>>q;
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		ask[a].push_back({b,i});
	}
	dfs1(1);
	dfs2(1);
	dfs3(1);
	/*
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<tree[i].size();j++){
			cout<<i<<' '<<tree[i][j].fs<<":"<<pref[i][j].big()<<endl;
		}
	}

   */
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dfn,-1,sizeof(dfn));
	int t;cin>>t;
	while(t--)solve();
}
