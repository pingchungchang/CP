#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 1e6+10;
ll dp[mxn];

ll calc(ll a,ll b){
	a--;
	return b*(b+1)*(b*2+1)/6-a*(a+1)*(a*2+1)/6;
}

void solve(){
	ll n;
	cin>>n;
	ll level = 0;
	ll l = 0,r = 2023;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(mid*(mid+1)/2>=n)r = mid-1;
		else l = mid;
	}
	level = l;
	ll s,e;
	s = n-(level+1)*level/2;e = s;
	//cout<<level<<','<<s<<','<<e<<'\n';
	ll ans = calc(n,n);
	while(level){
		e = min(e,level);
		s = max(s-1,1LL);
		level--;
		ll sh = level*(level+1)/2;
		ans += calc(sh+s,sh+e);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
