#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	ll arr[n];
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(auto &i:arr){
		cin>>i;
		i %= a+b;
		if(i == 0)i = a+b;
		pq.push((i-1)/a);
	}
	ll ans = 0;
	while(!pq.empty()&&k>=pq.top()){
		k -= pq.top();
		pq.pop();
		ans++;
	}
	cout<<ans;
}
