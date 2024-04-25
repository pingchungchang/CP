#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n,k;
	cin>>n>>k;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	for(int i = 0;i<n;i++){
		ll x;
		cin>>x;
		pq.push(x);
	}
	ll ans = pq.top();
	ll sm = pq.top();
	pq.pop();
	while(!pq.empty()&&k--){
		ans += pq.top();
		sm = min(sm,1LL*0);
		pq.pop();
	}
	while(!pq.empty()){
		sm = min(sm,pq.top());
		pq.pop();
	}
	cout<<ans-sm<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
