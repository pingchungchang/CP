#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin>>n;
	ll ans = 0;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	ll times = 1;
	for(int i =0;i<n;i++){
		ll k;
		cin>>k;
		while((k&1) == 0){
			k>>=1;
			times<<=1;
		}
		pq.push(k);
	}
	ans += pq.top()*times;
	pq.pop();
	while(!pq.empty()){
		ans += pq.top();
		pq.pop();
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		solve();
	}
}
