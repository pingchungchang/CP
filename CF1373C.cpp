#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	ll n = s.size();
	ll pref[n];
	pref[0] = (s[0] == '+'?1:-1);
	for(int i = 1;i<n;i++)pref[i] = pref[i-1]+(s[i] == '+'?1:-1);
	ll ans = n;
	vector<pll> v = {make_pair(0,0)};
	for(int i = 0;i<n;i++){
		if(pref[i]<v.back().sc)v.push_back({i+1,pref[i]});
	}
	for(int i = 1;i<v.size();i++){
		ans += v[i].fs;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
