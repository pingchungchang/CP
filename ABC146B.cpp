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
ll n,m,k;
const int mxn = 2e5+10;
ll arr[mxn];
ll buff[mxn];
int main(){
	io
	cin>>n>>m>>k;
	ll ans = 0;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		pq.push(k);
	}
	for(ll i = 30;i>=0;i--){
		ll tar = (1LL<<i);
		ll use = 0;
		int p = 0;
		for(int j = 0;j<k;j++){
			auto now = pq.top();pq.pop();
			buff[p++] = now;
			if(now&(1LL<<i))continue;
			use += (1LL<<i)-now;
		}
		if(use<=m){
			m -= use;
			ans |= (1LL<<i);
			for(int j = 0;j<p;j++){
				if(buf[j]&(1LL<<i))continue;
				buf[j] = (1LL<<i);
			}
			while(!pq.empty()){
				if(pq.top()&(1LL<<i))
			}
		}
	}
}

