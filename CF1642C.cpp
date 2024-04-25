#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	multiset<ll> st;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	ll n,m;
	cin>>n>>m;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		pq.push(k);
		st.insert(k);
	}
	ll ans = 0;
	while(!pq.empty()){
		ll now = pq.top();
		pq.pop();
		if(st.find(now) == st.end())continue;
		if(st.find(now*m) != st.end())st.erase(st.find(now*m));
		else ans++;
		st.erase(st.find(now));
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;++i)solve();
}
