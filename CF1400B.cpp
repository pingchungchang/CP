#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll p,f;
	cin>>p>>f;
	pll cnt;
	pll w;
	cin>>cnt.fs>>cnt.sc>>w.fs>>w.sc;
	ll ans = 0;
	if(w.fs>w.sc){
		swap(w.fs,w.sc);
		swap(cnt.fs,cnt.sc);
	}
	for(ll i = 0;i<=cnt.fs;i++){
		if(i*w.fs>p)break;
		auto cc = cnt;
		cc.fs -= i;
		ll tans = i;
		ll ff = f;
		
		ll d = min(cc.sc,(p-w.fs*i)/w.sc);
		cc.sc -= d;
		tans += d;

		d = min(cc.fs,ff/w.fs);
		ff -= d*w.fs;
		cc.fs -= d;
		tans += d;

		d = min(cc.sc,ff/w.sc);
		cc.sc -= d;
		tans += d;
		ans = max(ans,tans);
		assert(cc.fs>=0&&cc.sc>=0);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
