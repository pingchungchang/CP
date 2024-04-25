#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	ll n,k,x;
	cin>>n>>k>>x;
	vector<ll> v(n);
	for(ll i = 0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	priority_queue<ll,vector<ll> ,greater<ll>> pq;
	for(ll i = 1;i<n;i++){
		pq.push((v[i]-v[i-1]==0?0LL:(v[i]-v[i-1]-1)/x));
	}
	while(!pq.empty()&&k>=pq.top()){
//		cout<<k<<' ';
		k -= pq.top();
		pq.pop();
	}
	cout<<pq.size()+1;
	return;
}
int main(){
	io
	int t;
	t = 1;
	while(t--)solve();
}

