#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	if(k>=50){
		cout<<"0\n";
		return;
	}
	pll pre = {1,0},now = {0,1};
	k -= 2;
	while(k--){
		swap(pre,now);
		now.fs += pre.fs,now.sc += pre.sc;
		if(now.fs>=1e9||now.sc>=1e9){
			cout<<"0\n";
			return;
		}
	}
	ll ans = 0;
	//cout<<now.fs<<' '<<now.sc<<'\n';
	for(ll i = 0;i<n;i++){
		if(i*now.fs>n)break;
		ll tmp = n-i*now.fs;
		if(tmp<0||tmp%now.sc != 0)continue;
		ll ii = tmp/now.sc;
		if(ii>=i)ans++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
