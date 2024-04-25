#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll n,k;
	cin>>n>>k;
	ll arr[n],c[n];
	ll val;
	for(ll i = 0;i<n;i++)cin>>arr[i];
	cin>>val;
	for(ll i = 0;i<n;i++)cin>>c[i];
	ll ans = 0;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(ll i = 0;i<n;i++){
		pq.push(c[i]);
		while(!pq.empty()&&k<arr[i]){
			ans += pq.top();
			pq.pop();
			k += val;
		}
		if(k<arr[i]){
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
}

