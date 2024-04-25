#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const ll inf = 1e18;
const int mxn = 2e5+10;
int N;
deque<pll> ldq[mxn],rdq[mxn];
vector<int> tree[mxn];
int arr[mxn];
ll dp[mxn],dep[mxn];
vector<int> v[mxn];
int mx[mxn],mn[mxn],par[mxn];

void init(){
	for(int i = 0;i<=N+1;i++){
		ldq[i].clear();rdq[i].clear();tree[i].clear();v[i].clear();
		dep[i] = 0;arr[i] = 0;dp[i] = 0,par[i] = 0;
		mx[i] = 0;mn[i] = inf;
	}
	return;
}

void dfs(int now){
	for(auto nxt:tree[now]){
		if(nxt == par[now])continue;
		par[nxt] = now;
		dfs(nxt);
		dep[now] = dep[nxt]+1;
	}
	mx[dep[now]] = max(mx[dep[now]],arr[now]);
	mn[dep[now]] = min(mn[dep[now]],arr[now]);
	v[dep[now]].push_back(now);
}

ll getval(ll val,int d){
	ll re = 0;
	auto lit = upper_bound(ldq[d].begin(),ldq[d].end(),pll(val+1,-inf));
	if(lit != ldq[d].begin()){
		lit--;
		re = max(re,lit->sc+val);
	}
	auto rit = upper_bound(rdq[d].begin(),rdq[d].end(),pll(val,-inf));
	if(rit != rdq[d].end()){
		re = max(re,rit->sc-val);
	}
	return re;
}

void add(ll pos,ll pval,ll val,int d){
	if(!ldq[d].empty()&&ldq[d].back().fs == pos)ldq[d].back().sc = max(ldq[d].back().sc,val-pval);
	else if(ldq[d].empty()||ldq[d].back().sc<val-pval)ldq[d].push_back(pll(pos,val-pval));

	while(!rdq[d].empty()&&val+pval>=rdq[d].back().sc)rdq[d].pop_back();
	if(!rdq[d].empty()&&rdq[d].back().fs == pos)rdq[d].back().sc = max(rdq[d].back().sc,val+pval);
	else rdq[d].push_back(pll(pos,val+pval));
	return;
}

vector<int> tv;

void solve(){
	init();
	cin>>N;
	for(int i = 2;i<=N;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
		tree[i].push_back(p);
	}
	for(int i = 2;i<=N;i++)cin>>arr[i];
	dfs(1);
	for(int i = 0;!v[i].empty();i++){
		sort(v[i].begin(),v[i].end(),[](int a,int b){return arr[par[a]]<arr[par[b]];});
		for(auto &now:v[i]){
			dp[now] = max(arr[now]-mn[i],mx[i]-arr[now]);
			for(auto nxt:tree[now]){
				dp[now] = max(dp[now],dp[nxt]+max(arr[now]-mn[i],mx[i]-arr[now]));
			}
			dp[now] = max(getval(arr[now],i),dp[now]);
			add(arr[par[now]],arr[par[now]],dp[now],i+1);
		}
	}
	//for(int i = 1;i<=N;i++)cerr<<dp[i]<<' ';cerr<<endl;
	cout<<dp[1]<<'\n';
	tv.push_back(dp[1]);
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(mn,mn+mxn,inf);
	int t;cin>>t;
	for(int i = 1;i<=t;i++){
		solve();
	}
}
