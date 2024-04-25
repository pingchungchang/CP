#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 998244353;
const ll mxn = 1<<20;
ll fac[mxn],ifac[mxn];
int tree[mxn+1],arr[mxn],lvl[mxn],tdp[mxn+1];
ll dp[mxn];
int n;
ll coef = 1;

inline ll pw(ll a,ll b,ll m = mod){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%m;
		b>>=1;
		a = a*a%m;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll C(ll a,ll b){
	if(b>a)return 0;
	return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}

void add(int k,int p){
	int now = 1;
	for(int i = n-1;i>=0;i--){
		if((1<<i)&k)now = now*2+1;
		else now = now*2;
	}
	for(int i = 0;i<=n-lvl[p];i++){
		if(tree[now] != -1){
			coef = 0;
			return;
		}
		tree[now] = p;
		now>>=1;
	}
	return;
}

void dfs(int now,int dep){
	if(dep == n){
		return;
	}
	dfs(now*2,dep+1);
	dfs(now*2+1,dep+1);
	if(tree[now]>=0)tdp[now] = true;
	if(tdp[now*2] >= 0||tdp[now*2+1] >= 0)tdp[now] = true;
	return;
}

void dfs2(int now,int dep){
	if(!tdp[now]){
		coef = coef*dp[dep]%mod;
		return;
	}
	if(!dep)return;
	dfs2(now*2,dep-1);
	dfs2(now*2+1,dep-1);
	if(tree[now] == -1&&tree[now*2] == -1&&tree[now*2+1] == -1)coef = coef*2%mod;
	return;
}

void solve(){
	cin>>n;
	memset(arr,-1,sizeof(arr));
	coef = 1;
	int pt = 0;
	for(int i = 0;i<(1<<n);i++){
		int k;
		cin>>k;
		tdp[i] = k-1;
		if(k>0)arr[k-1] = i;
	}
	for(int i = 0;i<=n-1;i++){
		for(int j = 0;j+(1<<i)<(1<<n);j+=1<<(i+1)){
			tdp[j] = min(tdp[j],tdp[j+(1<<i)]);
			//cout<<j<<":"<<tdp[j]<<',';
			if(tdp[j]>=(1<<(n-1-i)))coef = 0;
		}
		//cout<<endl;
	}
	memset(tdp,0,sizeof(tdp));
	lvl[0] = 0;
	memset(tree,-1,sizeof(tree));
	for(int i = 1;i<(1<<n);i++)lvl[i] = lvl[i>>1]+1;
	for(int i = 0;i<(1<<n);i++){
		if(arr[i]>=0)add(arr[i],i);
	}
	dp[0] = 1;
	for(int i = 1;i<=n;i++){
		dp[i] = dp[i-1]*dp[i-1]*2%mod;
	}
	dfs(1,0);
	dfs2(1,n);
	int cnt[n+1] = {};
	for(int i = 0;i<(1<<n);i++)if(arr[i]<0)cnt[lvl[i]]++;
	//for(int i = 0;i<(1<<n);i++)cout<<arr[i]<<' ';cout<<endl;
	for(int i = 0;i<=n;i++)coef = coef*fac[cnt[i]]%mod;
	cout<<coef;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	solve();
}
