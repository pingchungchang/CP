#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

ll w,h;
ll x1,x2,y1,y2;
ll f(ll sx,ll sy,ll ex,ll ey){
	ll r = y2-y1;
	ll c = x2-x1;
	ll returns = INT_MAX;
	if(c+ex<=w){
		if(x1>=ex)return 0LL;
		returns = min(returns,abs(ex-x1));
	}
	if(sx-c>=0){
		if(x2<=sx)return 0LL;
		returns = min(returns,abs(x2-sx));
	}
	if(r+ey<=h){
		if(y1>=ey)return 0LL;
		returns = min(returns,abs(y1-ey));
	}
	if(sy-r>=0){
		if(sy>=y2)return 0LL;
		returns = min(returns,abs(sy-y2));
	}
	return returns;
}
void solve(){
	cin>>w>>h;
	cin>>x1>>y1>>x2>>y2;
	ll ww,hh;
	cin>>ww>>hh;
	ld ans = INT_MAX;
	ans = min(ans,(ld)f(0,0,ww,hh));
	ans = min(ans,(ld)f(w-ww,h-hh,w,h));
	ans = min(ans,(ld)f(0,h-hh,ww,h));
	ans = min(ans,(ld)f(w-ww,0,w,hh));
	if(ans == INT_MAX)cout<<"-1\n";
	else cout<<fixed<<setprecision(8)<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

