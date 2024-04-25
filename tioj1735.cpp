#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e5+10;
const ll mod = 998244353;
const ll p = 31;
int len;
int n;
string s;
ll pref[mxn];

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

void solve(){
	cin>>s;
	n = s.size();
	s = "#"+s;
	ll pp = 1;
	for(int i = 1;i<=n;i++){
		pref[i] = mad(pref[i-1],pp*(s[i]-'a'+1)%mod);
		pp = pp*p%mod;
	}
	ll rev = pw(inv(p),len);
	ll ans = 0;
	for(int i = len*2;i<=n;i++){
		ll ta = mub(pref[i],pref[i-len]),tb = mub(pref[i-len],pref[i-len*2]);
		//cout<<i<<":"<<ta*rev%mod<<' '<<tb<<',';
		if(ta*rev%mod == tb)ans++;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>len)solve();
}
