#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	ll n,b,x,y;
	cin>>n>>b>>x>>y;
	ll now = 0;
	ll ans = 0;
	for(ll i = 1;i<=n;i++){
		if(now+x<=b)now += x;
		else now -= y;
		ans += now;
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

