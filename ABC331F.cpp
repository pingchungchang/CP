#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const pll p = {31,37};
const ll mod = 712271227;
const ll mxn = 1e6+10;
ll n,q;
string s;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
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

struct Hint{
	pll val;
	Hint(){
		val = make_pair(0,0);
	}
	Hint(ll a,ll b){
		val = make_pair(a,b);
	}
	Hint(pll v){
		val = v;
	}
	const Hint operator+(Hint b)const{
		Hint re;
		re.val.fs = mad(val.fs,b.val.fs);
		re.val.sc = mad(val.sc,b.val.sc);
		return re;
	}
	const Hint operator-(Hint b)const{
		return (*this)+Hint(mod-b.val.fs,mod-b.val.sc);
	}
	const Hint operator*(Hint b)const{
		Hint re;
		re.val.fs = val.fs*b.val.fs%mod;
		re.val.sc = val.sc*b.val.sc%mod;
		return re;
	}
	const Hint operator*(ll b)const{
		Hint re;
		re.val.fs = val.fs*b%mod;
		re.val.sc = val.sc*b%mod;
		return re;
	}
};
Hint bit1[mxn],bit2[mxn];
Hint P[mxn],iP[mxn];

void modify(Hint bit[],ll p,Hint v){
	for(;p<mxn;p+=p&-p){
		bit[p] = bit[p]+v;
	}
	return;
}
Hint getval(Hint bit[],int s,int e){
	Hint re;
	for(;e>0;e-= e&-e){
		re = re+bit[e];
	}
	s--;
	for(;s>0;s-= s&-s){
		re = re-bit[s];
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	P[1] = Hint(p.fs,p.sc);
	iP[1] = Hint(inv(p.fs),inv(p.sc));
	P[0] = iP[0] = Hint(1,1);
	for(int i = 2;i<mxn;i++){
		P[i] = P[i-1]*P[1];
		iP[i] = iP[i-1]*iP[1];
	}
	cin>>s;
	s = "#"+s;
	for(int i = 1;i<=n;i++){
		modify(bit1,i,P[i]*(s[i]-'a'+1));
		modify(bit2,i,P[n-i]*(s[i]-'a'+1));
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int p;
			char c;
			cin>>p>>c;
			modify(bit1,p,Hint(mod,mod)-(P[p]*(s[p]-'a'+1)));
			modify(bit2,p,Hint(mod,mod)-(P[n-p]*(s[p]-'a'+1)));
			s[p] = c;
			modify(bit1,p,(P[p]*(s[p]-'a'+1)));
			modify(bit2,p,(P[n-p]*(s[p]-'a'+1)));
		}
		else{
			ll l,r;
			cin>>l>>r;
			Hint ta = getval(bit1,l,r),tb = getval(bit2,l,r);
			ta = ta*iP[l];
			tb = tb*iP[n-r];
			if(ta.val.fs == tb.val.fs&&ta.val.sc == tb.val.sc)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
