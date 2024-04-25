#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,s,k;
	cin>>n>>s>>k;
	set<ll> st;
	while(k--){
		ll tmp;
		cin>>tmp;
		st.insert(tmp);
	}
	ll ans = 1e18;
	ll h = s,l = s;
	for(;h<=n&&st.find(h) != st.end();h++);
	for(;l>0&&st.find(l) != st.end();l--);
	if(h<=n)ans = min(ans,h-s);
	if(l>0)ans = min(ans,s-l);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
