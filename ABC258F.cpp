//failed
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll b,k,sx,sy,ex,ey;
	cin>>b>>k>>sx>>sy>>ex>>ey;
	if(sx<=b&&sy<=b&&ex<=b&&ey<=b){
		cout<<(abs(sx-ex)+abs(ey-sy))*k<<'\n';
		return;
	}
	ll ans = k*(abs(sx-ex)+abs(sy-ey));
	if(sx>ex){
		swap(sx,ex);
		swap(sy,ey);
	}
	if(sx>=b)ans = min(ans,abs(sx-ex)+abs(ey-sy));
	cout<<ans<<',';
	if(ex>=b)ans = min(ans,abs(b-sx)*k+abs(ex-b)+abs(ey-sy));
	cout<<ans<<',';
	if(sy>ey){
		swap(sx,ex);
		swap(sy,ey);
	}
	if(sy>=b)ans = min(ans,abs(sx-ex)+abs(ey-sy));
	cout<<ans<<',';
	if(ey>=b)ans = min(ans,abs(b-sy)*k+abs(ey-b)+abs(sx-ex));
	cout<<ans<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

