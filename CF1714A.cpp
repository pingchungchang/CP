#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	set<pll> st;
	ll n;
	pll p;
	cin>>n>>p.fs>>p.sc;
	for(int i = 0;i<n;i++){
		pll tmp;
		cin>>tmp.fs>>tmp.sc;
		st.insert(tmp);
	}
	st.insert(make_pair(st.begin()->fs+24,st.begin()->sc));
	auto it = st.lower_bound(p);
	ll ans = 60*(it->fs-p.fs)+it->sc-p.sc;
	cout<<ans/60<<' '<<ans%60<<'\n';
	return;
}
int main(){
	io
	ll t;
	cin>>t;
	while(t--)solve();	
}
