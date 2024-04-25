#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 1e9+10;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	vector<pll> v;
	for(auto &i:arr)if(v.empty()||v.back().fs != i)v.push_back({i,1});else v.back().sc++;
	v.push_back({0,0});
	v.push_back({inf,0});
	sort(v.begin(),v.end());
	ll pref[v.size()];
	ll cnt[v.size()];
	pref[0] = cnt[0] = 0;
	for(int i = 1;i<v.size();i++){
		pref[i] = pref[i-1]+v[i].fs*v[i].sc;
		cnt[i] = cnt[i-1]+v[i].sc;
	}
	n = v.size()-1;
	ll ans = inf*inf;
	for(int i = 1;i<v.size()-1;i++){
		ll ta = cnt[i-1]*v[i-1].fs-pref[i-1],da = v[i].fs-v[i-1].fs,ca = cnt[i-1];
		ll tb = pref[n]-pref[i]-(cnt[n]-cnt[i])*v[i+1].fs,db = v[i+1].fs-v[i].fs,cb = cnt[n]-cnt[i];
		ll cc = m-v[i].sc;
		if(cc<=0){
			ans = 0;
			break;
		}
		if(cc<=ca)ans = min(ans,ta+(da-1)*ca+cc);
		if(cc<=cb)ans = min(ans,tb+(db-1)*cb+cc);
		if(da>db){
			swap(da,db);
			swap(ta,tb);
			swap(ca,cb);
		}
		ans = min(ans,ta+(da-1)*ca+tb+(db-1)*cb+cc);
		//cout<<i<<":"<<v[i].fs<<' '<<v[i].sc<<' '<<tans<<'\n';
	}
	cout<<ans;
}
