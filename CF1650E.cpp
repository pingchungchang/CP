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

ll n,d;
vector<ll> v;
void solve(){
	cin>>n>>d;
	v = vector<ll>(n+1,0);
	for(int i = 1;i<=n;i++)cin>>v[i];
	multiset<ll> st;
	for(int i = 1;i<=n;i++)st.insert(v[i]-v[i-1]-1);
	ll last = d-v.back()-1;
	ll ans = 0;
	for(int i = 1;i<n;i++){
		ll l = v[i]-v[i-1]-1;
		ll r= v[i+1]-v[i]-1;
		st.erase(st.find(l));st.erase(st.find(r));
		st.insert(l+r+1);
		ans = max(ans,min((*st.rbegin()-1)/2,*st.begin()));
		ans = max(ans,min(*st.begin(),last));
		st.insert(l);st.insert(r);
		st.erase(st.find(l+r+1));
//		cout<<i<<endl;
	}
	st.erase(st.find(v[n]-v[n-1]-1));
	ans = max(ans,min(d-v[n-1]-1,*st.begin()));
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

