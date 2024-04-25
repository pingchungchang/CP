#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll> v[3];
	pll arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr){
		cin>>i.sc;
		v[i.sc].push_back(i.fs);
	}
	for(auto &i:v)sort(i.rbegin(),i.rend());
	v[1].insert(v[1].begin(),0);
	ll pt = 0;
	ll ans = 5e18;
	ll sum = 0;
	for(auto &i:v[1])sum += i;
	for(int i = v[1].size()-1;i>=0;i--){
		while(pt<v[2].size()&&sum<m){
			sum += v[2][pt];
			pt++;
		}
		if(sum<m)break;
		ans = min(ans,pt*2+i);
		sum -= v[1][i];
	}
	if(ans>n*2)cout<<"-1\n";
	else cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
