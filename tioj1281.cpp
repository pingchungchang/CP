#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mod = 1e9+7;
const ll mod1 = 998244353;
//const ll p = 29;
const ll mxn = 1e5+10;
const ll p = 17;
const ll pw(ll a,ll b,ll m){
	ll re= 1;
	while(b){
		if(b&1)re = re*a%m;
		b>>=1;
		a = a*a%m;
	}
	return re;
}
int n;
string s;
string f(ll k){
	string re = "-1";
	set<pll> st;
	pll tmp = {0,0};
	pll pp = {1,1};
	for(int i = 0;i<k;i++){
		tmp = {pp.fs*(s[i]-'a')+tmp.fs,tmp.sc+pp.sc*(s[i]-'a')};
		pp = {pp.fs*p%mod,pp.sc*p%mod1};
		tmp.fs %=mod;
		tmp.sc %= mod1;
	}
	pll inv = {pw(p,mod-2,mod),pw(p,mod1-2,mod1)};
	pp = {pp.fs*inv.fs%mod,pp.sc*inv.sc%mod1};
	st.insert(tmp);
	for(int i = k;i<n;i++){
		tmp.fs -= (s[i-k]-'a');
		tmp.sc -= (s[i-k]-'a');
		if(tmp.fs<0)tmp.fs += mod;
		if(tmp.sc<0)tmp.sc += mod1;
		tmp = {tmp.fs*inv.fs,tmp.sc*inv.sc};
		tmp.fs += pp.fs*(s[i]-'a');
		tmp.sc += pp.sc*(s[i]-'a');
		tmp.fs %= mod;
		tmp.sc %= mod1;
		if(st.find(tmp) != st.end()&&re == "-1"){
			re = s.substr(i-k+1,k);
		}
		st.insert(tmp);
	}
	return re;
}
int main(){
	io
	cin>>s;
	n = s.size();
	ll l = 1,r = s.size();
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(f(mid) != "-1")l = mid;
		else r = mid-1;
	}
	cout<<f(l);
	return 0;
}

