#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll ans = 0;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		pq.push(k);
	}
	while(pq.size()>1){
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();
		ans += a;
		ans += b;
		pq.push(a+b);
	}
	cout<<ans;
}
