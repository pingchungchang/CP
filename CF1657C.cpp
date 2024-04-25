#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7;
const ll h1 = 3;
const ll h2 = 2;
const ll invmod = 333333336;
ll pw1(ll k){
	ll ans = 1;
	ll pd = h1;
	while(k != 0){
		if((k&1))ans *= pd;
		k>>=1;
		pd  = (pd*pd)%mod;
		ans  %= mod;
	}
	return ans;
}
ll pw2(ll k){
	ll ans = 1;
	ll pd = h2;
	while(k != 0){
		if((k&1))ans *= pd;
		k>>=1;
		pd  = (pd*pd)%mod;
		ans  %= mod;
	}
	return ans;
}
void solve(){
	int n;
	string s;
	cin>>n>>s;
	string pref;
	pll phash = make_pair(0,0);
	pll shash = make_pair(0,0);
	int t = 0;
	int p = 0;
	for(int i = 0;i<n;i++){
		pref += s[i];
		phash.fs = (phash.fs*h1)%mod;
		phash.fs = (phash.fs+s[i]-'(')%mod;
		shash.fs = (shash.fs +pw1(1LL*i-p)*(s[i]-'('))%mod;
		phash.sc = (phash.sc*h2)%mod;
		phash.sc = (phash.sc+s[i]-'(')%mod;
		shash.sc = (shash.sc +pw2(1LL*i-p)*(s[i]-'('))%mod;
//		cout<<i<<' '<<p<<' '<<pref<<' '<<phash.sc<<' '<<shash.sc<<'\n';
		if(pref.size() == 1)continue;
		if(pref == "()"||pref == "))"||pref == "(("){
			pref = "";
			p = i+1;
			t++;
			phash = make_pair(0,0);
			shash = make_pair(0,0);
		}
		else if(phash.fs == shash.fs&&phash.sc == shash.sc){
			p = i+1;
			t++;
			pref = "";
			phash = make_pair(0,0);
			shash = make_pair(0,0);
		}
	}
	cout<<t<<' '<<(n-p)<<'\n';
}

int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

