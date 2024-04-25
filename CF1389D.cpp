#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	pll r1,r2;
	cin>>n>>k>>r1.fs>>r1.sc>>r2.fs>>r2.sc;
	if(r1.fs>r2.fs)swap(r1,r2);
	ll cnt = n*max(0LL,min(r1.sc,r2.sc)-max(r1.fs,r2.fs));
	if(cnt>=k){
		cout<<"0\n";
		return;
	}
	ll ans = 4e18;
	ll dx = k-cnt;
	if(r1.sc>=r2.fs){
		ans = 0;
		ll tmp = min(dx,(max(r1.sc-r2.sc,r2.sc-r1.sc)+max(r1.fs-r2.fs,r2.fs-r1.fs))*n);
		ans += tmp;
		dx -= tmp;
		ans += dx*2;
		cout<<ans<<'\n';
		return;
	}
	for(int i = 1;i<=n;i++){
		ll ddx = dx;
		ll tans = (r2.fs-r1.sc)*i;
		ll tmp = min(ddx,(r2.sc-r1.fs)*i);
		tans += tmp;
		ddx -= tmp;
		tans += ddx*2;
		ans = min(ans,tans);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
