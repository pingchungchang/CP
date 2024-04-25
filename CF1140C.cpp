#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mkp make_pair
int main(){
	ll n,k;
	cin>>n>>k;
	priority_queue<pll,vector<pll>,less<pll>> pq;
	for(ll i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		pq.push(mkp(a,b));
	}
	ll t = 0;
	priority_queue<pll,vector<pll>,greater<pll>> now;
	for(ll i = 0;i<k&&!pq.empty();i++){
		t += pq.top().fs;
		now.push(mkp(pq.top().sc,pq.top().fs));
		pq.pop();
	}
	ll ans = 0;
	while(!pq.empty()){
		ans = max(ans,t*(now.top().fs));
		t -= now.top().sc;
		now.pop();
		now.push(mkp(pq.top().sc,pq.top().fs));
		t += pq.top().fs;
		pq.pop();
	}
	while(!now.empty()){
		ans = max(ans,now.top().fs*t);
		t -= now.top().sc;
		now.pop();
	}
	cout<<ans;
	
}

