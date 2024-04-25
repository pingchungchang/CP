#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll a,b,x,y,n;
	cin>>a>>b>>x>>y>>n;
	if(a<b){
		swap(a,b);
		swap(x,y);
	}
	ll ans  = 1e18;

	ll dx = a-x;
	if(dx>=n)ans = min(ans,(a-n)*b);
	else ans = min(ans,(x)*max(y,b-n+dx));

	dx = b-y;
	if(dx>=n)ans = min(ans,a*(b-n));
	else ans = min(ans,max(x,a-n+dx)*(y));

	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
