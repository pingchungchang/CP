#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll> fac;
vector<pll> all;

ll cnt(ll now){
	if(now<0)return INT_MAX;
	ll returns = 0;
	while(now != 0){
		if((now&1))returns++;
		now>>=1;
	}
	return returns;
}
void solve(){
	ll n;
	cin>>n;
	ll ans = INT_MAX;
	for(auto i:all){
		ans = min(ans,i.sc+cnt((n-i.fs)));
//		if(ans == 3){
//			cout<<i.fs<<' '<<cnt(n-i.fs)<<endl;
//			return;
//		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	fac = {1LL};
	for(ll i = 1;i*fac.back()<=1e12;i++){
		fac.push_back(fac.back()*i);
	}
	all = {{0,0}};
	for(auto i:fac){
		ll tmp = all.size();
		for(ll j = 0;j<tmp;j++){
			all.push_back(make_pair(all[j].fs+i,all[j].sc+1));
		}
		all.push_back(make_pair(i,1LL));
	}
	sort(all.begin(),all.end());
//	all.erase(unique(all.begin(),all.end()),all.end());
//	for(auto i:all)cout<<i.fs<<' ';return 0;
	ll t;
	cin>>t;
	while(t--)solve();
}

