#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
const ll mod = 998244353;
bitset<mxn> isp;
ll fac[mxn],ifac[mxn];
int cnt[mxn];
vector<ll> p,np,pref;
ll dp[5000][3030];
int n;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){return pw(k,mod-2);}

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}


inline ll C(ll a,ll b){
	assert(a<mxn&&b<mxn);
	if(a<b)return 0ll;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	isp[1] = true;
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			for(int j = i+i;j<mxn;j+=i){
				isp[j] = true;
			}
		}
	}
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
		ifac[i] = inv(fac[i]);
	}
	cin>>n;
	for(int i = 0;i<n*2;i++){
		int k;
		cin>>k;
		cnt[k]++;
	}
	for(int i = 1;i<mxn;i++){
		if(!cnt[i])continue;
		if(isp[i])np.push_back(cnt[i]);
		else p.push_back(cnt[i]);
	}
	pref.push_back(0ll);
	for(int i = 0;i<p.size();i++){
		pref.push_back(pref.back()+p[i]);
	}
	dp[0][0] = 1;
	for(int i = 1;i<=p.size();i++){
		dp[i][0] = dp[i-1][0]*C(n-pref[i-1],p[i-1])%mod;
		for(int j = 1;j<=n;j++){
		dp[i][j] = mad(dp[i-1][j]*C(n-(pref[i-1]-j),p[i-1])%mod,dp[i-1][j-1]*C(n-(pref[i-1]-(j-1)),p[i-1]-1)%mod);
		}
	}

	/*
	cout<<C(5,3)<<endl;
	for(auto &i:p)cout<<i<<',';cout<<endl;
	for(auto &i:np)cout<<i<<',';cout<<endl;
	for(auto &i:pref)cout<<i<<',';cout<<endl;
	for(int i = 0;i<=p.size();i++){
		for(int j = 0;j<=n;j++)cout<<setw(5)<<dp[i][j]<<' ';cout<<endl;
	}
   */
	ll tans = dp[p.size()][n];
	ll rest = n*2-pref.back();
	for(auto &j:np){
		tans = tans*C(rest,j)%mod;
		rest -= j;
	}
	cout<<tans;
}
