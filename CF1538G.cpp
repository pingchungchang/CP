#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll x,y,a,b;
	cin>>x>>y>>a>>b;
	if(x>y)swap(x,y);
	if(a>b)swap(a,b);
	if(a == b){
		cout<<x/a<<'\n';
		return;
	}
	ll ans = 0;
	ll tx = x,ty = y;
	ll d1 = y-x,d2 = b-a;
	ll k = min(d1/d2,min(x/a,y/b));
	ll tans = k;
	tx -= k*a,ty -= k*b;
	tans += min(tx/(a+b),ty/(a+b))*2;
	ans = max(ans,tans);
	tans = k;
	tx = x-k*a,ty= y-k*b;
	if(tx>=a&&ty>=b)tx -= a,ty -= b,tans++;
	tans += min(tx/(a+b),ty/(a+b))*2;
	ans = max(ans,tans);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
/*
n,m
an+bm<=x
am+bn<=y
(n+m)(a+b)<=x+y
n+m<=(x+y)/(a+b)
*/
