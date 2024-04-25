#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

int main(){
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	ll n;
	cin>>n;
	for(ll i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		pq.push(make_pair(b,-a));
	}
	ll fin;
	cin>>fin;
	ll t = 0;
	set<ll> st;
	while(t < fin&& !pq.empty()){
		st.insert(-pq.top().second);
		pq.pop();
		t++;
		while(!pq.empty()&&pq.top().first<=t){
			ll val = -pq.top().second;
			if(val>*st.begin()){
				st.erase(st.begin());
				st.insert(val);
			}
			pq.pop();
		}
	}
	while(!pq.empty()){
		ll val = -pq.top().second;
		if(val>*st.begin()){
			st.erase(st.begin());
			st.insert(val);
		}
		pq.pop();
	}
	ll ans = 0;
	for(auto it:st)ans += it;
	cout<<ans-(fin-t);
	
}
