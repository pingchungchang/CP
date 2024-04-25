#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define int ll


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector<pll> v;
	int n;
	cin>>n;
	int pre;
	cin>>pre;
	for(int i = 1;i<n;i+=2){
		cin>>pre;
		int tmp;
		cin>>tmp;
		v.push_back({pre,tmp});
	}
	v.push_back({-2,-2});
	v.push_back({-1,-1});
	v.push_back({INT_MAX,INT_MAX});
	sort(v.begin(),v.end());
	ll pref[v.size()];
	memset(pref,0,sizeof(pref));
	for(int i = 1;i<v.size();i++){
		pref[i] = pref[i-1]+v[i].sc-v[i].fs;
	}
	int q;
	cin>>q;
	while(q--){
		ll l,r;
		cin>>l>>r;
		auto lit = --upper_bound(v.begin(),v.end(),make_pair(l,-2LL));
		auto rit = --upper_bound(v.begin(),v.end(),make_pair(r,1LL*INT_MAX));
		ll ans = max(0LL,pref[rit-v.begin()]-pref[lit-v.begin()]);
		ans += max(0LL,lit->sc-max(l,lit->fs));
		ans -= max(0LL,rit->sc-r);
		cout<<ans<<'\n';
	}
	return 0;
}
