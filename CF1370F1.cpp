#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
vector<int> tree[mxn];
bitset<mxn> active;
int dep[mxn];
int fa[mxn];
int n;
vector<int> dv[mxn];
pii dp[mxn];
int C = 0;

inline pii ask(vector<int> vv){
	C++;
	cout<<"? "<<vv.size()<<' ';
	for(auto &i:vv)cout<<i<<' ';
	cout<<endl;
	pii re;
	cin>>re.fs>>re.sc;
	if(re.fs == -1)exit(0);
	return re;
}

void dfs(int now,int par){
	fa[now] = par;
	dv[dep[now]].push_back(now);
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt,now);
	}
	return;
}

void solve(){
	C = 0;
	active.reset();
	for(int i =0 ;i<=n;i++){
		tree[i].clear();
		dp[i] = {0,0};
		dv[i].clear();
	}
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<int> v;
	for(int i= 1;i<=n;i++)v.push_back(i);
	auto tmp = ask(v);
	int rt = tmp.fs;
	int dis = tmp.sc;
	dep[rt] = 0;
	dfs(rt,rt);
	int l = 1,r = *max_element(dep+1,dep+n+1);
	r = min(r,dis);
	while(l != r){
		int mid = (l+r+1)>>1;
		dp[mid] = tmp = ask(dv[mid]);
		if(tmp.sc == dis)l = mid;
		else r = mid-1;
	}
	if(!dp[l].fs)dp[l] = ask(dv[l]);
	int ans1 = dp[l].fs;
	for(int i = ans1;i!=rt;i = fa[i])active[i] = true;
	int d2 = dis-l;
	v.clear();
	for(auto &i:dv[d2]){
		if(!active[i])v.push_back(i);
	}
	int ans2 = ask(v).fs;
	cout<<"! "<<ans1<<' '<<ans2<<endl;
	string re;
	cin>>re;
	if(re != "Correct")exit(0);
	assert(C<=12);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
