#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define int ll
#define _all(T) T.begin(),T.end()
main(){
	io
	ll n,m,k,d;
	cin>>n>>m>>k>>d;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	set<ll> st;
	for(int i = 0;i<n;i++){
		ll t;
		cin>>t;
		pq.push(t);
	}
	for(int i = 0;i<d;i++){
		ll kk;
		cin>>kk;
		st.insert(kk);
	}
	ll ans = 0;
	for(ll i = m;i>=1&&!pq.empty()&&k>0;i--){
		if(st.find(i) == st.end()){
			k--;
			ans += i;
			ans += pq.top();
			pq.pop();
		}
	}
	cout<<ans;
	
}

