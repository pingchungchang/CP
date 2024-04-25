#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
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
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(ll i = 0;i<m;i++)pq.push(0);
	while(n--){
		ll k;
		cin>>k;
		ll tmp = pq.top();pq.pop();
		pq.push(tmp+k);
	}
	ll ans = 0;
	while(!pq.empty()){
		ans = max(ans,pq.top());
		pq.pop();
	}
	cout<<ans;
}

