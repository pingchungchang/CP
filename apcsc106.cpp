#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	ll m,n;
	cin>>m>>n;
	vector<pll> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].fs>>v[i].sc;
	}
	ll ans = 0;
	for(ll i = 0;i<(1LL<<n);i++){
		ll w = 0,p = 0;
		for(int j = 0;j<n;j++){
			if((i&(1LL<<j)) != 0){
				w += v[j].fs;
				p += v[j].sc;
			}
		}
		if(w<=m)ans = max(ans,p);
	}
	cout<<ans;
}

