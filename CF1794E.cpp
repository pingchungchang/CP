#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 3e5+10;
const ll mod = 712271227;
vector<ll> primes;
bitset<mxn> isp;
pll p;
pll ip;
vector<int> tree[mxn];
ll cnt[mxn];
int n;
pll dp[mxn];
vector<int> ans;
pll tar;
set<pll> st;

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
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

void dfs1(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs1(nxt,now);
		dp[now].fs = mad(dp[now].fs,dp[nxt].fs*p.fs%mod);
		dp[now].sc = mad(dp[now].sc,dp[nxt].sc*p.sc%mod);
	}
	dp[now].fs = mad(dp[now].fs,1ll);
	dp[now].sc = mad(dp[now].sc,1ll);
	return;
}

void dfs2(int now,int par){
	if(st.find(dp[now]) != st.end())ans.push_back(now);
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		pll tmp = dp[now];
		tmp.fs = mub(tmp.fs,dp[nxt].fs*p.fs%mod);
		tmp.sc = mub(tmp.sc,dp[nxt].sc*p.sc%mod);
		dp[nxt].fs = mad(dp[nxt].fs,tmp.fs*p.fs%mod);
		dp[nxt].sc = mad(dp[nxt].sc,tmp.sc*p.sc%mod);
		dfs2(nxt,now);
	}
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
		}
	}
	p.fs = *lower_bound(primes.begin(),primes.end(),200000);
	p.sc = *(++lower_bound(primes.begin(),primes.end(),200000));
	ip.fs = inv(p.fs);
	ip.sc = inv(p.sc);
	//cout<<p.fs<<' '<<p.sc<<endl;

	cin>>n;
	for(int i = 1;i<n;i++){
		int k;
		cin>>k;
		cnt[k]++;
	}
	pll tmp = make_pair(1,1);
	for(int i = 0;i<=n;i++){
		tar.fs = mad(tar.fs,tmp.fs*cnt[i]%mod);
		tar.sc = mad(tar.sc,tmp.sc*cnt[i]%mod);
		tmp.fs = tmp.fs*p.fs%mod;
		tmp.sc = tmp.sc*p.sc%mod;
	}
	tmp = make_pair(1,1);
	for(int i = 0;i<=n;i++){
		pll tt = tar;
		tt.fs = mad(tt.fs,tmp.fs);
		tt.sc = mad(tt.sc,tmp.sc);
		st.insert(tt);
		tmp.fs = tmp.fs*p.fs%mod;
		tmp.sc = tmp.sc*p.sc%mod;
	}
	for(int i= 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs1(1,1);
	dfs2(1,1);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return 0;
}
