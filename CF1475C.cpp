#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	map<int,int> mp[3];
	ll n,m,k;
	cin>>n>>m>>k;
	ll ans = 0;
	pll arr[k];
	for(auto &i:arr){
		cin>>i.fs;
		i.fs--;
	}
	for(auto &i:arr){
		cin>>i.sc;
		i.sc--;
	}
	ll c = 0;
	for(auto &i:arr){
		ans += c-mp[0][i.fs]-mp[1][i.sc]+mp[2][i.fs*m+i.sc];
		mp[0][i.fs]++;
		mp[1][i.sc]++;
		mp[2][i.fs*m+i.sc]++;
		c++;
	}
	cout<<ans<<'\n';
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
