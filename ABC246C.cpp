#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll n,k,x;
	cin>>n>>k>>x;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	for(int i = 0;i<n;i++){
		ll j;
		cin>>j;
		pq.push(j-min(j/x,k)*x);
		k -= min(j/x,k);
	}
	ll ans= 0;
	while(!pq.empty()){
		if(k != 0){
			k--;
			pq.pop();
			continue;
		}
		ans += pq.top();
		pq.pop();
	}
	cout<<ans;
}

