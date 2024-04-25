#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn = 1e5+10;
map<ll,ll> mp[mxn];
map<ll,pll> range;
set<ll> st;
int n;
pll choose[mxn];

void solve(){
	range.clear();
	st.clear();
	for(int i = 0;i<=n;i++){
		choose[i] = {0,0};
		mp[i].clear();
	}
	cin>>n;
	ll L = 0,R = 0;
	for(int i = 0;i<n;i++){
		int c;
		cin>>c>>choose[i].fs>>choose[i].sc;
		ll sum = 0;
		for(int j = 0;j<c;j++){
			int k;
			cin>>k;
			st.insert(k);
			mp[i][k] = 0;
		}
		for(auto &j:mp[i]){
			cin>>j.sc;
			sum += j.sc;
		}
		for(auto &j:mp[i]){
			ll rest = sum-j.sc;
			range[j.fs].fs += max(0ll,choose[i].fs-rest);
			range[j.fs].sc += max(0ll,choose[i].sc-rest);
		}
		L += choose[i].fs,R += choose[i].sc;
	}
	/*
	for(auto &i:range){
		cout<<i.fs<<" "<<i.sc.fs<<' '<<i.sc.sc<<':';
	}
	cout<<L<<"<"<<R<<'\n';

   */
	ll ans = 4e18;
	for(ll i = L;i<=R;i++){
		if(st.find(i) == st.end()){
			cout<<"0\n";
			return;
		}
		ll tans = 0;
		auto tmp = range[i];
		ll E = R-(tmp.sc-tmp.fs);
		tans = tmp.fs+max(0ll,i-E);
		ans = min(ans,tans);
	}
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
