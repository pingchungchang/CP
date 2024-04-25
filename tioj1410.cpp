#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
ll n;
const ll mxn = 1e6+10;
vector<ll> all;
ll cnt[mxn*2];
pll req[mxn];
void solve(){
	fill(cnt,cnt+mxn*2,0LL);
	all.clear();
	for(int i = 0;i<n;i++){
		cin>>req[i].fs>>req[i].sc;
		all.push_back(req[i].fs);
		all.push_back(req[i].sc+1);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	for(int i = 0;i<n;i++){
		cnt[lower_bound(_all(all),req[i].fs)-all.begin()]++;
		cnt[lower_bound(_all(all),req[i].sc+1)-all.begin()]--;
	}
	ll ans = 0;
	ll s = 0;
	for(auto &i:cnt){
		s+=i;
		ans = max(ans,s);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	while(cin>>n)solve();
}

