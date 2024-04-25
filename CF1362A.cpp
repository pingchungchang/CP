#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll a,b;
	cin>>a>>b;
	if(b>a)swap(a,b);
	if(a%b != 0){
		cout<<"-1\n";
		return;
	}
	ll d = a/b;
	ll ans = 0;
	while(!(d&1)){
		d>>=1;
		ans++;
	}
	if(d != 1)cout<<"-1\n";
	else cout<<(ans+2)/3<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
