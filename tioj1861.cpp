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

int n;
void solve(){
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		pq.push(k);
	}
	ll ans = 0;
	while(pq.size()>1){
		ll tmp = pq.top();pq.pop();
		ll b = pq.top();
		pq.pop();
		ans += tmp+b;
		pq.push(tmp+b);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	while(cin>>n){
		if(!n)return 0;
		solve();
	}
}

