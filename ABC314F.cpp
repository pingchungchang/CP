#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 998244353;
const int mxn = 4e5+10;
int dsu[mxn],sz[mxn];
int n;
vector<int> tree[mxn];
ll dp[mxn];
int ptr = 0;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	dsu[b] = a;
}

void dfs(int now){
	sz[now] = 0;
	if(tree[now].empty()){
		sz[now] = 1;
		return;
	}
	for(auto nxt:tree[now]){
		dfs(nxt);
		sz[now] += sz[nxt];
	}
	return;
}
void dfs2(int now){
	if(tree[now].empty())return;
	int lp = tree[now][0],rp = tree[now][1];
	dp[lp] = mad(dp[now],sz[lp]*inv(sz[now])%mod);
	dp[rp] = mad(dp[now],sz[rp]*inv(sz[now])%mod);
	dfs2(lp);
	dfs2(rp);
	//cout<<now<<":"<<sz[now]<<' '<<lp<<' '<<rp<<endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<mxn;i++){
		dsu[i] = i;
	}
	ptr = n+1;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		a = root(a),b = root(b);
		tree[ptr].push_back(a);
		tree[ptr].push_back(b);
		onion(ptr,a);
		onion(ptr,b);
		ptr++;
	}
	dfs(root(1));
	dfs2(root(1));
	for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';
}
