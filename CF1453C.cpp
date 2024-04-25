#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define int ll
#define _all(T) T.begin(),T.end()
int n;
vector<string> v;
ll f(int tar){
	ll lr = n,hr = 0,lc = n,hc = 0;;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(v[i][j] == '0'+tar){
				lr = min(i,lr);
				hr = max(i,hr);
				lc = min(lc,j);
				hc = max(hc,j);
			}
		}
	}
//	cout<<tar<<' '<<hc<<' '<<lc<<endl;
	ll re =0;
	for(int i = 0;i<n;i++){
		pll p = {n,-1};
		for(int j = 0;j<n;j++){
			if(v[i][j] == '0'+tar){
				p.fs = min(p.fs,j);
				p.sc = max(p.sc,j);
			}
		}
		ll mh = max(hr-i,i-lr);
		if(mh >= 0)re = max({re,(p.sc-p.fs)*max(n-1-i,i),(n-1-p.fs)*mh,(p.sc)*mh});
//		cout<<i<<' '<<p.fs<<' '<<p.sc<<' '<<mh<<' '<<tar<<' '<<re<<endl;
	}
//	cout<<tar<<' '<<re<<',';
	for(int i = 0;i<n;i++){
		pll p = {n,-1};
		for(int j = 0;j<n;j++){
			if(v[j][i] == '0'+tar){
				p.fs = min(p.fs,j);
				p.sc = max(p.sc,j);
			}
		}
		ll mc = max(hc-i,i-lc);
//		cout<<i<<' '<<tar<<' '<<mc<<endl;
		if(mc>=0)re = max({re,(p.sc-p.fs)*max(n-1-i,i),(n-1-p.fs)*mc,p.sc*mc});
//		cout<<i<<' '<<p.fs<<' '<<p.sc<<' '<<mc<<' '<<tar<<' '<<re<<endl;
	}
	return re;
}
void solve(){
	cin>>n;
	v = vector<string>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	ll ans[10];
	for(int i = 0;i<10;i++)ans[i] = f(i);
//	cout<<f(2)<<endl;
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

