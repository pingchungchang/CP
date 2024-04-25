#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

inline ll sq(ll k){
	ll l = 0,r = 2e9;
	while(l != r){
		ll mid = (l+r)>>1;
		if(mid*mid>=k)r = mid;
		else l = mid+1;
	}
	return l;
}

void solve(){
	ll n;
	cin>>n;
	map<ll,ll> mp;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		mp[k]++;
	}
	int q;
	cin>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll tmp = sq(x*x-y*4);
		if(tmp*tmp != x*x-y*4){
			cout<<"0 ";
			continue;
		}
		ll ta = x+tmp;
		if(abs(ta) % 2 != 0){
			cout<<"0 ";
			continue;
		}
		ta >>=1;
		if(ta == x-ta)cout<<mp[ta]*(mp[ta]-1)/2<<' ';
		else cout<<mp[ta]*mp[x-ta]<<' ';
	}
	cout<<'\n';
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
