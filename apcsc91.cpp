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
	ll n,l;
	cin>>n>>l;
	set<pll> st;
	st.insert(make_pair(0,l));
	vector<pll> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].sc>>v[i].fs;
	}
	sort(v.begin(),v.end());
	long long ans = 0;
	for(int i = 0;i<n;i++){
//		for(auto it:st)cout<<it.fs<<' '<<it.sc<<',';cout<<'\n';
		auto it = --st.upper_bound(make_pair(v[i].sc,INT_MAX));
		ans += it->sc-it->fs;
		ll s = it->fs;
		ll e = it->sc;
		st.erase(it);
		if(s != v[i].sc)st.insert(make_pair(s,v[i].sc));
		if(e != v[i].sc)st.insert(make_pair(v[i].sc,e));
	}
	cout<<ans;
}

