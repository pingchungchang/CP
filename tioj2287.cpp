#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")

const ll mod = 998244353;
const int mxn = 1e5+10;
vector<pll> fac[mxn];
int N;
pll arr[mxn];
ll dp[mxn];
ll rc[mxn],rs[mxn];
ll lpf[mxn];
ll cnt1[mxn],cnt2[mxn];

int mad(int a,int b){
	if(a>=mod)a %= mod;
	if(b>=mod)b %= mod;
	 a += b;
	 return a>=mod?a-mod:a;
}
int mub(int a,int b){
	if(a>=mod)a %= mod;
	if(b>=mod)b %= mod;
	return mad(a,mod-b);
}

struct mat{
	ll arr[3][3];
	mat(){
		memset(arr,0,sizeof(arr));
	}
	mat operator*(mat b)const{
		mat re;
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				for(int k = 0;k<3;k++){
					re.arr[i][j] = mad(re.arr[i][j],arr[i][k]*b.arr[k][j]%mod);
				}
			}
		}
		return re;
	}
};

void dec(int a,int b){
	for(int i = 1;i*i<=a;i++){
		if(a%i == 0){
			fac[i].push_back(pii(a,b));
			cnt1[i] += b;
			cnt2[i] = mad(cnt2[i],1ll*a*b%mod);
			if(i*i != a)cnt1[a/i] += b,cnt2[a/i] = mad(cnt2[a/i],1ll*a*b%mod),fac[a/i].push_back(pii(a,b));
		}
	}
	return;
}

void process(int now){
	int tmp = now;
	vector<int> v;
	while(tmp != 1){
		if(v.empty()||v.back() != lpf[tmp])v.push_back(lpf[tmp]);
		tmp/=lpf[tmp];
	}
	for(int i = 0;i<(1<<v.size());i++){
		tmp = 1;
		for(int j = 0;j<v.size();j++){
			if(i&(1<<j))tmp *= v[j];
		}
		if(__builtin_popcount(i)&1){
			rs[now] = mub(rs[now],cnt2[tmp]);
			rc[now] -= cnt1[tmp];
		}
		else{
			rs[now] = mad(rs[now],cnt2[tmp]);
			rc[now] += cnt1[tmp];
		}
	}
	return;
}

void prec(){
	for(int i = 1;i<mxn;i++){
		process(i);
	}
}

void calc(int now){
	if(fac[now].empty())return;
	mat nmat = mat();
	for(int i = 0;i<3;i++)nmat.arr[i][i] = 1;
	for(auto &i:fac[now]){
		mat tmp = mat();
		for(int j = 0;j<3;j++)tmp.arr[j][j] = 2;
		tmp.arr[0][1] = 2ll*i.fs;
		tmp.arr[0][2] = 1ll*i.fs*i.fs%mod;
		tmp.arr[1][2] = i.fs;
		ll p = i.sc;
		while(p){
			if(p&1)nmat = nmat*tmp;
			p>>=1;
			tmp = tmp*tmp;
		}
	}
	dp[now] = mad(rc[now]*nmat.arr[0][2]%mod,rs[now]*nmat.arr[1][2]%mod);
	for(int i = now+now;i<mxn;i+=now)dp[now] = mub(dp[now],dp[i]);
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>arr[i].fs>>arr[i].sc;
		dec(arr[i].fs,arr[i].sc);
	}
	prec();
	for(int i = 1;i<=10;i++)cout<<i<<":"<<rs[i]<<' '<<rc[i]<<endl;
	for(int i = mxn-1;i>=0;i--){
		calc(i);
	}
	ll ans = 0;
	for(int i = 1;i<mxn;i++){
		if(dp[i])cout<<i<<":"<<dp[i]<<endl;
	}
	for(int i = 2;i<mxn;i++)ans = mad(ans,dp[i]);
	cout<<ans<<'\n';return 0;
}
