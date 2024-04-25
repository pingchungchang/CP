#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

ll hc,dc,k,w,a,hm,dm;
void solve(){
	cin>>hc>>dc>>hm>>dm>>k>>w>>a;
	for(ll x = 0;x<=k;x++){
		if((hc+ x*a + dm -1)/dm >= (hm + dc + (k-x)*w - 1)/(dc + (k-x)*w)){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

