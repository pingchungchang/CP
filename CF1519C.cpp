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
	int n;
	cin>>n;
	vector<vector<ll>> v(n+1);
	vector<pll> p(n);
	for(ll i = 0;i<n;i++)cin>>p[i].fs;
	for(ll i = 0;i<n;i++){
		cin>>p[i].sc;
		v[p[i].fs].push_back(p[i].sc);
	}
	vector<ll> ans(n+1,0LL);
	for(auto &tmp:v){
		sort(tmp.rbegin(),tmp.rend());
		for(ll i = 1;i<tmp.size();i++){
			tmp[i] += tmp[i-1];
		}
		for(ll i = 1;i<=tmp.size();i++){
			ll pos = tmp.size()/i*i-1;
			ans[i]+=tmp[pos];
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

