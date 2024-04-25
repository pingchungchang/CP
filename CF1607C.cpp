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
void solve(){
	ll n;
	cin>>n;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i  =0;i<n;i++){
		ll k;
		cin>>k;
		pq.push(k);
	}
	ll shift = 0;
	ll ans = pq.top();
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		now -= shift;
		ans = max(ans,now);
		shift += now;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

