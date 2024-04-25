#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


struct D{
	ll a,b,c;
	D(){
		a = b = c = 0;
	}
	D(ll aa,ll bb,ll cc):a(aa),b(bb),c(cc){}
};

inline D calc(D a,D b){
	if(a.c<b.c)swap(a,b);
	while(b.c != 0){
		ll tmp = a.c/b.c;
		a.a -= tmp*b.a;
		a.b -= tmp*b.b;
		a.c -= tmp*b.c;
		swap(a,b);
	}
	return a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll x,y;
	cin>>y>>x;
	D ta(1,0,x),tb(0,1,y);
	if(ta.c<0)ta = D(-1,0,-x);
	if(tb.c<0)tb = D(0,-1,-y);
	auto a = calc(ta,tb);
	if(a.c == 1){
		a.a *= 2;
		a.b *= 2;
		a.c *= 2;
	}
	if(a.c != 2)cout<<"-1";
	else cout<<a.a<<' '<<-a.b;
}
