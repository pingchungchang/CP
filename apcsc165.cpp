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
int main(){
	io
	ll n,m;
	cin>>n>>m;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		pq.push(k);
	}
	ll ans = 0;
	for(ll i = 0;i<m;i++){
		ans += pq.top();
		pq.pop();
	}
	cout<<ans;
}

