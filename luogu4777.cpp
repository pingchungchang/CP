#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ll __int128_t
//#define ll int
#define int long long

const int mxn = 1e5+10;
pll arr[mxn];
int N;

ll gcd(ll a,ll b){
	if(b>a)swap(a,b);
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

pll extgcd(ll a,ll b,ll c){
	ll G = gcd(a,b);
	if(c%G != 0)return pll(-1,-1);
	a/=G,b/=G,c/=G;
	array<ll,3> ta,tb;
	ta[0] = 1,ta[1] = 0,ta[2] = a;
	tb[0] = 0,tb[1] = 1,tb[2] = b;
	if(ta[2]<tb[2])swap(ta,tb);
	while(tb[2]){
		ll coef = ta[2]/tb[2];
		for(int i = 0;i<3;i++)ta[i] -= tb[i]*coef;
		swap(ta,tb);
	}
	return pll(ta[0]*c,ta[1]*c);
}

ll conv(ll k,ll mod){
	if(k>=0)return k%mod;
	else return (k+(-k+mod-1)/mod*mod)%mod;
}

/*
a1*m1+b1 = a2*m2+b2
a1*m1-a2*m2 = b2-b1
*/

pll calc(pll a,pll b){
	if(a.sc>b.sc)swap(a,b);
	auto tmp = extgcd(a.fs,b.fs,b.sc-a.sc);
	auto ca = tmp.fs;
	//cerr<<a.fs<<' '<<a.sc<<":"<<b.fs<<' '<<b.sc<<":"<<tmp.fs<<' '<<tmp.sc<<endl;
	ll lc = a.fs*b.fs/gcd(a.fs,b.fs);
	ca = conv(ca,lc);
	ll val = ca*a.fs+a.sc;
	val %= lc;
	pll re;
	re.fs = lc,re.sc = val;
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		int in;
		cin>>in;
		arr[i].fs = in;
		cin>>in;arr[i].sc = in;
	}
	for(int i = 2;i<=N;i++){
		arr[i] = calc(arr[i-1],arr[i]);
		//cerr<<arr[i].fs<<','<<arr[i].sc<<endl;
	}
	cout<<(int)arr[N].sc;
}
