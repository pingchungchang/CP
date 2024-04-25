#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin>>n;
	vector<pair<ll,ll>> v(n);
	for(ll i = 0;i<n;i++){
		cin>>v[i].second;
	}
	for(ll j = 0;j<n;j++){
		cin>>v[j].first;
		v[j].first = v[j].second-v[j].first+1;
	}
	sort(v.begin(),v.end());
	v.push_back(make_pair(LONG_LONG_MAX,LONG_LONG_MAX));
	ll ans = 0;
	ll e = -1;
	ll s = -1;
//	for(ll i = 0;i<v.size();i++)cout<<v[i].first<<' '<<v[i].second<<',';
	for(ll i = 0;i<=n;i++){
//		cout<<i<<' '<<s<<' '<<e<<'\n'<<endl;
		if(v[i].first>e){
			if(s != -1&&e != -1)ans += (e-s+1)*(e-s+2)/2;
			s = v[i].first;
		}
		e = max((ll)v[i].second,e);
	}
	cout<<ans<<'\n';
	
}
/*
1
3
1 2 3
1 1 3
*/
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
