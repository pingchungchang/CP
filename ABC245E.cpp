#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	io
	ll n,m;
	cin>>n>>m;
	priority_queue<pii,vector<pii>,less<pii>> pq;
	vector<pii> v(n);
	for(ll i = 0;i<n;i++){
		cin>>v[i].fs;
	}
	for(ll i = 0;i<n;i++){
		cin>>v[i].sc;
	}
	vector<pii> vv(m);
	for(ll i = 0;i<m;i++)cin>>vv[i].fs;
	for(ll i = 0;i<m;i++)cin>>vv[i].sc;
	for(ll i = 0;i<m;i++)pq.push(vv[i]);
	sort(v.begin(),v.end());
	multiset<ll> st;
	st.insert(INT_MAX);
	for(ll i = n-1;i>=0;i--){
		while(!pq.empty()&&pq.top().fs>=v[i].fs){
			st.insert(pq.top().sc);
			pq.pop();
		}
		auto it = st.lower_bound(v[i].sc);
		if(*it == INT_MAX){
			cout<<"No";
			return 0;
		}
		st.erase(it);
	}
	cout<<"Yes";
}

