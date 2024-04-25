#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	map<ll,vector<ll>> mp;
	for(int i = 1;i<=n;i++){
		ll tmp;
		cin>>tmp;
		ll rest = tmp%k;
		if(!rest)rest = k;
		mp[rest].push_back(i);
	}
	for(auto it = mp.rbegin();it != mp.rend();it++){
		for(auto &i:it->sc)cout<<i<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
