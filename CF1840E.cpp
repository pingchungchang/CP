#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;
pll p = {31,37};
inline ll pw(ll a,ll b){
	ll re = 1;
	assert(b>=0);
	while(b){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
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
	if(!b)return a;
	else return mad(a,mod-b);
}
const ll mxn = 4e5+10;
string s[2];
pll hval[2];
vector<ll> op[mxn];

void solve(){
	hval[0] = hval[1] = {0LL,0LL};
	cin>>s[0]>>s[1];
	for(int i = 0;i<s[0].size();i++){
			hval[0].fs = mad(hval[0].fs,pw(p.fs,i)*(s[0][i]-'a'+1)%mod);
			hval[1].fs = mad(hval[1].fs,pw(p.fs,i)*(s[1][i]-'a'+1)%mod);
			hval[0].sc = mad(hval[0].sc,pw(p.sc,i)*(s[0][i]-'a'+1)%mod);
			hval[1].sc = mad(hval[1].sc,pw(p.sc,i)*(s[1][i]-'a'+1)%mod);
	}
	ll t,q;
	cin>>t>>q;
	for(int ii = 0;ii<q;ii++){
		int tp;
		cin>>tp;
		//cout<<hval[0].fs<<','<<hval[1].sc<<' ';
		for(auto &i:op[ii]){
			hval[0].fs = mad(hval[0].fs,pw(p.fs,i-1)*(s[0][i-1]-'a'+1)%mod);
			hval[1].fs = mad(hval[1].fs,pw(p.fs,i-1)*(s[1][i-1]-'a'+1)%mod);
			hval[0].sc = mad(hval[0].sc,pw(p.sc,i-1)*(s[0][i-1]-'a'+1)%mod);
			hval[1].sc = mad(hval[1].sc,pw(p.sc,i-1)*(s[1][i-1]-'a'+1)%mod);
		}
		if(tp == 3){
			//cout<<s[0]<<' '<<s[1]<<'\n';
			cout<<((hval[0].fs^hval[1].fs)||(hval[0].sc^hval[1].sc)?"NO\n":"YES\n");
		}
		else if(tp == 2){
			pll a,b;
			cin>>a.fs>>a.sc>>b.fs>>b.sc;
			a.fs--;b.fs--;
			pll pp = {pw(p.fs,a.sc-1),pw(p.sc,a.sc-1)};
			pll ppp = {pw(p.fs,b.sc-1),pw(p.sc,b.sc-1)};
			hval[a.fs].fs = mub(hval[a.fs].fs,pp.fs*(s[a.fs][a.sc-1]-'a'+1)%mod);
			hval[b.fs].fs = mub(hval[b.fs].fs,ppp.fs*(s[b.fs][b.sc-1]-'a'+1)%mod);
			hval[a.fs].sc = mub(hval[a.fs].sc,pp.sc*(s[a.fs][a.sc-1]-'a'+1)%mod);
			hval[b.fs].sc = mub(hval[b.fs].sc,ppp.sc*(s[b.fs][b.sc-1]-'a'+1)%mod);
			swap(s[a.fs][a.sc-1],s[b.fs][b.sc-1]);
			hval[a.fs].fs = mad(hval[a.fs].fs,pp.fs*(s[a.fs][a.sc-1]-'a'+1)%mod);
			hval[b.fs].fs = mad(hval[b.fs].fs,ppp.fs*(s[b.fs][b.sc-1]-'a'+1)%mod);
			hval[a.fs].sc = mad(hval[a.fs].sc,pp.sc*(s[a.fs][a.sc-1]-'a'+1)%mod);
			hval[b.fs].sc = mad(hval[b.fs].sc,ppp.sc*(s[b.fs][b.sc-1]-'a'+1)%mod);
		}
		else if(tp == 1){
			ll pos;
			cin>>pos;
			op[min(1LL*ii+t,q)].push_back(pos);
			pos--;
			pll pp = {pw(p.fs,pos),pw(p.sc,pos)};
			hval[0].fs = mub(hval[0].fs,pp.fs*(s[0][pos]-'a'+1)%mod);
			hval[1].fs = mub(hval[1].fs,pp.fs*(s[1][pos]-'a'+1)%mod);
			hval[0].sc = mub(hval[0].sc,pp.sc*(s[0][pos]-'a'+1)%mod);
			hval[1].sc = mub(hval[1].sc,pp.sc*(s[1][pos]-'a'+1)%mod);
			//cout<<hval[0].fs<<' ';
		}
	}
	for(int i = 0;i<=q;i++)op[i].clear();
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
