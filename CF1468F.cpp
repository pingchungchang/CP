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

ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
map<pll,ll> mp;
void reg(pll &p){
	ll G = gcd(abs(p.fs),abs(p.sc));
	p = {p.fs/G,p.sc/G};
}
void solve(){
	mp.clear();
	int n;
	cin>>n;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		c -= a,d -= b;
		pll tmp = {c,d};
		reg(tmp);
		ans += mp[{-tmp.fs,-tmp.sc}];
		mp[tmp]++;
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

