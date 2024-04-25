#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	if(n&1){
		ll ans = n-1;
		pair<ll,ll> re = {1,n-1};
		for(ll i = 2;i*i<=n;i++){
			if(n%i == 0){
				pll tmp = make_pair(i,n-i);
				if(tmp.fs*tmp.sc/__gcd(tmp.fs,tmp.sc)<re.fs*re.sc/__gcd(re.fs,re.sc))re = tmp;
				tmp  = make_pair(n/i,n-n/i);
				if(tmp.fs*tmp.sc/__gcd(tmp.fs,tmp.sc)<re.fs*re.sc/__gcd(re.fs,re.sc))re = tmp;
			}
		}
		cout<<re.fs<<' '<<re.sc<<'\n';
	}
	else cout<<n/2<<' '<<n/2<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
